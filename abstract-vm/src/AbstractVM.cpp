#include "AbstractVM.hpp"

AbstractVM::AbstractVM() {}
AbstractVM::AbstractVM(int ac, char **av) : _readOver(false), _execOver(false)
{
	std::string str;

	if (ac < 2)
		update();
	else if (ac == 2)
	{
		std::ifstream fs(av[1], std::fstream::out | std::fstream::in);
		if (!fs)
			throw Error(FILE_INVALID);
		processFile(fs);
	}
	else
		throw Error(AC_INVALID);
	output();
}

AbstractVM::~AbstractVM()
{
	cleanLiterals();
}

void AbstractVM::opush(std::pair<eOperandType, std::string> const &value)
{
	IOperand const *newLiteral;
	newLiteral = _factory.createOperand(value.first, value.second);
	_literals.push_back(newLiteral);
}

void AbstractVM::opop()
{
	if (_literals.empty())
		throw Error(POP_EMPTY);
	
	delete _literals.back();
	_literals.pop_back();
}

void AbstractVM::odump()
{
	std::vector<const IOperand *>::reverse_iterator it;
	for (it = _literals.rbegin(); it != _literals.rend(); ++it)
	{
		_ss << (*it)->toString() << std::endl;
	}
}

void AbstractVM::oassert(std::pair<eOperandType, std::string> const &value)
{
	if (value.first != _literals.back()->getType() ||
		value.second != _literals.back()->toString())
		{
			cleanLiterals();
			throw Error(FALSE_ASSERT);
		}
}

std::pair<const IOperand*, const IOperand*> AbstractVM::popTwo()
{
	if (_literals.size() < 2)
	{
		cleanLiterals();
		throw Error(NOT_ENOUGH);
	}

	IOperand const *first = _literals.back();
	_literals.pop_back();

	IOperand const *second = _literals.back();
	_literals.pop_back();
	return std::make_pair(first, second);
}

void AbstractVM::cleanLiterals()
{
	std::vector<const IOperand*>::iterator it;
	for (it = _literals.begin(); it != _literals.end(); ++it)
		delete *it;
}

void AbstractVM::oadd()
{
	std::pair<const IOperand*, const IOperand*> operands;
	operands = popTwo();

	IOperand const *newOperand = *(operands.second) + *(operands.first);

	_literals.push_back(newOperand);

	delete operands.first;
	delete operands.second;
}

void AbstractVM::osub()
{
	std::pair<const IOperand*, const IOperand*> operands;
	operands = popTwo();

	IOperand const *newOperand = *(operands.second) - *(operands.first);

	_literals.push_back(newOperand);

	delete operands.first;
	delete operands.second;
}

void AbstractVM::omul()
{
	std::pair<const IOperand*, const IOperand*> operands;
	operands = popTwo();

	IOperand const *newOperand = *(operands.second) * *(operands.first);

	_literals.push_back(newOperand);

	delete operands.first;
	delete operands.second;
}

void AbstractVM::odiv()
{
	std::pair<const IOperand*, const IOperand*> operands;
	operands = popTwo();
	try
	{
		IOperand const *newOperand = *(operands.second) / *(operands.first);
		_literals.push_back(newOperand);
	}
	catch(const Error& e)
	{
		std::cerr << e.what() << '\n';
		cleanLiterals();
		delete operands.first;
		delete operands.second;
	}
	delete operands.first;
	delete operands.second;
}

void AbstractVM::omod()
{
	std::pair<const IOperand*, const IOperand*> operands;
	operands = popTwo();
	try
	{
		IOperand const *newOperand = *(operands.second) % *(operands.first);
		_literals.push_back(newOperand);
	}
	catch(const Error& e)
	{
		std::cerr << e.what() << '\n';
		cleanLiterals();
		delete operands.first;
		delete operands.second;
	}
	delete operands.first;
	delete operands.second;
}

void AbstractVM::oprint()
{
	if (_literals.back()->getType() != Int8)
		throw Error(FALSE_ASSERT);

	int n = std::stoi(_literals.back()->toString());
	char c = static_cast<char>(n);
	_ss << c << std::endl;
}

void AbstractVM::execute()
{
	while (!_operations.empty() && !_execOver)
	{
		eOperation operation = _operations.front();
		switch (operation)
		{
		case Push:
		
			opush(_values.front());
			_values.pop();
			break;
		case Pop:
			opop();
			break;
		case Dump:
			odump();
			break;
		case Assert:
			oassert(_values.front());
			_values.pop();
			break;
		case Add:
			oadd();
			break;
		case Sub:
			osub();
			break;
		case Mul:
			omul();
			break;
		case Div:
			odiv();
			break;
		case Mod:
			omod();
			break;
		case Print:
			oprint();
			break;
		case Exit:
			_execOver = true;
			break;
		}
		_operations.pop();
	}
}

void AbstractVM::processLine(std::string const &str)
{
	std::vector<std::pair<eToken, std::string>> tokens = _lexer.tokenize(str);
	if (tokens.empty())
		return;

	if (!_parser.validateTokens(tokens))
		throw Error(INVALID_TOKENS);

	eOperation operation = _parser.getOperation(tokens);
	if (operation == Exit)
	{
		if (str == ";;")
		{
			if (_readFromFile)
				throw Error(UNKNOWN_INSTR);
			else
			{
				_operations.push(operation);
				_readOver = true;
			}	
		}
		else if (str == "exit" && _readFromFile)
		{
			_operations.push(operation);
			_readOver = true;
		}
	}
	else
		_operations.push(operation);

	if (tokens.size() != 1)
	{
		std::pair<eOperandType, std::string> value = _parser.getValue(tokens);
		_values.push(value);
	}
}

void AbstractVM::update()
{
	_readFromFile  = false;

	std::string str;
	while (std::getline(std::cin, str))
	{
		if (str != "")
			processLine(str);
		if (_readOver)
			break;
		execute();
	}
}

void AbstractVM::processFile(std::ifstream &fs)
{
	_readFromFile = true;

	std::string str;
	while (std::getline(fs, str))
	{
		if (str != "")
			processLine(str);
	}

	if (!_readOver)
		throw Error(NO_EXIT);
		
	fs.close();
	execute();
}

void AbstractVM::output()
{
	std::cout << _ss.str();
}