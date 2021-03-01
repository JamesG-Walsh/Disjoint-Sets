//CS3340B      Winter 2021 Assignment 2
//James Walsh jwalsh57    250481718

#include <vector>
#include <iostream>
#include <set>
#include <map>

#include "UandF.h"

UandF::UandF(int n)
{
  //parents.resize(n);
  //ranks.resize(n);
  //preFinalParents.resize(n);
  for(int i = 0; i<=n ; i++) //maybe change to 1->n?
  {
    parents.push_back(-1);
    ranks.push_back(-1); //initialize vectors to -1 to indicate that make_set has not been performed yet();
    preFinalParents.push_back(-1);
  }
  setsFinalized = false;
}

void UandF::make_set(int i)
{
  if(!setsFinalized)
  {
    parents[i] = i;
    ranks[i] = 0;
  }
}

void UandF::union_sets(int i, int j)
{
  if(!setsFinalized)
  {
    link(find_set(i), find_set(j));
  }
}

void UandF::link(int i, int j)
{
  if (ranks[i] > ranks[j])
  {
    parents[j] = i;
  }
  else if (ranks[i] < ranks[j])
  {
    parents[i] = j;
  }
  else if (i != j)
  {
    parents[j] = i;
    ranks[i] += 1;
  }
}

int UandF::find_set(int i) //TODO finalization
{
  if(!setsFinalized)
  {
    if (i != parents[i])
    {
      parents[i] = find_set(parents[i]);
    }
    return parents[i];
  }
  else
  {
    return finalMap.at(parents[i]).first;
  }
}

int UandF::final_sets()
{
  int n = parents.size();
  //printf("parents.size(): %d", parents.size());
  for (int i = 1; i < n; i++)
  {
    preFinalParents[i] = find_set(i); //the find_set call here fully compresses every path and stores the result for access after finalization
    finalSets.insert(find_set(i));
  }

  std::set<int, std::less<int> >::iterator setItr;
  std::pair<int, int> p;  //1st is post finalization label, 2nd is count of connected component size

  int label = 1;
  for (setItr = finalSets.begin(); setItr != finalSets.end() ; setItr++, label++)
  {
    p = std::make_pair(label, 0);
    finalMap[*setItr] = p;
  }

  setsFinalized = true;
  return finalSets.size(); //TODO implement
}

void UandF::print()
{
  for (int i = 0 ; i < parents.size() ; i++)
  {
    std::cout << "i: " << i << "\tparent: " << parents[i] << "\trank: " << ranks[i] << "\tset: " << find_set(i) << "\n"; //TODO add findset once implemented
  }
  std::cout << "\n";
}

void UandF::printFinalSets()
{
  /*std::set<int, std::less<int> >::iterator itr;

  for (itr = finalSets.begin(); itr != finalSets.end(); itr++)
  {
    std::cout << *itr << " ";
  }*/
  std::map<int, std::pair<int, int> >::iterator mapItr;
  std::cout << "\nThe finalMap is : \n";
  std::cout << "\tKEY\tELEMENT\tSIZE\n";
  for (mapItr = finalMap.begin(); mapItr != finalMap.end(); ++mapItr)
  {
    std::cout << '\t' << mapItr->first << '\t' << mapItr->second.first << '\t' << mapItr->second.second << '\n';
  }
}

void UandF::incrementComponentSizeCount(int preFinalizationParent)
{
  finalMap[preFinalizationParent].second += 1;
}

int UandF::getPreFinalParent(int i)
{
  int pfp = preFinalParents[i];
  return pfp;
}

void UandF::sortBySizeAndPrint()
{
  std::multimap<int, int> sizeToFMap;
  std::map<int, std::pair<int, int> >::iterator fMapItr;
  int finSetNum;
  int size;
  std::cout << "\nPart 3: The final " << finalMap.size() << " sets/conected components are : \n";
  std::cout << "\tSET #\tCHAR LABEL\tSIZE\n";
  for (fMapItr = finalMap.begin(); fMapItr != finalMap.end(); ++fMapItr)
  {
    size = fMapItr->second.second;
    finSetNum = fMapItr->second.first;
    //sizeToFMap[size] = finSetNum;
    sizeToFMap.insert(std::pair <int, int> (size, finSetNum));

    //std::cout << '\t' << finSetNum << '\t' << label << '\t' << size << '\n';
  }

  int labelInt;
  char label;
  std::map<int, int>::iterator s2lItr;
  for(s2lItr = sizeToFMap.begin(); s2lItr != sizeToFMap.end(); ++s2lItr)
  {
    finSetNum = s2lItr->second;
    labelInt = 64 + finSetNum;
    label = (char)labelInt;
    size = s2lItr->first;
    std::cout << '\t' << finSetNum << '\t' << label << "\t\t" << size << '\n';
  }
}

int UandF::getComponentSize(int i)
{
  int pfp = preFinalParents[i];
  return finalMap[pfp].second;
}
