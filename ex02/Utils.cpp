#include <iostream>

#include "Utils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int num = rand() % 3;

	if (num == 0)
		return (new A);
	else if (num == 1)
		return (new B);
	else
		return (new C);
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
}

void identify_from_reference(Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A";
	else if (dynamic_cast<B*>(&p))
		std::cout << "B";
	else if (dynamic_cast<C*>(&p))
		std::cout << "C";
}