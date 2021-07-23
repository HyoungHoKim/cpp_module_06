#include "DataChange.hpp"

void *serialize(void)
{
	Data data;
	std::string base = "ABCDFEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < 8; i++)
		data.s1.push_back(base[rand() % base.length()]);
	data.n = rand() % 12345;
	for (int i  = 0; i < 8; i++)
		data.s2.push_back(base[rand() % base.length()]);
	
	std::cout << "------ serialize ------" << std::endl;
	std::cout << "str1 : " << data.s1 << std::endl;
	std::cout << "n : " << data.n << std::endl;
	std::cout << "str2 : " << data.s2 << std::endl;

	char *raw = new char[52];
	memcpy(raw, &data.s1, 24);
	memcpy(raw + 24, &data.n, 4);
	memcpy(raw + 28, &data.s2, 24);
	return (reinterpret_cast<void*>(raw));
}

Data *deserialize(void *raw)
{
	Data *ret = new Data;
	
	ret->s1 = std::string(reinterpret_cast<char*>(raw), 24);
	ret->n = *(reinterpret_cast<int*>(raw) + 6);
	ret->s2 = std::string(reinterpret_cast<char*>(raw) + 28, 24);
	return (ret);
}