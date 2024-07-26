#include <iostream>
#include "utilityFuncs.h"

long long int getSumOrPrimesBelowANumber(unsigned int);

int main(int argc, char** argv)
{
   std::cout << getSumOrPrimesBelowANumber(2000000) << std::endl;
   return 0;
}

// Solution to EULER #10
long long int getSumOrPrimesBelowANumber(unsigned int number)
{
   std::vector<unsigned int> primes = calculateSeiveUpToNumber(number);
   long long unsigned int sum = 0;
   for_each(primes.begin(), primes.end(), [&](unsigned int prime){sum += prime;});
   return sum;
}