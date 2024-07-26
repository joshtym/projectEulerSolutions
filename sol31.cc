#include <iostream>

int waysToMakeMoneyValue(int,int);

int setOfCoins[] = {200, 100, 50, 20, 10, 5, 2, 1};
int allSolutions[8000][8];

int main(int argc, char** argv)
{
   std::cout << waysToMakeMoneyValue(200, 0) << std::endl;
   return 0;     
}

int waysToMakeMoneyValue(int moneyLeft, int startingIndex)
{
   /*
    * Clearly, if we have calculated the value or if we have no money left
    * return the appropriate values
   */
   if (moneyLeft == 0)
      return 1;
   if (allSolutions[moneyLeft][startingIndex] != 0)
      return allSolutions[moneyLeft][startingIndex];

   int numberOfWays = 0;

   /*
    * Interesting recursive step. We start with the largest coin index and
    * recurse down trying all possible solutions. So, for example, 11 would
    * try 10,1  then 5,5,1, then 5,1,1,1,1,1,1,then eleven ones
   */
   for (int i = startingIndex; i < 8; ++i)
      if (moneyLeft >= setOfCoins[i])
         numberOfWays += waysToMakeMoneyValue(moneyLeft - setOfCoins[i],i);

   allSolutions[moneyLeft][startingIndex]  = numberOfWays;

   return numberOfWays;
}