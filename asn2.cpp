//CS3340B      Winter 2021 Assignment 2
//James Walsh jwalsh57    250481718

#include "UandF.h"

int main(int argc, char **argv)
{
  int n = 8;

  UandF uf = UandF(n);
  uf.print();

  for(int i = 1; i <= n; i++)
  {
    uf.make_set(i);
  }
  uf.print();

  uf.union_sets(1, 2);
  uf.print();

  return 0;
}
