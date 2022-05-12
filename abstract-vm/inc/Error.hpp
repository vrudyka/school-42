#pragma once
#include <iostream>

#define UNKNOWN_INSTR "Instruction is unknown."
#define VALUE_FORMAT "Invalid value format."
#define VALUE_OVERFLOW "Overflow on a value."
#define VALUE_UNDERFLOW "Underflow on a value."
#define NO_NEWLINE "Command must end with a newline."
#define EMPTY_POP "Pop on an empty stack."
#define DIV_ZERO "Division by 0 is prohibited."
#define MODULO_ZERO "Modulo by 0 is prohibited."
#define NO_EXIT "The program doesn’t have an exit instruction."
#define FALSE_ASSERT "Assert instruction is false."
#define NO_VALUES "The stack is composed of less that two values."
#define AC_INVALID "The number of arguements is invalid."
#define FILE_INVALID "File could not be read."
#define INVALID_TOKENS "Tokens are invalid."
#define POP_EMPTY "Pop on an empty stack."
#define NOT_ENOUGH "Not enough values in stack to preform operation."

class Error : std::exception
{
private:
	std::string _message;

	Error();

public:
	Error(char* const str);
	Error(std::string const &str);
	~Error() noexcept;
	const char *what() const throw();
};
