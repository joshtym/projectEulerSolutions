#include <iostream>
#include <string>
#include <algorithm>

int getLongestRepeatingDenominator(int);
std::string getStringDecimal(int, int, bool&, int&);
std::string determineRepeatingDecimalStatus(std::string, bool&, int&);

int main(int argc, char** argv)
{
   bool isRepeating = false;
   int startingIndex = 0;
   std::cout << getLongestRepeatingDenominator(1000) << std::endl;
   return 0;
}

int getLongestRepeatingDenominator(int upperLimit)
{
   int maxPeriod = 0;
   int longestRepeatingDenominator = 0;
   for (int i = 1; i < upperLimit; ++i)
   {
      if (i % 2 == 0)
         continue;
      if (i % 5 == 0)
         continue;
      
      bool isRepeating = false;
      int startIndexOfPeriod = -1;
      std::string decimalOfFraction = getStringDecimal(1, i, isRepeating, startIndexOfPeriod);

      if (isRepeating && (decimalOfFraction.length() - startIndexOfPeriod) > maxPeriod)
      {
         maxPeriod = decimalOfFraction.length() - startIndexOfPeriod;
         longestRepeatingDenominator = i;
      }
   }
   return longestRepeatingDenominator;
}

// This function is a programmed version of long manual long division. In order to determine if a decimal is repeating,
// we check every 2000 digits to see if we've determined a repeating decimal yet
std::string getStringDecimal(int numerator, int denominator, bool& isRepeating, int& startIndexOfRepeat)
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
         int startIndex = 0;
         number = determineRepeatingDecimalStatus(number, isRepeating, startIndexOfRepeat);
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

// This function takes the current number in and returns a stripped version of the number (if it's a repeating decimal)
std::string determineRepeatingDecimalStatus(std::string number, bool& isRepeating, int& startOfRepeatIndex)
{
   int startingIndex = number.find('.') + 1;
   int maxStartIndex = (number.length() - startingIndex) / 2;

   for (int i = startingIndex; i < maxStartIndex; ++i)
   {
      int maxLength = (number.length() - i) / 2;

      for (int j = 1; j <= maxLength; ++j)
      {
         std::string repeatingNumToTry = "";

         for (int k = i; k < j + i; ++k)
            repeatingNumToTry += number[k];

         std::string comparingNumber = number.substr(0, i);
         
         while (comparingNumber.length() < number.length())
            comparingNumber += repeatingNumToTry;
         
         comparingNumber = comparingNumber.substr(0, number.length());

         if (comparingNumber == number)
         {
            isRepeating = true;
            startOfRepeatIndex = i;
            return number.substr(0, i) + repeatingNumToTry;
         }
      }
   }

   isRepeating = false;
   startOfRepeatIndex = -1;
   return number;
}