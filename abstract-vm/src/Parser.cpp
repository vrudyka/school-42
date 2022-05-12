#include "Parser.hpp"

Parser::Parser()
{
	_validTokens.push_back(Operator);
	_validTokens.push_back(Value);
	_validTokens.push_back(Separator);
	_validTokens.push_back(Literal);
	_validTokens.push_back(Separator);
}

Parser::~Parser() {}

bool Parser::validateTokens(std::vector<std::pair<eToken, std::string>>& tokens)
{
	if (tokens.size() > _validTokens.size())
		throw Error(INVALID_TOKENS);

	std::vector<std::pair<eToken, std::string>>::iterator it;
	std::vector<eToken>::iterator kt = _validTokens.begin();
	for (it = tokens.begin(); it != tokens.end(); ++it)
	{
		if (it->first != *kt)
			return false;
		++kt;
	}
	return true;
}

eOperation Parser::getOperation(std::vector<std::pair<eToken, std::string>>& tokens)
{
	std::string operation;
	operation = tokens.begin()->second;
	if (operation == "push") return Push;
	else if (operation == "pop") return Pop;
	else if (operation == "dump") return Dump;
	else if (operation == "assert") return Assert;
	else if (operation == "add") return Add;
	else if (operation == "sub") return Sub;
	else if (operation == "mul") return Mul;
	else if (operation == "div") return Div;
	else if (operation == "mod") return Mod;
	else if (operation == "print") return Print;
	else if (operation == "exit") return Exit;
	return Exit;
}

std::pair<eOperandType, std::string> Parser::getValue(std::vector<std::pair<eToken, std::string>>& tokens)
{
	std::pair<eOperandType, std::string> val;
	std::vector<std::pair<eToken, std::string>>::iterator it;
	for (it = tokens.begin(); it != tokens.end(); ++it)
	{
		if (it->first == Value)
		{
			if (it->second == "int8") val.first = Int8;
			else if (it->second == "int16") val.first = Int16;
			else if (it->second == "int32") val.first = Int32;
			else if (it->second == "float") val.first = Float;
			else if (it->second == "double") val.first = Double;
		}
		else if (it->first == Literal)
		{
			std::string str = it->second;
			auto validLiteral = std::find_if(str.begin(),
											 str.end(),
											 [](char c) { return !std::isdigit(c) &&
																 c != '-' &&
																 c != '+' &&
																 c != '.'; });
			if (validLiteral != str.end())
				throw Error(VALUE_FORMAT);
			else
				val.second = it->second;
		}
	}
	return val;
}
