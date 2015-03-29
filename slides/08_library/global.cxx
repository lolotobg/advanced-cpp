#include <iostream>

#include "library.hxx"

void private_global()
{
	std::cout << "private global function in client application" << std::endl;
}

int main()
{
	library();
	private_global();
	return 0;
}


