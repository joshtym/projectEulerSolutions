#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <unordered_set>
#include "utilityFuncs.h"

int getDistinctTerms(int, int, int, int);
std::string getPrimeFactorization(std::vector<unsigned int>, int, int);

int main(int argc, char** argv)
{
   std::cout << getDistinctTerms(2, 100, 2, 100) << std::endl;

   return 0;
}

int getDistinctTerms(int aLowerLimit, int aUpperLimit, int bLowerLimt, int bUpperLimit)
{
   std::vector<unsigned int> primes = calculateSeiveUpToNumber(aUpperLimit);
   std::unordered_set<std::string> distinctTerms;

   for (int i = aLowerLimit; i <= aUpperLimit; ++i)
      for (int j = bLowerLimt; j <= bUpperLimit; ++j)
         distinctTerms.insert(getPrimeFactorization(primes, i, j));

   return distinctTerms.size();
}

std::string getPrimeFactorization(std::vector<unsigned int> potentialPrimeFactors, int number, int power)
{
   std::string hasPrime = "";
   std::vector<std::string> primePower;
   primePower.reserve(potentialPrimeFactors.size());
   std::string stringRepresentationOfPrimesAndPowers = "";

   for (int i = 0; i < potentialPrimeFactors.size(); ++i)
   {
      hasPrime += "0";
      primePower.push_back("0");
   }

   for (int i = 0; i < potentialPrimeFactors.size(); ++i)
   {
      if (number == 1)
         break;
      
      int powerOfPrime = 0;

      while (number % potentialPrimeFactors[i] == 0)
      {
         hasPrime[i] = '1';
         powerOfPrime++;
         number /= potentialPrimeFactors[i];
      }

      primePower[i] = std::to_string(powerOfPrime * power);
   }

   stringRepresentationOfPrimesAndPowers = hasPrime + ";";

   for (int i = 0; i < primePower.size(); ++i)
      stringRepresentationOfPrimesAndPowers += primePower[i] + (i != primePower.size() - 1 ? "," : "");
   
   return stringRepresentationOfPrimesAndPowers;
}