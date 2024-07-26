#include <iostream>
#include "utilityFuncs.h"

int getIndexOfTermWithNDigitsInFibSequence(int);

int main(int argc, char** argv)
{
   std::cout << getIndexOfTermWithNDigitsInFibSequence(1000) << std::endl;
   return 0;
}

int getIndexOfTermWithNDigitsInFibSequence(int numOfDigits)
{
   std::string termOne = "1";
   std::string termTwo = "1";
   int termNumber = 2;

   while (termTwo.length() < numOfDigits)
   {
      std::string tmp = termTwo;
      termTwo = addTwoStringNumbers(termTwo, termOne);
      termOne = tmp;
      termNumber++;
   }

   return termNumber;
}