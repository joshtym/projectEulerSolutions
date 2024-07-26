#include <iostream>
#include <vector>
#include <map>

using pointMap = std::map<std::pair<int, int>, long long int>;

long long int maximumProductOfFourAdjacentValues(std::vector<std::vector<int>>, unsigned int, unsigned int);

int main(int argc, char** argv)
{
   return 0;
}

// Solution to EULER #11
long long int maximumProductOfFourAdjacentValues(std::vector<std::vector<int>> grid, unsigned int rowCount, unsigned int columnCount)
{
   // Initialize our dp table with default maps and jazz
   std::vector<std::vector<pointMap>> dpTable;
   std::vector<std::pair<int, int>> directions;
   pointMap startingProductMap;

   // Might not be valid
   directions.push_back(std::make_pair(0,0));
   directions.push_back(std::make_pair(0,-1));
   directions.push_back(std::make_pair(-1,-1));
   directions.push_back(std::make_pair(-1,0));
   directions.push_back(std::make_pair(-1,1));
   directions.push_back(std::make_pair(0,-2));
   directions.push_back(std::make_pair(-2,-2));
   directions.push_back(std::make_pair(-2,0));
   directions.push_back(std::make_pair(-2,2));
   directions.push_back(std::make_pair(0,-3));
   directions.push_back(std::make_pair(-3,-3));
   directions.push_back(std::make_pair(-3,0));
   directions.push_back(std::make_pair(-3,3));


   for (int i = 0; i < directions.size(); ++i)
      startingProductMap[directions[i]] = 0;

   for (int i = 0; i < rowCount; ++i)
   {
      std::vector<pointMap> rowToPush;
      for (int j = 0; j < columnCount; ++j)
      {
         startingProductMap[std::make_pair(0, 0)] = grid[i][j];
         rowToPush.push_back(startingProductMap);
      }
      dpTable[i].push_back(startingProductMap);
   }
   
   for (int i = 0; i < rowCount; ++i)
      for (int j = 0; j < columnCount; ++j)
      {
         for (auto& element: directions)
         {
            if (i + element.first < 0 || j + element.second < 0 || (element.first == 0 && element.second == 0))
               continue;

            std::map<std::pair<int, int>, long long int> mapToExamineForProduct;

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