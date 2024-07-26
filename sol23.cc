#include <iostream>
#include <algorithm>
#include "utilityFuncs.h"

int main(int argc, char** argv)
{
   long long int sumOfAbundantNumbers = 0;
   int sumOfDivisorsArray[28124];
   std::vector<int> abundantNumbers;
   bool isSummableByAbundantNumbers[56248];

   std::fill_n(std::begin(sumOfDivisorsArray), 28124, -1);
   std::fill_n(std::begin(isSummableByAbundantNumbers), 56248, false);

   for (int i = 1; i <= 28123; ++i)
   {
      int sumOfProperDivisors = getSumOfDivisors(sumOfDivisorsArray, i, 28124);
      if (sumOfProperDivisors > i)
      {
         abundantNumbers.push_back(i);

         for (int j = 0; j < abundantNumbers.size(); ++j)
            isSummableByAbundantNumbers[i + abundantNumbers[j]] = true;
      }
   }

   for (int i = 1; i <= 28123; ++i)
      if (!isSummableByAbundantNumbers[i])
      sumOfAbundantNumbers += i;

   std::cout << sumOfAbundantNumbers << std::endl;

   return 0;
}