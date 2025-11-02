#include <iostream>
template<typename Container>
void iter 	(	Container & container, 
				size_t l, 
				void (*func)( typename Container::value_type &  )
			)	
{
	for( size_t i=0 ; i < l; i++)
	{
		func(container[i]);
	}
	std::cout << " Non const used" << std::endl;
}


template<typename Container>
Container  iter 	(	Container const & container, 
				size_t const l, 
				void (*func)( typename Container::value_type const &  )
			)	
{
	Container result(container);
	for( size_t i=0 ; i < l; i++)
	{
		func(result[i]);
	}
	std::cout << " const used" << std::endl;
	return result ;
}



template<typename T>
void square (T & arrayelement)
{
	std::cout << "non const square" << std::endl;
	arrayelement *= arrayelement;
}

template<typename T>
T & square (T const & arrayelement)
{
	std::cout << "const square" << std::endl;
	return arrayelement * arrayelement;
}
template<typename T>
void showInt( T const & n ) 
{
	std::cout << n << std::endl;
}
/*
template<typename T>
void showInt( T  & n ) 
{
	std::cout << n << std::endl;
}
*/
