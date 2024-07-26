#include <iostream>

long long int getSmallestNumberDivisibleByGroup(int);

int main(int argc, char** argv)
{
   std::cout << getSmallestNumberDivisibleByGroup(20) << std::endl;
   return 0;
}

long long int getSmallestNumberDivisibleByGroup(int upperIncrementalBound)
{
	long long int compareNum = upperIncrementalBound;
	while (true)
	{
		auto divisibleByAll = true;
		for (auto i = upperIncrementalBound; i > 0; --i)
			if (compareNum % i != 0)
			{
				divisibleByAll = false;
            break;
         }
      
      if (divisibleByAll)
         return compareNum;
      else
         compareNum++;
	}
   return -1;
}

// TODO: Add in solution using prime factorization