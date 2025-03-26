#pragma once

#include <typeinfo>
#include <iostream>

// .h file only!

template <class T>
class TemplateExample
{
public:
	TemplateExample()
	{
		T myVar;
		std::cout << "At runtime, 'T' is of type: ";
		std::cout << typeid(myVar).name() 
			<< std::endl << std::endl;
	}
};

