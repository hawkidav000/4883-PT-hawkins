//David Hawkins

#include <iostream>

using namespace std;

#define endl "\n"

int main() {

  int cases, numVals;
  int* arr;
  cin >> cases;

  for (int i = 0; i < cases; i++)
  {
    cin >> numVals;
    arr = new int[numVals];
    for(int j = 0; j < numVals; j++)
    {
      cin >> arr[j];
    }

    cout << "Case " << i + 1 << ": " << arr[(int)(numVals / 2)] << endl;

    delete[] arr;
  }
  return 0;
} 