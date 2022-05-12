#pragma once
#include "Lexer.hpp"
#include "IOperand.hpp"
#include <vector>

enum eOperation
{
	Push,
	Pop,
	Dump,
	Assert,
	Add,
	Sub,
	Mul,
	Div,
	Mod,
	Print,
	Exit
};

class Parser
{
private:
	std::vector<eToken>		_validTokens;

public:
	Parser();
	~Parser();

	bool validateTokens(std::vector<std::pair<eToken, std::string> >& tokens);
	eOperation getOperation(std::vector<std::pair<eToken, std::string> >& tokens);
	std::pair<eOperandType, std::string> getValue(std::vector<std::pair<eToken, std::string> >& tokens);
};
