#include <iostream>

// 1. Non-const container with void function (in-place modification)
template<typename Container>
void iter 	(	Container & container, 
				size_t l, 
				void (*func)( typename Container::value_type &  )
			)	
{
	typename Container::iterator it = container.begin();
	for( size_t i=0 ; i < l; i++, ++it)
	{
		func(*it);
	}
	std::cout << " Non const used void func" << std::endl;
}

// 2. Non-const container with const& function (read-only, like showInt)
template<typename Container>
void iter 	(	Container & container, 
				size_t l, 
				void (*func)( typename Container::value_type const &  )
			)	
{
	typename Container::iterator it = container.begin();
	for( size_t i=0 ; i < l; i++, ++it)
	{
		func(*it);
	}
	std::cout << " non const used void func with const" << std::endl;
}

// 3. const container with function returning modified value
template<typename Container>
Container  iter 	(	Container const & container, 
				size_t const l, 
				typename Container::value_type (*func)( typename Container::value_type const &  )
			)	
{
	Container result(container);
	typename Container::iterator it = result.begin();
	for( size_t i=0 ; i < l; i++,++it)
	{
		*it= func(*it);
	}
	std::cout << " const used returning" << std::endl;
	return result ;
}

// 4. const container with void function read only
template<typename Container>
Container  iter 	(	Container const & container, 
				size_t const l, 
				void (*func)( typename Container::value_type const &  )
			)	
{
	Container result(container);
	typename Container::const_iterator it = container.begin();
	for( size_t i=0 ; i < l; i++, ++it)
	{
		func(*it);
	}
	std::cout << " const used void" << std::endl;
	return result ;
}

// 5. container with void non-const function (in-place modification)
template<typename Container>
void iter 	(	Container * container, 
				size_t l, 
				void (*func)( Container &  )
			)	
{
	for( size_t i=0 ; i < l; i++)
	{
		func(container[i]);
	}
	std::cout << " Array with const func" << std::endl;
}
// 6. container with void const function (in-place modification)
template<typename Container>
void iter 	(	Container * container, 
				size_t l, 
				void (*func)( Container const &  )
			)	
{
	for( size_t i=0 ; i < l; i++)
	{
		func(container[i]);
	}
	std::cout << " Array with const func" << std::endl;
}


// For non-const container (modifies in place)
template<typename T>
void square (T & arrayelement)
{
	std::cout << "non const square" << std::endl;
	arrayelement *= arrayelement;
}

// For const container (returns new value)
template<typename T>
T  square (T const & arrayelement)
{
	std::cout << "const square" << std::endl;
	return arrayelement * arrayelement;
}

// showInt works with both (const version)
template<typename T>
void showInt( T const & n ) 
{
	std::cout << n << std::endl;
}

/*template<typename T>
void showInt( T & n ) 
{
	std::cout << n << std::endl;
}
*/

// This wrapper  disambiguate:
template<typename T>
T squareConst(T const & val)
{
    return square(val);
}

template<typename T>
void squareMut(T & val)
{
    square(val);
}
