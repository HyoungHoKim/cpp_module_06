#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Utils.hpp"

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		Base *o = generate();
		std::cout << "Test " << i << ": ";
		identify_from_pointer(o);
		std::cout << ", ";
		identify_from_reference(*o);
		std::cout << std::endl;
		delete o;
	}

	return (0);
}