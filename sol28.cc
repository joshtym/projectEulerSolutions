#include <iostream>
#include <vector>

long long int getSumOfDiagonalsForSpiralGrid(int);
std::vector<std::vector<int>> createSpiralGrid(int);

int main(int argc, char** argv)
{
   std::cout << getSumOfDiagonalsForSpiralGrid(1001) << std::endl;
   return 0;
}

long long int getSumOfDiagonalsForSpiralGrid(int rowSize)
{
   long long int sum = 0;
   std::vector<std::vector<int>> spiralGrid = createSpiralGrid(rowSize);

   if (spiralGrid.empty())
      return -1;
   
   for (int i = 0; i < rowSize; ++i)
   {
      sum += spiralGrid[i][i];
      sum += spiralGrid[rowSize - 1 - i][i];
   }

   // Subtract 1 due to the double addition of the middle of the grid
   return sum - 1;
}

std::vector<std::vector<int>> createSpiralGrid(int rowSize)
{
   std::vector<std::vector<int>> grid;
   std::pair<int, int> direction = std::make_pair(0, 0);
   std::pair<int, int> nextDirection = std::make_pair(0, 1);
   int currRow = rowSize / 2;
   int currColumn = rowSize / 2;

   // We can't create a spiral with even rows
   if (rowSize % 2 == 0)
      return grid;

   grid.reserve(rowSize);

   for (int i = 0; i < rowSize; ++i)
   {
      std::vector<int> row;
      row.reserve(rowSize);

      for (int i = 0; i < rowSize; ++i)
         row.push_back(0);
      
      grid.push_back(row);
   }

   grid[currRow][currColumn] = 1;
   // Populate the numbers
   for (int i = 2; i <= rowSize * rowSize; ++i)
   {
      if (grid[currRow + nextDirection.first][currColumn + nextDirection.second] == 0)
      {
         direction.first = nextDirection.first;
         direction.second = nextDirection.second;
         nextDirection.first = direction.first == 0 ? direction.second : 0;
         nextDirection.second = direction.first == 0 ? 0 : (direction.first * -1);
      }

      currRow += direction.first;
      currColumn += direction.second;

      grid[currRow][currColumn] = i;
   }

   return grid;
}