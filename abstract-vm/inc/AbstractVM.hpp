#include "Operand.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include <fstream>
#include <queue>

class AbstractVM
{
private:
	Lexer		_lexer;
	Parser		_parser;
	Factory		_factory;
	bool		_readOver;
	bool		_execOver;
	bool		_readFromFile;

	std::queue<eOperation>								_operations;
	std::queue<std::pair<eOperandType, std::string> >	_values;
	std::vector<const IOperand*>						_literals;
	std::stringstream									_ss;

	AbstractVM();

public:
	AbstractVM(int ac, char **av);
	~AbstractVM();

	void update();
	void processFile(std::ifstream &fs);
	void processLine(std::string const &str);

	void execute();

	std::pair<const IOperand*, const IOperand*> popTwo();
	void cleanLiterals();

	void opush(std::pair<eOperandType, std::string> const &value);
	void opop();
	void odump();
	void oassert(std::pair<eOperandType, std::string> const &value);
	void oadd();
	void osub();
	void omul();
	void odiv();
	void omod();
	void oprint();

	void output();
};
