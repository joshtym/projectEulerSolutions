#include <iostream>
#include <cmath>
#include "utilityFuncs.h"z

long long int getLargestPrimeFactor(long long int);

int main(int argc, char** argv)
{
   std::cout << getLargestPrimeFactor(600851475143) << std::endl;
   return 0;
}

long long int getLargestPrimeFactor(long long int num)
{
   std::vector<long long int> primes = getPrimeFactors(num, 2);

   for (auto rit = primes.rbegin(); rit != primes.rend(); ++rit)
      if (num % *rit == 0)
         return *rit;
   
   return num;
}