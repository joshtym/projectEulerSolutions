#include <iostream>

long long int getNumOfPathsToBotCorner(int);

int main(int argc, char** argv)
{
   std::cout << getNumOfPathsToBotCorner(20) << std::endl;
   return 0;
}

long long int getNumOfPathsToBotCorner(int size)
{
   long long int paths = 0;
   size++;
   long long int** gridVertices = new long long int*[size];

   for (int i = 0; i < size; ++i)
      gridVertices[i] = new long long int[size];

   for (int i = 0; i < size; ++i)
   {
      for (int j = 0; j < size; ++j)
      {
         bool isPrevColAccessible = j - 1 >= 0;
         bool isPrevRowAccessible = i - 1 >= 0;

         if (isPrevColAccessible && isPrevRowAccessible)
            gridVertices[i][j] = gridVertices[i - 1][j] + gridVertices[i][j - 1];
         else if (isPrevColAccessible)
            gridVertices[i][j] = gridVertices[i][j - 1];
         else if (isPrevRowAccessible)
            gridVertices[i][j] = gridVertices[i - 1][j];
         else
            gridVertices[i][j] = 1;
      }
   }

   paths = gridVertices[size - 1][size - 1];

   for (int i = 0; i < size; ++i)
      delete [] gridVertices[i];
   delete [] gridVertices;

   return paths;
}