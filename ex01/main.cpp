#include <iostream>
#include "DataChange.hpp"

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 2; i++)
	{
		Data data;
		std::string base = "ABCDFEFGHIJKLMNOPQRSTUVWXYZ";

		for (int i = 0; i < 8; i++)
			data.s1.push_back(base[rand() % base.length()]);
		data.n = rand() % 12345;
		for (int i  = 0; i < 8; i++)
			data.s2.push_back(base[rand() % base.length()]);
		std::cout << "------ Data Structure Info ------" << std::endl;
		std::cout << "str1 : " << data.s1 << std::endl;
		std::cout << "n : " << data.n << std::endl;
		std::cout << "str2 : " << data.s2 << std::endl;
		std::cout << "Structure address : " << &data << std::endl;

		uintptr_t raw = serialize(&data);
		std::cout << "------ serialize ------" << std::endl;
		std::cout << "Serialize address : " << raw << std::endl;

		Data *ret = deserialize(raw);
		std::cout << "------ deserialize ------" << std::endl;
		std::cout << "str1 : " << ret->s1 << std::endl;
		std::cout << "n : " << ret->n << std::endl;
		std::cout << "str2 : " << ret->s2 << std::endl;
		std::cout << "Deserialize address : " << &data << std::endl;
	}

	return (0);
}