//Author: David Hawkins

#include <iostream>

using namespace std;

#define endl "\n"

int main() {

  int int1, int2, max, temp, iterations;
  
  while(cin >> int1)
  {
    max = 1;
    cin >> int2;
    cout << int1 << " " << int2 << " ";

    if (int1 > int2)
    {
      temp = int1;
      int1 = int2;
      int2 = temp;
    }

    for(int i = int1; i <= int2; i++)
    {
      iterations = 1;
      temp = i;
      while(temp != 1)
      {
        if(temp % 2 == 1)
        {
          temp = 3*temp + 1;
        }
        else
        {
          temp = temp/2;
        }

        iterations++;
      }

      if(iterations > max)
      {
        max = iterations;
      }
    }
    cout << max << endl;
  }

  return 0;
} 