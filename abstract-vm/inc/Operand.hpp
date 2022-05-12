#pragma once
#include "IOperand.hpp"
#include <sstream>
#include <cmath>

template <class T>
class Operand : public IOperand
{
private:
	const Factory	*_factory;
	T				_value;
	int				_precision;
	eOperandType	_type;
	std::string		_string;

	int getPrecision() const;
	eOperandType getType() const;
	IOperand const *operator+(IOperand const &rhs) const;
	IOperand const *operator-(IOperand const &rhs) const;
	IOperand const *operator*(IOperand const &rhs) const;
	IOperand const *operator/(IOperand const &rhs) const;
	IOperand const *operator%(IOperand const &rhs) const;
	std::string const &toString() const;
	Operand();

public:
	Operand(const Factory *factory, T value, int precision, eOperandType type, std::string str);
	~Operand();
};

template <class T>
Operand<T>::Operand() {}

template <class T>
Operand<T>::Operand(const Factory *factory, T value, int precision, eOperandType type, std::string str) :
	_factory(factory), _value(value), _precision(precision), _type(type), _string(str) {}

template <class T>
Operand<T>::~Operand() {}

template <class T>
int Operand<T>::getPrecision() const { return _precision; }

template <class T>
eOperandType Operand<T>::getType() const { return _type; }

template <class T>
IOperand const *Operand<T>::operator+(IOperand const &rhs) const
{
	std::ostringstream ss;
	eOperandType type = _type > rhs.getType() ? _type : rhs.getType();
	switch (type)
	{
		case Int8:
		case Int16:
		case Int32:
			ss << std::stoi(_string) + std::stoi(rhs.toString());
			break;
		case Float:
			ss << std::stof(_string) + std::stof(rhs.toString());
			break;
		case Double:
			ss << std::stod(_string) + std::stod(rhs.toString());
			break;
	}
	return _factory->createOperand(type, ss.str());
}

template <class T>
IOperand const *Operand<T>::operator-(IOperand const &rhs) const
{
	std::ostringstream ss;
	eOperandType type = _type > rhs.getType() ? _type : rhs.getType();
	switch (type)
	{
		case Int8:
		case Int16:
		case Int32:
			ss << std::stoi(_string) - std::stoi(rhs.toString());
			break;
		case Float:
			ss << std::stof(_string) - std::stof(rhs.toString());
			break;
		case Double:
			ss << std::stod(_string) - std::stod(rhs.toString());
			break;
	}
	return _factory->createOperand(type, ss.str());
}

template <class T>
IOperand const *Operand<T>::operator*(IOperand const &rhs) const
{
	std::ostringstream ss;
	eOperandType type = _type > rhs.getType() ? _type : rhs.getType();
	switch (type)
	{
		case Int8:
		case Int16:
		case Int32:
			ss << std::stoi(_string) * std::stoi(rhs.toString());
			break;
		case Float:
			ss << std::stof(_string) * std::stof(rhs.toString());
			break;
		case Double:
			ss << std::stod(_string) * std::stod(rhs.toString());
			break;
	}
	return _factory->createOperand(type, ss.str());
}

template <class T>
IOperand const *Operand<T>::operator/(IOperand const &rhs) const
{
	if (!std::stod(rhs.toString()))
		throw Error(DIV_ZERO);

	std::ostringstream ss;
	eOperandType type = _type > rhs.getType() ? _type : rhs.getType();
	switch (type)
	{
		case Int8:
		case Int16:
		case Int32:
			ss << std::stoi(_string) / std::stoi(rhs.toString());
			break;
		case Float:
			ss << std::stof(_string) / std::stof(rhs.toString());
			break;
		case Double:
			ss << std::stod(_string) / std::stod(rhs.toString());
			break;
	}
	return _factory->createOperand(type, ss.str());
}

template <class T>
IOperand const *Operand<T>::operator%(IOperand const &rhs) const
{
	if (!std::stod(rhs.toString()))
		throw Error(DIV_ZERO);

	std::ostringstream ss;
	eOperandType type = _type > rhs.getType() ? _type : rhs.getType();
	switch (type)
	{
		case Int8:
		case Int16:
		case Int32:
			ss << std::stoi(_string) % std::stoi(rhs.toString());
			break;
		case Float:
			ss << fmod(std::stof(_string), std::stof(rhs.toString()));
			break;
		case Double:
			ss << fmod(std::stod(_string), std::stod(rhs.toString()));
			break;
	}
	return _factory->createOperand(type, ss.str());
}

template <class T>
std::string const &Operand<T>::toString() const { return _string; }
