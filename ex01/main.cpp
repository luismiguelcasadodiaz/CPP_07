#include <algorithm>
#include <vector>
#include <list>
#include "iter.hpp"
#include <iostream>

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T const & x )
{
  std::cout << x << std::endl;
  return;
}


int main ( void )
{

{//array pointer
  int tab[] = { 0, 1, 2, 3, 4 };
  const int tabc[] = { 5, 6, 7, 8, 9 };
  Awesome tab2[5];

  const int len = 5;
std::cout << "===== NON-CONST Array ==>" << std::endl;
	iter( tab, len, print<const int> );
	iter( tab, len, square<int> );
	iter( tab, len, print<const int> );
std::cout << "===== CONST Array ==>" << std::endl;
	iter( tabc, len, print<const int> );
	const int * tabc2 = iter( tabc, len, square<int> ) ;
	iter( tabc2, len, print<const int> );

  	iter( tab2, len, print<Awesome> );
}


{//vect container
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



	std::cout << "===== NON-CONST container ==>VECTOR" << std::endl;
	std::cout << "Original vector " << std::endl ; 
	iter(v, v.size(), showInt<int>);
	iter(v, v.size(), square<int>);
	std::cout << "Squared  vector " << std::endl ; 
	iter(v, v.size(), showInt<int>);


	const std::vector<int> c(v);
	std::cout << "===== CONST container ==> VECTOR" << std::endl;
	std::cout << "Original const vector " << std::endl ; 
  	iter(c, c.size(), showInt<int>);
	// Use wrapper to disambiguate
	//std::vector<int> c2 = iter(c, c.size(), squareConst<int>);
	// Use Static Cast to disambiguate Square to the one that returns
	std::vector<int> c2 = iter(c, c.size(), static_cast<int(*)(int const &)>(square<int>));
	std::cout << "Squared  const vector " << std::endl ; 
	iter(c2, c2.size(), showInt<int>);
}


{//list container
	std::list<int> l;
	l.push_back(0);
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(8);
	l.push_back(9);

		std::cout << "===== NON-CONST container ==>LIST" << std::endl;
	std::cout << "Original list " << std::endl ; 
	iter(l, l.size(), showInt<int>);
	iter(l, l.size(), square<int>);
	std::cout << "Squared  list " << std::endl ; 
	iter(l, l.size(), showInt<int>);


	const std::list<int> lc(l);
	std::cout << "===== CONST container  ==>LIST" << std::endl;
	std::cout << "Original const list " << std::endl ; 
  	iter(lc, lc.size(), showInt<int>);
	// Use wrapper to disambiguate
	//std::list<int> lc2 = iter(lc, lc.size(), squareConst<int>);
	// Use Static Cast to disambiguate Square to the one that returns
	std::list<int> lc2 = iter(lc, lc.size(), static_cast<int(*)(int const &)>(square<int>));
	std::cout << "Squared  const list " << std::endl ; 
	iter(lc2, lc2.size(), showInt<int>);
}
return 0 ;
}
