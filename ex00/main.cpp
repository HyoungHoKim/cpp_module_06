#include "Converter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Too many argument, Please only one parameter!!!" << std::endl;
		return (1);
	}

	Converter converter;

	try
	{
		converter.setValue(argv[1]);
	}
	catch(std::invalid_argument &)
	{ 
    	std::cout << "invalid input\n";
	}
	catch(std::out_of_range &)
	{
    	std::cout << "input out of range representable by doubles\n";
	} 

	try
	{
		char c = converter.toChar();
		std::cout << "char : '" << c << "'" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "char : " << e.what() << std::endl;
	}

	try
	{
		std::cout << "int : " << converter.toInt() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		float f = converter.toFloat();
		if (f - static_cast<int>(f) != 0)
			std::cout << "float : " << f << "f" << std::endl;
		else
			std::cout << "float : " << f << ".0f" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "float : " << e.what() << std::endl;
	}

	double d = converter.toDouble();
	if (d - static_cast<int>(d) != 0)
		std::cout << "double : " << d << std::endl;
	else
		std::cout << "double : " << d << ".0" << std::endl;

}