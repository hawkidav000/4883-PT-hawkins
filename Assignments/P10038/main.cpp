// David Hawkins
// UVA Problem 10038
// 4883 - Programming Techniques - Dr. Griffin

#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

void quickSort(vector<int> &diffs, int beg, int end);
int partition(vector<int> &diffs, int beg, int end);
void swap(vector<int> &diffs, int a, int b);

int main() {
  
  int numInts = 0;
  int temp = 0;
  vector<int> jollyJumpers;
  vector<int> differences;
  int correct[3000];
  bool allGood;
  int loopNum;

  for(int i = 0; i < 3000; i++)
  {
    correct[i] = i + 1;
  }

  while(cin >> numInts)
  {
    allGood = true;

    for(int i = 0; i < numInts; i++)
    {
      cin >> temp;
      jollyJumpers.push_back(temp);
    }

    //////////////////////////// DATA PROCESSING ////////////////////////////

    if(jollyJumpers.size() != 1)
    {
      for(int i = 0; i < jollyJumpers.size() - 1; i++)
      {
        differences.push_back(abs(jollyJumpers[i] - jollyJumpers[i + 1]));
      }

      quickSort(differences, 0, differences.size() - 1);

      //Compare differences and correct using a for loop
      for(int i = 0; i < differences.size() && allGood; i++)
      {
        if (differences[i] != correct[i])
        {
          allGood = false;
        }
      }

      //If even one difference is found, it's not a Jolly Jumper
      if (!allGood)
      {
        cout << "Not jolly" << endl;
      }
      //If they are the same element for element it's a Jolly Jumper
      else
      {
        cout << "Jolly" << endl;
      }
    }
    else
    {
      cout << "Jolly" << endl;
    }


    //////////////////////////// END DATA PROCESSING ////////////////////////////

    jollyJumpers.clear();
    differences.clear();
    
  }

  return 0;
}


//My quicksort is largely based on code from this website:
// https://www.geeksforgeeks.org/cpp-program-for-quicksort/
void quickSort(vector<int> &diffs, int beg, int end)
{
  if (beg < end)
  {
    int pi = partition(diffs, beg, end);

    quickSort(diffs, beg, pi - 1);
    quickSort(diffs, pi + 1, end);
  }
}

int partition(vector<int> &diffs, int beg, int end)
{
  int pivot = diffs[end];    // pivot
  int i = (beg - 1);  // Index of smaller element

  for (int j = beg; j <= end - 1; j++)
  {
    // If current element is smaller than or
    // equal to pivot
    if (diffs[j] <= pivot)
    {
      i++;    // increment index of smaller element
      swap(diffs, i, j);
    }
  }
  swap(diffs, i + 1, end);
  return (i + 1);
}

void swap(vector<int> &diffs, int a, int b)
{
  int t = diffs[a];
  diffs[a] = diffs[b];
  diffs[b] = t;
}
