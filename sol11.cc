#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <cmath>

using pointMap = std::map<std::pair<int, int>, long long int>;

long long int maximumProductOfFourAdjacentValues(std::vector<std::vector<int>>, unsigned int, unsigned int);
pointMap getStartingPointMap(std::vector<std::pair<int, int>>);

long long int naiveMaxProdFourAdj(std::vector<std::vector<int>>, unsigned int, unsigned int);
long long int getMax(long long int, long long int);

int main(int argc, char** argv)
{
   unsigned int rows, columns;
   std::cin >> rows >> columns;
   std::ifstream myFile("prob11.txt");
   std::vector<std::vector<int>> grid;

   if (myFile.is_open())
   {
      for (int i = 0; i < rows; ++i)
      {
         std::vector<int> row;
         for (int j = 0; j < columns; ++j)
         {
            int num;
            myFile >> num;
            row.push_back(num);
         }
         grid.push_back(row);
      }
   }

   std::cout << naiveMaxProdFourAdj(grid, rows, columns) << std::endl;

   return 0;
}


long long int naiveMaxProdFourAdj(std::vector<std::vector<int>> grid, unsigned int rowCount, unsigned int columnCount)
{
   long long int prod = -1;
   int lowIValue, highIValue, lowJValue, highJValue;

   for (unsigned int i = 0; i < rowCount; ++i)
   {
      lowIValue = i - 3;
      highIValue = i + 3;
      for (unsigned int j = 0; j < columnCount; ++j)
      {
         lowJValue = j - 3;
         highJValue = j + 3;

         if (highJValue < columnCount)
         {
            prod = getMax(prod, grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3]);
            if (lowIValue >= 0)
               prod = getMax(prod, grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3]);
            if (highIValue < rowCount)
               prod = getMax(prod, grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3]);
         }

         if (highIValue < rowCount)
         {
            prod = getMax(prod, grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j]);
            if (lowJValue >= 0)
               prod = getMax(prod, grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3]);
         }
      }
   }

   return prod;
}

long long int getMax(long long int a, long long int b)
{
   if (a < b)
      return b;
   return a;
}

// TODO: Come back to this (DP Solution)
// Solution to EULER #11
long long int maximumProductOfFourAdjacentValues(std::vector<std::vector<int>> grid, unsigned int rowCount, unsigned int columnCount)
{
   // Initialize our dp table with default maps and jazz
   std::vector<std::vector<pointMap>> dpTable;
   std::vector<std::pair<int, int>> directions =
   {
      std::make_pair(0,0),
      std::make_pair(0,-1),
      std::make_pair(-1,-1),
      std::make_pair(-1,0),
      std::make_pair(-1,1),
      std::make_pair(0,-2),
      std::make_pair(-2,-2),
      std::make_pair(-2,0),
      std::make_pair(-2,2),
      std::make_pair(0,-3),
      std::make_pair(-3,-3),
      std::make_pair(-3,0),
      std::make_pair(-3,3)
   };

   for (int i = 0; i < rowCount; ++i)
   {
      std::vector<pointMap> rowToPush;
      for (int j = 0; j < columnCount; ++j)
      {
         pointMap startingProductMap = getStartingPointMap(directions);
         startingProductMap[std::make_pair(0, 0)] = grid[i][j];
         rowToPush.push_back(startingProductMap);
      }
      dpTable.push_back(rowToPush);
   }
   
   for (int i = 0; i < rowCount; ++i)
      for (int j = 0; j < columnCount; ++j)
      {
         for (auto& element: directions)
         {
            if (i + element.second < 0 || j + element.first < 0 || (element.first == 0 && element.second == 0))
               continue;

            pointMap mapToExamineForProduct;

            if (std::abs(element.first) > 1 || std::abs(element.second) > 1)
               continue;

            if (element.first == 0 && element.second == -1)
               mapToExamineForProduct = dpTable[i - 1][j];
            else if (element.first == -1 && element.second == -1)
               mapToExamineForProduct = dpTable[i - 1][j - 1];
            else if (element.first == -1 && element.second == 1)
               mapToExamineForProduct = dpTable[i - 1][j + 1];
            else if (element.first == -1 && element.second == 0)
               mapToExamineForProduct = dpTable[i][j - 1];

            dpTable[i][j][element] *= dpTable[i + element.second][j + element.first][std::make_pair(i + element.second, j + element.first)];
         }
      }

      //for (auto i = 0; i < rowCount; ++i)
   
   return -1;
}

pointMap getStartingPointMap(std::vector<std::pair<int, int>> directions)
{
   pointMap startingProductMap;
   for (int i = 0; i < directions.size(); ++i)
         startingProductMap[directions[i]] = 0;
   return startingProductMap;
}