#include "Converter.hpp"

Converter::Converter()
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
	return (*this);
}

void Converter::toChar(char *str)
{
	std::cout << "char : ";
	std::string check(str);
	if (check == "-inff" || check == "inff" || check == "nanf"
		|| check == "-inf" || check == "inf" || check == "nan")
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	double d;
	try
	{
		d = std::stod(str);
	}
	catch(std::invalid_argument &)
	{ 
    	std::cout << "Invalid input" << std::endl;
		return ;
	}
	catch(std::out_of_range &)
	{
    	std::cout << "impossible" << std::endl;
		return ;
	}

	if (d > std::numeric_limits<char>::max()
		|| d < std::numeric_limits<char>::min())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (d < 32 || d > 126)
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	char c = static_cast<int>(d);
	std::cout << c << std::endl;
}

void Converter::toInt(char *str)
{
	std::cout << "int : ";
	std::string check(str);
	if (check == "-inff" || check == "inff" || check == "nanf"
		|| check == "-inf" || check == "inf" || check == "nan")
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	double d;
	try
	{
		d = std::stod(str);
	}
	catch(std::invalid_argument &)
	{ 
    	std::cout << "Invalid input" << std::endl;
		return ;
	}
	catch(std::out_of_range &)
	{
    	std::cout << "impossible" << std::endl;
		return ;
	}

	if (d > std::numeric_limits<int>::max()
		|| d < std::numeric_limits<int>::min())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(d) << std::endl;
}

void Converter::toFloat(char *str)
{
	std::cout << "float : ";
	float fv;
	try
	{
		fv = std::stof(str);
	}
	catch(std::invalid_argument &)
	{ 
    	std::cout << "Invalid input" << std::endl;
		return ;
	}
	catch(std::out_of_range &)
	{
    	std::cout << "impossible" << std::endl;
		return ;
	}
	float f = static_cast<float>(fv);
	if (f - static_cast<int>(f) != 0)
		std::cout << f << "f" << std::endl;
	else
		std::cout << f << ".0f" << std::endl;
}
void Converter::toDouble(char *str)
{
	std::cout << "double : ";
	double dv;
	try
	{
		dv = std::stod(str);
	}
	catch(std::invalid_argument &)
	{ 
    	std::cout << "Invalid input" << std::endl;
		return ;
	}
	catch(std::out_of_range &)
	{
    	std::cout << "impossible" << std::endl;
		return ;
	}
	double d =  static_cast<double>(dv);
	if (d - static_cast<int>(d) != 0)
		std::cout << d << std::endl;
	else
		std::cout << d << ".0" << std::endl;
}
