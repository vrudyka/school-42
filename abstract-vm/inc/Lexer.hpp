#pragma once
#include "Error.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <set>

enum eToken
{
	Operator,
	Value,
	Literal,
	Separator
};

class Lexer
{
private:
	std::set<std::string> _operators;
	std::set<std::string> _values;

public:
	Lexer();
	~Lexer();

	std::vector<std::pair<eToken, std::string> > tokenize(std::string const &str);
};
