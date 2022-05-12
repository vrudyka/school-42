#include "Operand.hpp"
#include "Error.hpp"

Factory::Factory() {}
Factory::~Factory() {}
IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	IOperand const *newOperand;
		switch (type)
		{
		case Int8:
			newOperand = createInt8(value);
			break;
		case Int16:
			newOperand = createInt16(value);
			break;
		case Int32:
			newOperand = createInt32(value);
			break;
		case Float:
			newOperand = createFloat(value);
			break;
		case Double:
			newOperand = createDouble(value);
			break;
		}
	return newOperand;
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	Operand<char> const *newOperand;
	int n;
	try
	{
		n = std::stoi(value);
		if (n < SCHAR_MIN)
			throw Error(VALUE_UNDERFLOW);
		else if (n > SCHAR_MAX)
			throw Error(VALUE_OVERFLOW);
	}
	catch(const std::exception& e)
	{
		if (value.find('-') != std::string::npos)
			throw Error(VALUE_UNDERFLOW);
		else
			throw Error(VALUE_OVERFLOW);
	}
	char c = static_cast<char>(n);
	newOperand = new Operand<char>(this, c, 0, Int8, value);
	return newOperand;
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	Operand<short> const *newOperand;
	int n;
	try
	{
		n = std::stoi(value);
		if (n < SHRT_MIN)
			throw Error(VALUE_UNDERFLOW);
		else if (n > SHRT_MAX)
			throw Error(VALUE_OVERFLOW);
	}
	catch(const std::exception& e)
	{
		if (value.find('-') != std::string::npos)
			throw Error(VALUE_UNDERFLOW);
		else
			throw Error(VALUE_OVERFLOW);
	}
	short s = static_cast<short>(n);
	newOperand = new Operand<short>(this, s, 0, Int16, value);
	return newOperand;
}

IOperand const *Factory::createInt32(std::string const &value) const
{
	Operand<long> const *newOperand;
	long n;
	try
	{
		n = std::stol(value);
		if (n < LONG_MIN)
			throw Error(VALUE_UNDERFLOW);
		else if (n > LONG_MAX)
			throw Error(VALUE_OVERFLOW);
	}
	catch(const std::exception& e)
	{
		if (value.find('-') != std::string::npos)
			throw Error(VALUE_UNDERFLOW);
		else
			throw Error(VALUE_OVERFLOW);
	}
	long l = static_cast<long>(n);
	newOperand = new Operand<long>(this, l, 0, Int32, value);
	return newOperand;
}

IOperand const *Factory::createFloat(std::string const &value) const
{
	Operand<float> const *newOperand;
	float f;
	try
	{
		f = std::stof(value);
	}
	catch(const std::exception& e)
	{
		if (value.find('-') != std::string::npos)
			throw Error(VALUE_UNDERFLOW);
		else
			throw Error(VALUE_OVERFLOW);
	}
	newOperand = new Operand<float>(this, f, 7, Float, value);
	return newOperand;
}

IOperand const *Factory::createDouble(std::string const &value) const
{
	Operand<double> const *newOperand;
	double d;
	try
	{
		d = std::stod(value);
	}
	catch(const std::exception& e)
	{
		if (value.find('-') != std::string::npos)
			throw Error(VALUE_UNDERFLOW);
		else
			throw Error(VALUE_OVERFLOW);
	}
	newOperand = new Operand<double>(this, d, 15, Double, value);
	return newOperand;
}
