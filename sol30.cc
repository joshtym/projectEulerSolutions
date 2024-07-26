#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

int getSumOfDigitPowers(int);

int main(int argc, char** argv)
{
   std::cout << getSumOfDigitPowers(5) << std::endl;
   return 0;
}

int getSumOfDigitPowers(int power)
{
   int numOfDigits = 2;
   int sumOfDigitPowers = 0;

   while(true)
   {
      std::string startingNumber = "1";
      std::string nextPowerOf10 = "";

      while (startingNumber.length() < numOfDigits)
         startingNumber += "0";

      nextPowerOf10 = startingNumber + "0";

      int maxNumber = 0;

      for (int i = 0; i < numOfDigits; ++i)
         maxNumber += pow(9, power);
      
      maxNumber = std::min(std::stoi(nextPowerOf10) - 1, maxNumber);

      if (maxNumber < std::stoi(startingNumber))
         break;

      for (int i = std::stoi(startingNumber); i <= maxNumber; ++i)
      {
         int sum = 0;
         int num = i;

         while (num != 0)
         {
            sum += pow(num % 10, power);
            num /= 10;
         }

         if (sum == i)
            sumOfDigitPowers += i;
      }
      numOfDigits++;
   }

   return sumOfDigitPowers;
}