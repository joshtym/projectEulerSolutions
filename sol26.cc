#include <iostream>
#include <string>
#include <algorithm>

int getLongestRepeatingDenominator(int);
std::string getStringDecimal(int, int, bool&);
std::string determineRepeatingDecimalStatus(std::string, bool&, int&);

int main(int argc, char** argv)
{
   bool isRepeating = false;
   std::cout << getStringDecimal(1, 6, isRepeating) << std::endl;
   std::cout << isRepeating << std::endl;
   return 0;
}

int getLongestRepeatingDenominator(int upperLimit)
{
   return -1;
}

std::string getStringDecimal(int numerator, int denominator, bool& isRepeating)
{
   int indexOfNumeratorDigit = 0;
   std::string numeratorAsString = std::to_string(numerator);
   int remainder = 0;
   bool addedDecimal = false;
   std::string number = "";
   std::string dividingNumberToTry = "";
   int lengthOfNumerator = numeratorAsString.length();
   int iteration = 1;

   while (remainder != 0 || indexOfNumeratorDigit < lengthOfNumerator)
   {
      if (iteration % 2000 == 0)
      {
         number = determineRepeatingDecimalStatus(number, isRepeating);
         if (isRepeating)
            break;
         iteration = 1;
      }
      else
         iteration++;

      dividingNumberToTry += std::to_string(remainder);
      dividingNumberToTry += (indexOfNumeratorDigit < lengthOfNumerator) ? numeratorAsString[indexOfNumeratorDigit++] : '0';

      while (atoi(dividingNumberToTry.c_str()) / denominator == 0)
      {
         //if (repeatingR)
         if (!addedDecimal)
         {
            if (number == "")
               number.append("0");
            number.append(".");
            addedDecimal = true;
         }
         else
            number.append("0");

         dividingNumberToTry += (indexOfNumeratorDigit < lengthOfNumerator) ? numeratorAsString[indexOfNumeratorDigit++] : '0';
      }

      number += std::to_string(atoi(dividingNumberToTry.c_str()) / denominator);
      remainder = atoi(dividingNumberToTry.c_str()) % denominator;
      dividingNumberToTry = "";
   }

   return number;
}

std::string determineRepeatingDecimalStatus(std::string number, bool& isRepeating, int& startOfRepeatIndex)
{
   int startingIndex = number.find('.') + 1;
   int maxStartIndex = (number.length() - startingIndex) / 2;

   for (int i = startingIndex; i < maxStartIndex; ++i)
   {
      int maxLength = (i - startingIndex) / 2;

      for (int j = 1; j <= maxLength; ++j)
      {
         std::string repeatingNumToTry = "";

         for (int k = i; k < j + i; ++k)
            repeatingNumToTry += number[k];

         std::string comparingNumber = number.substr(0, i); 
      }
   }

   return number;
}