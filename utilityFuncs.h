#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Use of the seive for finding primes (this can be optimized)
std::vector<long long int> getPrimesUpToNumber(long long int number)
{
   long double sqrtOfNumber = sqrt(number);
   std::vector<long long int> primes = {3};
   std::vector<long long int> additionalPrimes;

   for (long long int i = 3; i <= sqrtOfNumber; ++i)
      if (std::all_of(primes.begin(), primes.end(), [](long long int prime){return i % prime != 0;})
         primes.push_back(i);
         
   for (long long int = floor(sqrtOfNumber) + 1; i <= number; ++i)
      if (std::all_of(primes.begin(), primes.end(), [](long long int prime){return i % prime != 0;})
         additionalPrimes.push_back(i);
            
    primes.insert(primes.end(), additionalPrimes.begin(), additionalPrimes.end());

   return primes;
}