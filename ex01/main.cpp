#include "iter.hpp"
#include <iostream>
/*
#include <vector>

int main (void)
{
	std::vector<int> v1 ;
	std::vector::iter it;
	std::vector::iter it_end = v1.end();

	for (size_t i= 1; i <= 10 ; i++)
	{
		v1.push_back(i);
	}
	for (it = vi.begin(); it <= it_end ; ++it)
	{
		std::cout << it << std::endl ;
	}
	return 0;

}

*/
template<typename T>  // Function template
T const & max (T const & a, T const & b)
{
	return (a > b ? a : b);
}

int foo ( int x ) {
	std::cout << "Long computing time" << std::endl;
	return x;
}

int main ( void )
{
	int a = 12 ;
	int b = 24 ;
	std::cout << "Max of " << a << " and " << b << " is " ;
	std::cout << max<int>(a, b) << std::endl;   //Explicit instantiaton ;
	std::cout << "Max of " << a << " and " << b << " is " ;
	std::cout << max(a, b) << std::endl;   //Implicit instantiaton. The compiler infers from the arguments

	float c = 12.5 ;
	float d = 12.7 ;
	std::cout << "Max of " << c << " and " << d << " is " ;
	std::cout << max<float>(c, d) << std::endl;   //Explicit instantiaton ;
	std::cout << "Max of " << c << " and " << d << " is " ;
	std::cout << max(c, d) << std::endl;   //Implicit instantiaton. The compiler infers from the arguments

	char e = 'a' ;
	char f = 'b' ;
	std::cout << "Max of " << e << " and " << f << " is " ;
	std::cout << max<char>(e, f) << std::endl;   //Explicit instantiaton ;
	std::cout << "Max of " << e << " and " << f << " is " ;
	std::cout << max(e, f) << std::endl;   //Implicit instantiaton. The compiler infers from the arguments


	int ret = max<int>( foo(a), foo(b) );
	std::cout << "Max of " << a << " and " << b << " is " ;
	std::cout << ret << std::endl;   //Explicit instantiaton ;
return 0 ;
}
