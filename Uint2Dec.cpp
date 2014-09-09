// Convert from uintvar to decimal
// Joe Collins 27/5/13

#include <iostream>
#include <cstdio>
#include <cmath>

int uintvartoDecimal(unsigned long);
const int FINALMAX = 10000;

int
main(int argc, char* argv[])
{

   for ( int i = 1; i < argc; ++i )
   {
      long a;
      ::sscanf(argv[i], "%lx", &a); // read hex string and form long value
      std::cout << argv[i] << ": " << uintvartoDecimal(a) << std::endl;
   }

   return 0;
}

int
uintvartoDecimal(unsigned long b)
{
	int u[FINALMAX];
	int x[FINALMAX];
	int p;
	int q;
	int c = 0;
	int count = 0;
	bool done = false;

	while (b != 0)
	{
		p = b & 0xff; // takes first 8 bits from the uintvar
		u[count] = p; // puts those 8 in a collection
		b = b >> 8; // shifts the uintvar right 8
		count++;
	}
	int fin = count;
	for(int i = (count-1); i>=0; i--)
	{
		q = u[i]; // starting on the largest numbers take out 8 bits
		if ( (q & 0x80) == 0x80 ) // if the MSB is 1
		{
			q = (q & 0x7f); // get rid of sig bit
			x[i] = q; // put in new collection, smallest to biggest
			fin--;
		}
		else
		{
			x[i] = q; // put in new collection
			done = true; // set done to true
			fin--;
		}
		if (done == true) // gets out of for loop
			i=-1;
	} 
	for(int j = fin; j < count; j++) // for loop starting on smallest numbers
	{
		b += (x[j] * std::pow(128.0, c));
		c++;
	}
	if (done == true)
		return b;
	else 
		return 0;
}
