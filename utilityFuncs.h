#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

// Use of the seive for finding primes up to a number (needs to be adjusted as it does not work for large numbers)
// Note that this only works for the set of integers and is good enough
// TODO: Optimize this
std::vector<int> getNumberedPrimes(int size)
{
   long double sqrtOfNumber = sqrt(INT_MAX);
   std::vector<int> primes = {2};

   for (int i = 3; i <= INT_MAX; ++i)
   {
      if (primes.size() == size)
         break;

      if (std::all_of(primes.begin(), primes.end(), [&](int prime){return i%prime != 0;}))
         primes.push_back(i);
   }

   return primes;
}

// Use recursive method to determine prime factors by starting from the base prime of 2
std::vector<long long int> getPrimeFactors(long long int number, int startCheckNumber)
{
   std::vector<long long int> primeFactors;

   // Anything less than 2 will do weird things to this function
   if (startCheckNumber < 2)
      return primeFactors;

   while (number % startCheckNumber != 0)
      ++startCheckNumber;

   primeFactors.push_back(startCheckNumber);

   if (number == startCheckNumber)
      return primeFactors;

   while (number % startCheckNumber == 0)
      number /= startCheckNumber;

   std::vector<long long int> primeFactorsOfFactor = getPrimeFactors(number, startCheckNumber + 1);
   primeFactors.insert(primeFactors.end(), primeFactorsOfFactor.begin(), primeFactorsOfFactor.end());

   return primeFactors;
}

// Function to determine if a number is a palindrome
bool isNumberPalindrome(int number)
{
   auto numberAsString = std::to_string(number);
   auto startIndex = 0;
   auto endIndex = numberAsString.length() - 1;
   
   while(startIndex < endIndex)
      if (numberAsString[startIndex++] != numberAsString[endIndex--])
         return false;
      
   return true;
}

// Utility function to get all the primes up to a number (this function only works for unsigned max int)
std::vector<unsigned int> calculateSeiveUpToNumber(unsigned int maxNumber)
{
   std::vector<unsigned int> primes;
   double sqrtOfNumber = sqrt(maxNumber);
   unsigned int indexOfEndOfComparingPrimes = 0;
   bool isPrime;
   unsigned int startingIndex;

   if (maxNumber < 2)
      return primes;

   primes.push_back(2);

   for (unsigned int i = 3; i <= maxNumber; ++i)
   {
      isPrime = true;
      startingIndex = 0;
      while (startingIndex <= indexOfEndOfComparingPrimes)
      {
         if (i % primes[startingIndex++] == 0)
         {
            isPrime = false;
            break;
         }
      }

      if (isPrime)
      {
         primes.push_back(i);
         indexOfEndOfComparingPrimes += (i <= sqrtOfNumber);
      }
   }

   return primes;
}