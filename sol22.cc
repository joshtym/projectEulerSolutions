#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

int getAlphabeticalValueOfString(std::string);

int main(int argc, char** argv)
{
   std::ifstream file;
   std::string name;
   std::vector<std::string> names;
   file.open("prob22.txt");
   long long int sumOfAlphabeticalMultiplication = 0;

   while (std::getline(file, name, ','))
   {
      std::transform(name.begin(), name.end(), name.begin(), ::tolower);
      names.push_back(name.substr(1, name.length() - 2));
   }

   std::sort(names.begin(), names.end());

   for (int i = 0; i < names.size(); ++i)
      sumOfAlphabeticalMultiplication += (i + 1) * getAlphabeticalValueOfString(names[i]);

   std::cout << sumOfAlphabeticalMultiplication << std::endl;

   return 0;
}

int getAlphabeticalValueOfString(std::string name)
{
   int alphValue = 0;

   for (int i = 0; i < name.length(); ++i)
      alphValue += (int)name[i] - 96;

   return alphValue;
}