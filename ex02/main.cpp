#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void)
{
	srand(std::time(NULL));

	switch (rand() % 3)
	{
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A val;
		val = dynamic_cast<A&>(p);
		std::cout << "Class A" << std::endl;
	}
	catch (const std::exception& e) {}
	try
	{
		B val;
		val = dynamic_cast<B&>(p);
		std::cout << "Class B" << std::endl;
	}
	catch (const std::exception& e) {}
	try
	{
		C val;
		val = dynamic_cast<C&>(p);
		std::cout << "Class C" << std::endl;
	}
	catch (const std::exception& e) {}
}

int main()
{
	Base *base;
	base = generate();
	identify(base);
	identify(*base);
}
