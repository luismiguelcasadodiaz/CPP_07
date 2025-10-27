#ifndef SWAP_HH
#define SWAP_HH

template<typename T>
void swap( T & a, T & b)
{
    T c = b;
    b = a ;
    a = c;
}

#endif
