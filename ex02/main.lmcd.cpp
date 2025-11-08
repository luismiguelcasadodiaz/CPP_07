#include "Array.tpp"
#include <iostream>

int main( void )
{
	Array<int> a(5);
	try{
	std::cout << a[0] << std::endl;
	std::cout << a[4] << std::endl;
	std::cout << a[5] << std::endl;		
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;

}
