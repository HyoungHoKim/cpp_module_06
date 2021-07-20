#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <iostream>
# include <cmath>
# include <limits>

class Converter
{
private:
	double value;
public:
	Converter();
	~Converter();
	Converter(const Converter &_cv);
	Converter &operator=(const Converter &_cv);

	double getValue(void) const;
	void setValue(double _value);
	void setValue(char *str);

	char toChar();
	int toInt();
	float toFloat();
	double toDouble();

	class ImpossibleException : public std::exception {
		virtual const char *what() const throw();
	};
	class NonDisplayableException : public std::exception {
		virtual const char *what() const throw();
	};
};

#endif 