#include <iostream>
#include "utilityFuncs.h"

int getNumberedPrime(int);

int main(int argc, char** argv)
{
   std::cout << getNumberedPrime(10001) << std::endl;
   return 0;
}

// Solution for EULER #7
int getNumberedPrime(int number)
{
   return getNumberedPrimes(number)[number - 1];
}