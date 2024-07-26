#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "utilityFuncs.h"

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