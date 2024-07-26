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
   std::unique_ptr<bool[]> primes = seiveUpToNumber(number);
   long long unsigned int sum = 0;

   for (int i = 0; i <= number; ++i)
      sum += primes[i] ? i : 0;
      
   return sum;
}