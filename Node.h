#ifndef NODE
#define NODE

class Node
{
  public:
    int row;
    int clm;
    int oneDindex;

    Node();
    Node(int r, int c, int i);

    void print();
};

#endif
