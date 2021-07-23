#include <iostream>
#include "DataChange.hpp"

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 2; i++)
	{
		void *raw = serialize();
		Data *ret = deserialize(raw);

		std::cout << "------ deserialize ------" << std::endl;
		std::cout << "str1 : " << ret->s1 << std::endl;
		std::cout << "n : " << ret->n << std::endl;
		std::cout << "str2 : " << ret->s2 << std::endl;

		delete reinterpret_cast<char*>(raw);
		delete ret;
	}

	system("leaks datachange");

	return (0);
}