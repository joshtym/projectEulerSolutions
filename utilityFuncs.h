#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Use of the seive for finding primes up to a number (needs to be adjusted as it does not work for large numbers)
std::vector<long long int> getPrimesUpToNumber(long long int number)
{
   long double sqrtOfNumber = sqrt(number);
   std::vector<long long int> primes = {2};

   for (long long int i = 3; i <= number; ++i)
      if (std::all_of(primes.begin(), primes.end(), [&](long long int prime){return i%prime != 0;}))
         primes.push_back(i);

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