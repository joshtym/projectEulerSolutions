#include <iostream>
#include <fstream>

std::string getStringFromNumber(int);

int main(int argc, char** argv)
{
   int size = 0;
   for (int i = 1; i <= 1000; ++i)
      size += getStringFromNumber(i).length();

   std::cout << size << std::endl;
   return 0;
}

std::string getStringFromNumber(int number)
{
   std::string firstTwentyNumbers[20] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
   std::string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
   std::string numberAsString = "";
   bool useAnd = number > 99;

   if (number / 1000 > 0)
   {
      numberAsString += firstTwentyNumbers[number / 1000] + "thousand";
      number %= 1000;
   }

   if (number / 100 > 0)
   {
      numberAsString += firstTwentyNumbers[number / 100] + "hundred";
      number %= 100;
   }

   if (number == 0)
      return numberAsString;

   numberAsString += useAnd ? "and" : "";
   if (number < 20)
      numberAsString += firstTwentyNumbers[number];
   else
   {
      numberAsString += tens[number / 10];
      number %= 10;
      
      if (number != 0)
         numberAsString += firstTwentyNumbers[number];
   }

   return numberAsString;
}