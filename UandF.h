//CS3340B      Winter 2021 Assignment 2
//James Walsh jwalsh57    250481718

#ifndef UANDF
#define UANDF

#include <vector>
#include <set>
#include <map>

class UandF
{
  protected:
    std::vector<int> parents;
    std::vector<int> preFinalParents;
    std::vector<int> ranks;
    bool setsFinalized;
    std::set<int, std::less<int> > finalSets;
    std::map<int, std::pair<int, int> > finalMap;

  public:
    UandF(int n);

    void make_set(int i);
    void union_sets(int i, int j);
    void link(int i, int j);
    int find_set(int i);
    int final_sets(); //TODO implement

    void print();
    void printFinalSets();

    void incrementComponentSizeCount(int preFinalizationParent);
    int getPreFinalParent(int i);
    void sortBySizeAndPrint();
};

#endif
