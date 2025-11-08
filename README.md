# CPP_07
Templates


## Function templates


### swap
```c++
template<typename T>
void swap( T & a, T & b)
{
    T c = b;
    b = a ;
    a = c;
}
```

### min
```c++
template<typename U>
U const & min( U const & a, U const & b)
{
    return (a < b ? a : b);
}
```

## Container's Iterator template

Two different signatures to deal with const and non-const container arguments.

The function template passed as an argument must match the const/non-const container.

Attention must be paid to the container `value_type`, which must be considered in the function template used inside the iterator.

I want to use same iterator to change container's value and to print container's value, so i face 4 scenarios

|           | change           | print             | 
|-----------|------------------|-------------------|
|Non-const  | change in place  | read only         |
|const      | change a copy    | read only         |



```c++
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
```

