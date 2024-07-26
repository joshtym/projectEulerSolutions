#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Use of the seive for finding primes
std::vector<long long int> getPrimesUpToNumber(long long int number)
{
   long double sqrtOfNumber = sqrt(number);
   std::vector<long long int> primes = {3};
   std::vector<long long int>::iterator endOfInitalPrimes;

   for (long long int i = 3; i <= number; ++i)
   {
      if (i <= sqrtOfNumber)
         endOfInitialPrimes = primes.end();
         
      if (std::all_of(primes.begin(), endOfInitialPrimes, [](long long int prime){return i % prime != 0;})
         primes.push_back(i);
   }

   return primes;
}