#include <iostream>
#include <algorithm>
#include <string>

std::string getPermutationOfString(std::string, int);

int main(int argc, char** argv)
{
   std::cout << getPermutationOfString("0123456789", 1000000) << std::endl;

   return 0;
}

std::string getPermutationOfString(std::string permutableString, int iteration)
{
   int currIteration = 1;

   do
   {
      if (currIteration++ == iteration)
         return permutableString;
   } while (std::next_permutation(permutableString.begin(), permutableString.end()));
   return "";
}