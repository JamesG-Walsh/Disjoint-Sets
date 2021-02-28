#include "Node.h"


Node::Node(int r, int c, int i, bool e)
{
  row = r;
  clm = c;

  isAnElement = e;
  if(isAnElement)
  {
    oneDindex = i;
  }
  else //if pixel is a space
  {
    oneDindex = -1; //no 1D index
  }
}
