#include <iostream>
#include "utilityFuncs.h"

int getLargestPrimeFactor(long long int);

int main(int argc, char** argv)
{
   std::cout << getLargestPrimeFactor(5000000) << std::endl;
   return 0;
}

int getLargestPrimeFactor(long long int num)
{
	std::vector<long long int> primes = getPrimesUpToNumber(num);

	for (auto rit = primes.rbegin(); rit != primes.rend(); ++rit)
		if (num % *rit == 0)
			return *rit;
	
	return num;
}