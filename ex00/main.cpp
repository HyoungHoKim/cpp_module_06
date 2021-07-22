#include "Converter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Too many argument, Please only one parameter!!!" << std::endl;
		return (1);
	}

	Converter converter;

	converter.toChar(argv[1]);
	converter.toInt(argv[1]);
	converter.toFloat(argv[1]);
	converter.toDouble(argv[1]);
}