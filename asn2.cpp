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

  //Node * nodeptr; //not sure why I can't declare this

  std::vector<std::vector<Node> > twoDNodes; //2D vector of Nodes
  std::vector<Node> oneDNodes;
  //Node node; //passed dummy values here

  std::cout << "\nPart 1: Printing the input image...\n";
  while(fin)
  {
    getline(fin, rowStr);
    //std::cout << row << std::endl;
    std::vector<Node> twoDNodeRow;
    for (it = rowStr.begin() ; it!=rowStr.end() ; it++)
    {
      c = *it;
      std::cout << c;
      ++clm;
      if (c == '+')
      {
        Node node = Node(row, clm, ++numElements, true);
        oneDNodes.push_back(node);
        twoDNodeRow.push_back(node);
      }
      else if (c == ' ')
      {
        Node node = Node(row, clm, -1, false);
        twoDNodeRow.push_back(node);
      } //else?
    }
    row++;
    //std::cout << "num rows: " << numRows << "\tnum elements: " << numElements << "\n";
    if(0 < twoDNodeRow.size())
    {
      twoDNodes.push_back(twoDNodeRow);
    }
    std::cout << "\n";
  }
  fin.close();

  int height = twoDNodes.size();
  int width;
  int oneDindex;

  //std::cout << "num rows: " << height << "\tnum elements: " << numElements << "\n";

  UandF ufb = UandF(numElements);

  for(oneDindex = 1; oneDindex <= oneDNodes.size(); oneDindex++ )
  {
    ufb.make_set(oneDindex);
  }
  //ufb.print();

  for(row = 0; row < height ; row++)
  {
    width = twoDNodes[row].size();
    //std::cout << "\nrow: " << row << "\twidth: " << width;
    for (clm = 0 ; clm < width ; clm++)
    {
      if(twoDNodes[row][clm].isElement())
      {
        if(0 < row && twoDNodes[row-1][clm].isElement()) //0 < row here to prevent first row from from trying to access out of bounds
        {
          //printf("\nCalling union_sets() on ((%d,%d), %d) & ((%d,%d),%d)", row, clm, twoDNodes[row][clm].oneDindex, row-1, clm, twoDNodes[row-1][clm].oneDindex);
          ufb.union_sets(twoDNodes[row][clm].getOneDIndex(), twoDNodes[row-1][clm].getOneDIndex());
        }
        if(0 < clm && twoDNodes[row][clm-1].isElement()) //0 < clm here to prevent first column from from trying to access out of bounds
        {
          //printf("\nCalling union_sets() on ((%d,%d), %d) & ((%d,%d),%d)", row, clm, twoDNodes[row][clm].oneDindex, row, clm-1, twoDNodes[row][clm-1].oneDindex);
          ufb.union_sets(twoDNodes[row][clm].getOneDIndex(), twoDNodes[row][clm-1].getOneDIndex());
        }
      }
    }//end of row
  }//end of rows

  //std::cout << "\n";
  //ufb.print();
  /*std::cout << "\nFinal num sets: " << ufb.final_sets() << "\n";
  ufb.printFinalSets();*/
  ufb.final_sets();

  //now print img with unique ASCII chars for each connected component and count the size of each set

  std::cout << "Outputting part 2...\n";
  int asciiInt;
  char asciiChar;
  int fSetIndex;
  int preFinalPar;
  for(row = 0; row < height ; row++)
  {
    width = twoDNodes[row].size();
    for (clm = 0 ; clm < width ; clm++)
    {
      if(twoDNodes[row][clm].isElement())
      {
        oneDindex = twoDNodes[row][clm].getOneDIndex();
        fSetIndex = ufb.find_set(oneDindex);
        asciiInt = 64 + fSetIndex; //start before 'A' and offset by final set label
        asciiChar = (char)asciiInt;
        std::cout << asciiChar;

        preFinalPar = ufb.getPreFinalParent(oneDindex);
        ufb.incrementComponentSizeCount(preFinalPar); //counting the size of each connected component
      }
      else
      {
        std::cout << ' ';
      }
    }//end of row
    std::cout << "\n";
  }//end of rows

  //ufb.printFinalSets();
  ufb.sortBySizeAndPrint(); //part 3

  std::cout << "\nOutputting part 4...\n" ;
  for(row = 0; row < height ; row++)
  {
    width = twoDNodes[row].size();
    for (clm = 0 ; clm < width ; clm++)
    {
      if(twoDNodes[row][clm].isElement())
      {
        oneDindex = twoDNodes[row][clm].getOneDIndex();
        if(3 <= ufb.getComponentSize(oneDindex))
        {
          fSetIndex = ufb.find_set(oneDindex);
          asciiInt = 64 + fSetIndex;
          std::cout << (char)asciiInt;
        }
        else
        {
          std::cout << ' ';  //represents element that has been removed
        }
      }
      else
      {
        std::cout << ' '; //was a space in the original input image
      }
    }//end of row
    std::cout << '\n';
  }//end of rows

  std::cout << "\n\nReturning from main()" << "\n";
  return 0;
}
