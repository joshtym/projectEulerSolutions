#include <iostream>
#include "utilityFuncs.h"

int getLargestPalindromeOfThreeDigitMultiplication();

int main(int argc, char** argv)
{
   std::cout << getLargestPalindromeOfThreeDigitMultiplication() << std::endl;
   return 0;
}

// Solution for EULER #4
int getLargestPalindromeOfThreeDigitMultiplication()
{
   auto largestPalindrome = -1;
   
   for (auto lowNumber = 100; lowNumber < 1000; ++lowNumber)
      for (auto compareNumber = lowNumber; compareNumber < 1000; ++compareNumber)
         if (isNumberPalindrome(compareNumber * lowNumber))
            largestPalindrome = std::max(compareNumber * lowNumber, largestPalindrome);
      
   return largestPalindrome;
}