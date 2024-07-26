#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int getSumOfAmicableNumbers();
std::vector<int> getProperDivisors(int);
int getSumOfDivisors(int[], int);

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
      
      int sum = getSumOfDivisors(sumOfDivisors, i);

      if (sum != i && sum < 10000)
      {
         int otherSum = getSumOfDivisors(sumOfDivisors, sum);

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

int getSumOfDivisors(int sumOfDivisorsArray[10000], int number)
{
   if (number < 10000 && sumOfDivisorsArray[number] != -1)
      return number;
   
   std::vector<int> divisors = getProperDivisors(number);
   int sum = 0;

   for (int j = 0; j < divisors.size(); ++j)
      sum += divisors[j];

   if (number < 10000)
      sumOfDivisorsArray[number] = sum;

   return sum;
}

std::vector<int> getProperDivisors(int number)
{
   std::vector<int> divisors = {1};
   for (int i = 2; i <= sqrt(number); ++i)
   {
      if (number % i == 0)
      {
         divisors.push_back(i);
         if (i != sqrt(number))
            divisors.push_back(number / i);
      }
   }
   return divisors;
}