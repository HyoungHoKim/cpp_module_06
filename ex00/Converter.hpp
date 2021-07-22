#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <iostream>
# include <cmath>
# include <limits>

class Converter
{
public:
	Converter();
	~Converter();
	Converter(const Converter &_cv);
	Converter &operator=(const Converter &_cv);

	void toChar(char *str);
	void toInt(char *str);
	void toFloat(char *str);
	void toDouble(char *str);

	class ImpossibleException : public std::exception {
		virtual const char *what() const throw();
	};
	class NonDisplayableException : public std::exception {
		virtual const char *what() const throw();
	};
};

#endif 