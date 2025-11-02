#include <algorithm>
#include <vector>
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

int main ( void )
{
	std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);

	const std::vector<int> c(v);

	//for_each(v.begin(), v.end(), showInt);
	std::cout << "Original vector " << std::endl ; 
	iter(v, v.size(), showInt<int>);
	iter(v, v.size(), square<int>);
	std::cout << "Squared  vector " << std::endl ; 
	iter(v, v.size(), showInt<int>);
	//for_each(v.begin(), v.end(), showInt<int>);
/*	iter(c, c.size(), showInt<int>);
	iter(c, c.size(), square<int>);
	for_each(c.begin(), c.end(), showInt<const int>);
*/
	std::cout << "Original const vector " << std::endl ; 
  	iter(c, c.size(), showInt<int>);
//	iter(c, c.size(), square<int>);
	std::cout << "Squared  const vector " << std::endl ; 
	iter(c, c.size(), showInt<int>);
return 0 ;
}
