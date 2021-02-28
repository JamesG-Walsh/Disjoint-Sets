//CS3340B      Winter 2021 Assignment 2
//James Walsh jwalsh57    250481718

#include <iostream>
#include <fstream>

#include "UandF.h"
#include "Node.h"

int main(int argc, char *argv[])
{
  /*int n = 8;

  UandF uf = UandF(n);
  uf.print();

  for(int i = 1; i <= n; i++)
  {
    uf.make_set(i);
  }
  uf.print();

  uf.union_sets(1, 2);
  uf.print();

  uf.union_sets(5, 6);
  uf.print();

  std::cout << "fs6: " << uf.find_set(6) << "\n";

  uf.union_sets(1, 5);
  uf.print();

  uf.union_sets(3, 1);
  uf.print();

  std::cout << "fs6: " << uf.find_set(6) << "\n";
  uf.print();*/

  std::cout << "Numargs: " << argc << "\targ1: " << argv[1] << "\n";

  std::ifstream fin;
  fin.open(argv[1]);
  std::string rowStr;
  std::string::iterator it;
  char c;

  int row = 0;
  int clm = 0;
  int numElements = 0;

  std::vector<std::vector<bool> > twoDBools; //2D vector
  std::vector<Node> oneDNodes;
  //Node node; //passed dummy values here

  while(fin)
  {
    getline(fin, rowStr);
    //std::cout << row << std::endl;
    std::vector<bool> boolRow;
    for (it = rowStr.begin() ; it!=rowStr.end() ; it++)
    {
      c = *it;
      ++clm;
      if (c == '+')
      {
        std::cout << '+';
        boolRow.push_back(true);

        Node node = Node(row, clm, ++numElements);
        oneDNodes.push_back(node);
      }
      else if (c == ' ')
      {
        std::cout << ' ';
        boolRow.push_back(false);
      }
      else
      {
      }
    }
    row++;
    //std::cout << "num rows: " << numRows << "\tnum elements: " << numElements << "\n";
    if(0 < boolRow.size())
    {
      twoDBools.push_back(boolRow);
    }
    std::cout << "\n";
  }
  fin.close();

  std::cout << "num rows: " << twoDBools.size() << "\tnum elements: " << numElements << "\n";

  UandF ufb = UandF(numElements);

  int height = twoDBools.size();
  int width;
  int oneDindex;

  for(oneDindex = 1; oneDindex <= oneDNodes.size(); oneDindex++ )
  {
    ufb.make_set(oneDindex);
  }

  ufb.print();

  for(row = 0 ; row < height ; row++)
  {
    width = twoDBools[row].size();
    std::cout << "\nrow: " << row << "\twidth: " << width;
    for (clm = 0 ; clm < width ; clm++, oneDindex++)
    {
      if(twoDBools[row][clm])
      {
        std::cout << '+';
        //ufb.make_set(oneDindex);
      }
      else
      {
        std::cout << ' ';
      }
    }
  }

  return 0;
}
