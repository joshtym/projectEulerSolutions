#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "utilityFuncs.h"

int getSumOfAmicableNumbers();

int main(int argc, char** argv)
{
   std::cout << getSumOfAmicableNumbers() << std::endl;
   return 0;
}

int getSumOfAmicableNumbers()
{
   int sumOfDivisors[10000];

   std::fill_n(std::begin(sumOfDivisors), 10000, -1);
   std::vector<int> amicableNumbers;
   int sumOfAmicableNumbers;

   for (int i = 2; i < 10000; ++i)
   {
      if (std::find(amicableNumbers.begin(), amicableNumbers.end(), i) != amicableNumbers.end())
         continue;
      
      int sum = getSumOfDivisors(sumOfDivisors, i, 10000);

      if (sum != i && sum < 10000)
      {
         int otherSum = getSumOfDivisors(sumOfDivisors, sum, 10000);

         if (otherSum == i)
         {
            amicableNumbers.push_back(i);
            if (sum < 10000)
               amicableNumbers.push_back(sum);
         }
      }
   }

   for (int i = 0; i < amicableNumbers.size(); ++i)
      sumOfAmicableNumbers += amicableNumbers[i];
      
   return sumOfAmicableNumbers;
}