#include "Convertor.hpp"

Convertor::Convertor(std::string value): _value(value)
{
}

Convertor::~Convertor()
{
}

int Convertor::toInt() const
{
	try
	{
		return std::stoi(this->_value);
	}
	catch(const std::exception& e)
	{
		throw ImpossibleException();
	}
}

char Convertor::toChar() const
{
	char res;

	try
	{
		res = static_cast<char> (std::stoi(this->_value));
	}
	catch(const std::exception& e)
	{
		throw ImpossibleException();
	}
	if (res < 32 || res > 126)
		throw NonDisplayableException();

	return res;
}

float Convertor::toFloat() const
{
	try
	{
		return std::stof(this->_value);
	}
	catch(const std::exception& e)
	{
		throw ImpossibleException();
	}
}

double Convertor::toDouble() const
{
	try
	{
		return static_cast<double> (std::stof(this->_value));
	}
	catch(const std::exception& e)
	{
		throw ImpossibleException();
	}
}

const char *Convertor::ImpossibleException::what() const throw()
{
	return "Impossible";
}

const char *Convertor::NonDisplayableException::what() const throw()
{
	return "Non displayable";
}

std::ostream &operator<<(std::ostream &os, Convertor const &conv)
{
	try
	{
		os << "Char: " << conv.toChar() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		os << "Int: " << conv.toInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		os << "Float: " << conv.toFloat();
		if (conv.toFloat() - static_cast<int>(conv.toFloat()) == 0)
			os << ".0";
		os << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		os << "Double: " << conv.toDouble();
		if (conv.toDouble() - static_cast<int>(conv.toDouble()) == 0)
			os << ".0";
		os << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return os;
}
