//CS3340B      Winter 2021 Assignment 2
//James Walsh jwalsh57    250481718

#ifndef UANDF
#define UANDF

#include <vector>

class UandF
{
  protected:
    std::vector<int> parents;
    std::vector<int> ranks;

  public:
    UandF(int n);

    void make_set(int i);
    void union_sets(int i, int j);
    void link(int i, int j);
    int find_set(int i);

    void print();
};

#endif
