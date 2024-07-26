#include <iostream>
#include <algorithm>

int collatzSize[1000000];

void determineLargestCollatzSequence();

int main(int argc, char** argv)
{
   std::fill_n(std::begin(collatzSize), 1000000, -1);
   determineLargestCollatzSequence();
   std::cout << std::distance(collatzSize, std::max_element(collatzSize, collatzSize + 1000000)) << std::endl;
   return 0;
}

void determineLargestCollatzSequence()
{
   collatzSize[1] = 0;

   for (int i = 2; i < 1000000; ++i)
   {
      long long int temp = i;
      int steps = 0;

      while (temp >= 1000000 || collatzSize[temp] == -1)
      {
         temp = temp % 2 == 0 ? temp / 2 : 3 * temp + 1;
         steps++;
      }

      steps += collatzSize[temp];
      collatzSize[i] = steps;
   }
}