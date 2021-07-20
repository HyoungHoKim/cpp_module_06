#include "Converter.hpp"

Converter::Converter()
: value(0)
{ }

Converter::~Converter()
{ }

Converter::Converter(const Converter &_cv)
{
	*this = _cv;
}

Converter &Converter::operator=(const Converter &_cv)
{
	if (this == &_cv)
		return (*this);
	this->value = _cv.getValue();
	return (*this);
}

double Converter::getValue(void) const
{
	return (this->value);
}

void Converter::setValue(double _value)
{
	this->value = _value;
}

void Converter::setValue(char *str)
{
	this->value = std::stod(str);
}

char Converter::toChar()
{
	if (std::isinf(this->value) || std::isnan(this->value))
		throw Converter::ImpossibleException();
	char ret = static_cast<int>(this->value);
	if (ret < 32 || ret > 126)
		throw Converter::NonDisplayableException();
	return (ret);
}

int Converter::toInt()
{
	if (std::isinf(this->value) || std::isnan(this->value)
		|| this->value > std::numeric_limits<int>::max()
		|| this->value < std::numeric_limits<int>::min())
		throw Converter::ImpossibleException();
	return (static_cast<int>(this->value));
}

float Converter::toFloat()
{
	if (std::isinf(this->value) || std::isnan(this->value))
		return (static_cast<float>(this->value));
	/*if (this->value > std::numeric_limits<float>::max()
		|| this->value < std::numeric_limits<float>::min())
		throw Converter::ImpossibleException();*/
	return (static_cast<float>(this->value));
}
double Converter::toDouble()
{
	return (static_cast<double>(this->value));
}

const char *Converter::ImpossibleException::what() const throw()
{
	return ("impossible");
}
const char *Converter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}
