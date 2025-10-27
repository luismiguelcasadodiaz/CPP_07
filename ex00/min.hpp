#ifndef MIN_HH
#define MIN_HH

template<typename T>
T const & min( T const & a, T const & b)
{
    return (a < b ? a : b);
}

#endif
