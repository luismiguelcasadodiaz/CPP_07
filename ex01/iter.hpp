template<typename T>
void iter (T const & array, int const l, void (*func)(int) )
{
	for( int i=0 ; i < l; i++)
	{
		func(array[i]);
	}
}





template<typename T>
void square (T & arrayelement)
{
	arrayelement *= arrayelement;
}

template<typename T>
T & square (T const & arrayelement)
{
	return arrayelement * arrayelement;
}
