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
  for(int i = 0; i<=n ; i++) //maybe change to 1->n?
  {
    parents.push_back(-1);
    ranks.push_back(-1); //initialize vectors to -1 to indicate that make_set has not been performed yet();
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
  if (i != parents[i])
  {
    parents[i] = find_set(parents[i]);
  }
  return parents[i];
}

int UandF::final_sets()
{
  int n = parents.size();
  //printf("parents.size(): %d", parents.size());
  for (int i = 1; i < n; i++)
  {
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

  std::map<int, std::pair<int, int> >::iterator mapItr;
  std::cout << "\nThe finalMap is : \n";
  std::cout << "\tKEY\tELEMENT\n";
  for (mapItr = finalMap.begin(); mapItr != finalMap.end(); ++mapItr)
  {
    std::cout << '\t' << mapItr->first << '\t' << mapItr->second.first << '\n';
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
  std::set<int, std::less<int> >::iterator itr;

  for (itr = finalSets.begin(); itr != finalSets.end(); itr++)
  {
    std::cout << *itr << " ";
  }
}
