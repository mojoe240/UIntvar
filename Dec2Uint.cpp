// Converts from decimal to uintvar
// Joe Collins 27/5/13

#include <iostream>
#include <cstdlib>

const int FINALMAX = 10000;
int uintvar(unsigned long);

int
main(int argc, char* argv[])
{

    for ( int i = 1; i < argc; ++i )
    {
      unsigned long a = ::atol(argv[i]); // atol converts a string to unsigned long
	  std::cout << argv[i] << ": " << std::hex << uintvar(a) << std::endl;
    }

    return 0;

}
 
int
	uintvar(unsigned long b)
{
	int u[FINALMAX]; // collection for bits of 7
	int count = 0;
	int p; // variable used in deconstruction of the bits
	int q; // variable used in construction of uintvar representation

	while (b != 0) //while b is not empty
	{
		p = b & 0x7f; // takes out the first seven bits
		u[count] = p; // adds p to collection
		b = b >> 7; // shifts our number over 7 bits
		count++; // increments count for collection
	}

	for(int i = (count - 1); i >= 0; i--) 
	{
		q = u[i]; // starts on last bitset taken in
		if (i == 0) // if it's the last bitset
			q = q & 0x7f;
		else
			q = q | 0x80;
		b = b << 8; // shift left
		b = b + q;  // add bitset to uintvar
	}

	return b;

}


