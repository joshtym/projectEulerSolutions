#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

int getSumOfPandigitalNumbers();
bool isPandigital(int, int, bool&);

int main(int argc, char** argv)
{
   bool test = false;
   std::cout << getSumOfPandigitalNumbers() << std::endl;
   return 0;
}

int getSumOfPandigitalNumbers()
{
   std::unordered_set<int> products;
   int sum = 0;

   for (int i = 1; i < 100; ++i)
   {
      bool exceedsLimit = false;
      int multiplicand = i + 1;

      while (true)
      {
         if (isPandigital(i, multiplicand, exceedsLimit) && !products.count(multiplicand * i))
         {
            products.insert(multiplicand * i);
            sum += (multiplicand * i);
         }
         
         if (exceedsLimit)
            break;

         multiplicand++;
      }
   }
   return sum;
}

bool isPandigital(int multiplicant, int multiplicand, bool& exceedsLimit)
{
   int product = multiplicant * multiplicand;
   std::string combinedNumber = std::to_string(multiplicant) + std::to_string(multiplicand) + std::to_string(product);

   if (combinedNumber.length() > 9)
   {
      exceedsLimit = true;
      return false;
   }

   std::sort(combinedNumber.begin(), combinedNumber.end());

   if (combinedNumber == "123456789")
      return true;

   return false;
}