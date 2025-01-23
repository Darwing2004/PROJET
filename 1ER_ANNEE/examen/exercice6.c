#include <stdio.h>

int Puissance - Modulaire1(unsigned long long g, unsigned long long e, unsigned long long n)
{
	if (e == 1)
	{
		return g % n;
	}

	unsigned long long result;
	if (e > 1)
	{
		unsigned long long nbre = e / 2;
		unsigned long long reste = e % 2;
		if (reste != 0)
		{
			return result = g ^ e % n;
			return Puissance - Modulaire1(g ^ 2 % n, e / 2, n);
		}
	}
}