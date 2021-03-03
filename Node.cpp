//CS3340B      Winter 2021 Assignment 2
//James Walsh jwalsh57    250481718

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

bool Node::isElement()
{
  return isAnElement;
}

int Node::getOneDIndex()
{
  return oneDindex;
}
