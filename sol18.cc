#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

struct Node
{
   Node(int a) : val{a} {}
   int val;
   int maxSumHere = 0;
};

int getMaxSum(std::vector<std::vector<Node>>);

int main(int argc, char** argv)
{
   std::ifstream file;
   std::vector<std::vector<Node>> nodes;
   file.open("prob18.txt");
   int lineNumber = 0;

   while (!file.eof())
   {
      lineNumber++;
      std::vector<Node> nodeLine;
      for (int i = 0; i < lineNumber; ++i)
      {
         int number;
         file >> number;
         nodeLine.push_back(Node(number));
      }
      nodes.push_back(nodeLine);
   }
      
   std::cout << getMaxSum(nodes) << std::endl;

   return 0;
}

int getMaxSum(std::vector<std::vector<Node>> nodes)
{
   for (int i = 0; i < nodes[nodes.size() - 1].size(); ++i)
      nodes[nodes.size() - 1][i].maxSumHere = nodes[nodes.size() - 1][i].val;

   for (int i = nodes.size() - 2; i >= 0; --i)
      for (int j = 0; j < nodes[i].size(); ++j)
         nodes[i][j].maxSumHere = std::max(nodes[i + 1][j].maxSumHere, nodes[i + 1][j + 1].maxSumHere) + nodes[i][j].val;
   
   return nodes[0][0].maxSumHere;
}