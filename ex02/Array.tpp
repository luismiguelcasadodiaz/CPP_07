#include <cstddef>
#include <sstream>
#include <stdexcept>
template<typename T>
class Array
{
	public:
		Array( void );
		~Array( void );
		Array( Array<T> const & other );
		Array<T> & operator=( Array<T> const & other );
		Array<T>( unsigned int n);
		size_t size( void ) const;
		T operator[](size_t idx) const;
		T & operator[](size_t idx);

	private:
		T * a;
		size_t _size;
};


template<typename T>
Array<T>::Array( void ) :_size(0), a(NULL)
{
}
template<typename T>
Array<T>::Array( unsigned int n)
{
	this->_size = n ;
	this->a = new T[n];
	for (size_t i = 0 ; i < this->_size; i++)
		this->a[i] = T();
}
template<typename T>
Array<T>::~Array( void )
{
	delete[] this->a;
}

template<typename T>
Array<T>::Array( Array<T> const & other)
{
	this->_size = other._size ;
	this->a = new T[other._size];
	for (size_t i = 0 ; i < this->_size; i++)
		this->a[i] = other.a[i];
}
template<typename T>
Array<T> & Array<T>::operator=( Array<T> const & other)
{
	if (this != &other)
	{
		this->_size = other._size;
		delete[] this->a;

		this->a = ( this->_size > 0 ? new T[this->_size] : NULL );
		for (size_t i = 0 ; i < ( this->_size - 1 ); i++)
			this->a[i] = other.a[i]; 
	}
	return *this;
}
	
template<typename T>
T Array<T>::operator[](size_t const idx) const
{
	if ( this->_size <= idx)
	{
		std::stringstream ss;
		ss << "Index " << idx << " out of range in array of size ";
		ss << this->_size << "." ;
		throw std::out_of_range(ss.str()); 
	}
	return this->a[idx] ;
}
template<typename T>
T & Array<T>::operator[](size_t const idx)
{
		if ( this->_size <= idx)
	{
		std::stringstream ss;
		ss << "Index " << idx << " out of range in array of size ";
		ss << this->_size << "." ;
		throw std::out_of_range(ss.str()); 
	}
	return this->a[idx] ;
}


template<typename T>
size_t Array<T>::size( void ) const 
{
	return this->_size ;
}
