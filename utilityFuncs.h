#include <iostream>
#include <vector>
#include <cmath>
#include <map>

// Use of the seive for finding primes (this can be optimized)
std::vector<long long int> getPrimesUpToNumber(long long int number)
{
   auto sqrtOfNumber = floor(sqrt(number));
   std::map<long long int, bool> numberToPrimeMap;
   std::vector<long long int> primes;

   for (long long int i = 1; i <= number; ++i)
      numberToPrimeMap[i] = true;
   
   numberToPrimeMap[1] = false;

   for (long long int i = 2; i <= sqrtOfNumber; ++i)
   {
      for (long long int j = 2; j < i; ++j)
         if (numberToPrimeMap[j] && i % j == 0)
         {
            numberToPrimeMap[i] = false;
            break;
         }

      if (numberToPrimeMap[i])
         for (long long int j = i + i; j <= number; j += i)
            numberToPrimeMap[j] = false;
   }

   for (long long int i = 1; i <= number; ++i)
      if (numberToPrimeMap[i])
         primes.push_back(i);

   return primes;
}