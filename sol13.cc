#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "utilityFuncs.h"

std::string addTwoStringNumbers(std::string numOne, std::string numTwo);

int main(int argc, char** argv)
{
   std::vector<std::string> numbers;
   
   std::string number = "";
   std::ifstream file;
   file.open("prob13.txt");

   while (!file.eof())
   {
      std::getline(file, number);
      numbers.push_back(number);
   }
   
   file.close();

   std::cout << addVectorOfStringNumbers(numbers).substr(0, 10) << std::endl;

   return 0;
}

// Solution one involved adding two numbers the whole way through
std::string addTwoStringNumbers(std::string numOne, std::string numTwo)
{
   bool carryOver = false;
   char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
   int maxLength = std::max(numOne.length(), numTwo.length());
   std::string sum = "";

   for (int i = 0; i < maxLength; ++i)
   {
      char digitOne = i < numOne.length() ? numOne[numOne.length() - 1 - i] : '0';
      char digitTwo = i < numTwo.length() ? numTwo[numTwo.length() - 1 - i] : '0';
      int numericSum = 0 + carryOver;
      for (int j = 0; j < 10; ++j)
      {
         if (digitOne == numbers[j])
            numericSum += j;
         if (digitTwo == numbers[j])
            numericSum += j;
      }

      carryOver = numericSum >= 10;
      numericSum = carryOver ? numericSum - 10 : numericSum;
      sum = numbers[numericSum] + sum;
   }

   if (carryOver)
      sum = '1' + sum;

   return sum;
}