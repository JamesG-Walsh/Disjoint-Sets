//CS3340B      Winter 2021 Assignment 2
//James Walsh jwalsh57    250481718

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
    bool isAnElement; //left these attributes public for easy access

    Node();
    Node(int r, int c, int i, bool e);

    int getOneDIndex();
    bool isElement();
    void print();
};

#endif
