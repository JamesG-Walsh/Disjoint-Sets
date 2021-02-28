#ifndef NODE
#define NODE

/* class exists to store whether each char is a '+' or a ' '
and to make it possible to translate between 1D and 2D indexes */
class Node
{
  public:
    int row;
    int clm;
    int oneDindex;
    bool isAnElement;

    Node();
    Node(int r, int c, int i, bool e);

    void print();
};

#endif
