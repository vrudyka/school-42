#include "Lexer.hpp"

Lexer::Lexer()
{
	_operators.insert("push");
	_operators.insert("pop");
	_operators.insert("dump");
	_operators.insert("assert");
	_operators.insert("add");
	_operators.insert("sub");
	_operators.insert("mul");
	_operators.insert("div");
	_operators.insert("mod");
	_operators.insert("print");
	_operators.insert("exit");

	_values.insert("int8");
	_values.insert("int16");
	_values.insert("int32");
	_values.insert("float");
	_values.insert("double");
}

Lexer::~Lexer() {}

std::vector<std::pair<eToken, std::string> > Lexer::tokenize(std::string const &str)
{
	std::vector<std::pair<eToken, std::string> > tokens;
	if (!str.compare(";;")) // end of exec
	{
		tokens.push_back(std::make_pair(Operator, ";;"));
		return tokens;
	}

	std::stringstream ss(str);
	std::string word;
	while (ss >> word)
	{
		if (word.find(";") != std::string::npos) // comment
			break;

		if (_operators.find(word) != _operators.end())
			tokens.push_back(std::make_pair(Operator, word));
		else
		{
			std::size_t firstBracket = word.find('('); // find (
			std::size_t secondBracket = word.find(')'); // find )
			if (firstBracket == std::string::npos ||
				secondBracket == std::string::npos)
				throw Error(VALUE_FORMAT);

			std::string vvalue = word.substr(0, firstBracket); // get before (
			if (_values.find(vvalue) == _values.end())
				throw Error(VALUE_FORMAT);
			tokens.push_back(std::make_pair(Value, vvalue));

			tokens.push_back(std::make_pair(Separator, "(")); // get (

			std::string lliteral = word.substr(firstBracket + 1, secondBracket - firstBracket - 1); // get between ( )
			tokens.push_back(std::make_pair(Literal, lliteral));

			tokens.push_back(std::make_pair(Separator, ")")); // get )

			if (word.size() - secondBracket > 1)
				throw Error(NO_NEWLINE);
		}
	}
	return tokens;
}
