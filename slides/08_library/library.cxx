#include <iostream>
#include <cstdlib>

#include "library.hxx"

void private_global3();


void library()
{
	std::cout << "function in library" << std::endl;
	private_global3();
}

