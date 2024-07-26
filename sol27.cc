#include <iostream>
#include <cmath>
#include <vector>
#include "utilityFuncs.h"

int getProductOfCoefficientsForQuadraticPrimes(int);
bool isPrime(int);

int main(int argc, char** argv)
{
   std::cout << getProductOfCoefficientsForQuadraticPrimes(1000) << std::endl;
   return 0;
}

int getProductOfCoefficientsForQuadraticPrimes(int upperBound)
{
   if (upperBound < 0)
      return -1;
   
   int consecutivePrimes = 0;
   int coefficientA = 0;
   int coefficientB = 0;
   int numOfLinePrintouts = 0;
   int lines = 0;

   std::unique_ptr<bool[]> primesUpToNumber = seiveUpToNumber(upperBound);

   for (int i = 0; i < upperBound; ++i)
   {
      if (!primesUpToNumber[i])
         continue;
      
      for (int j = (upperBound - 1) * -1; j < upperBound - 1; ++j)
      {
         int n = 0;

         while (isPrime(pow(n, 2) + j * n + i))
            n++;
         
         if (n > consecutivePrimes)
         {
            consecutivePrimes = n;
            coefficientA = j;
            coefficientB = i;
         }
      }
   }

   return coefficientA * coefficientB;
}