#ifndef DATACHANGE_HPP
# define DATACHANGE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

void *serialize(void);
Data *deserialize(void *raw);

#endif 