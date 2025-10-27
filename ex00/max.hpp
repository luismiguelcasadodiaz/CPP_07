#ifndef MAX_HH
#define MAX_HH

template<typename T>
T const & max( T const & a, T const & b)
{
    return (a > b ? a : b) ;
}

#endif
