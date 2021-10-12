//Author: David Hawkins

#include <iostream>
#include <string>
#include <map>
#include <iomanip>

#define endl "\n"

using namespace std;

int main() {

  //Number of cases.
  int numCases;

  //Stores the tree types and how many there are.
  map<string, int, less<string>> trees;

  //String to read in the trees.
  string treeType = "";

  //Integer to keep track of the total number of trees.
  int treeCount;

  //Iterator used to iterate through map.
  map<string, int>::iterator it;

  //Used to hold information passed back when I call map.emplace().
  //This will tell me if the map already had that value, or if I need to add
  //it to the map. It will also return an iterator to the point on the map
  //where the new (or already previously added key) is located.

  pair<map<string, int>::iterator, bool> emplaceReturn;

  //Read in number of cases.
  cin >> numCases;

  //Use a for loop for the number of test cases.
  for(int i =  0; i < numCases; i++)
  {

    //Reset the data for the next test case.
    treeCount = 0;

    //There is a blank line after the number of test cases.
    if (i == 0)
    {
      getline(cin, treeType);
      getline(cin, treeType);
    }

    //Reset value for treeType
    treeType = "randomvalue";

    //Read until there's a "\n" or until it's the end of the file.
    while(getline(cin, treeType) && treeType != "")
    {

      //Read data into my dictionary inside of the while loop.
      emplaceReturn = trees.emplace(treeType, 1);

      //The map did not previously have a key for this value,
      //so it was just added and emplace returned true.
      if(emplaceReturn.second)
      {

        //Need to set the value of the key equal to 1.
        trees[treeType] = 1;
      }

      //The map already has a value of this key. We will use the
      //treeType to simply increment the value that the key is
      //associated with.
      else
      {
        trees[treeType]++;
      }

      treeCount++;
    }

    //Process data here.

    for (it = trees.begin(); it != trees.end(); it++)
    {
      cout << it->first << ' ' << fixed <<setprecision(4) 
      << (100.0 * double(it->second)) / double(treeCount) << endl;
    }
    if(i < numCases - 1)
      cout << endl;

    //Reset data for next test case.
    trees.clear();
  }

  return 0;
}
