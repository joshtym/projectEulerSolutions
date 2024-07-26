#include <iostream>
#include <string>
#include <vector>
#include "utilityFuncs.h"

char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

std::string performMultiplicationOfStringNumbers(std::string, std::string);

int main(int argc, char** argv)
{
   // This could be optimized by doing multiplication of some of these numbers that can
   // be contained a long long int and converted to a string. However, this works for now
   int sumOfDigits = 0;
   std::string factorial = performMultiplicationOfStringNumbers("100", "99");
   for (int i = 98; i >= 1; --i)
      factorial = performMultiplicationOfStringNumbers(factorial, std::to_string(i));
   
   for (int i = 0; i < factorial.length(); ++i)
      sumOfDigits += ((int)factorial[i] - 48);

   std::cout << sumOfDigits << std::endl;

   return 0;
}

std::string performMultiplicationOfStringNumbers(std::string numberOne, std::string numberTwo)
{
   std::vector<std::string> numbersToAdd;
   int numTwoEndIndex = numberTwo.length() - 1;
   int numOneEndIndex = numberOne.length() - 1;

   for (int i = numTwoEndIndex; i >= 0; --i)
   {
      std::string number = "";
      for (int j = 0; j < numTwoEndIndex - i; ++j)
         number += "0";
      
      int carryOver = 0;

      for (int j = numOneEndIndex; j >= 0; --j)
      {
         int multipliedNumber = ((int)numberTwo[i] - 48) * ((int)numberOne[j] - 48) + carryOver;
         number = numbers[multipliedNumber % 10] + number;
         carryOver = multipliedNumber / 10;
      }

      while (carryOver != 0)
      {
         number = numbers[carryOver % 10] + number;
         carryOver = carryOver / 10;
      }
      numbersToAdd.push_back(number);
   }

   return addVectorOfStringNumbers(numbersToAdd);
}