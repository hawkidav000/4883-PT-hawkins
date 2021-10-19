//Author: David Hawkins

#include <iostream>

using namespace std;

#define endl "\n"

int main() {
  
  //It's all the fibonacci sequence.

  //I'm going to fill an array with all of the values of
  //the fibonacci sequence up to the 50th one, and that
  //way it won't have to calculate the values each time
  //(only once).
  long long int fib[50];

  //Variable to hold read-in values.
  int n;

  //For loop to fill the array with fibonacci values
  for(int i = 0; i < 50; i++)
  {
    if(i != 0 && i != 1)
    {
      fib[i] = fib[i-1] + fib[i-2];
    }
    else
    {
      if(i == 0)
      {
        fib[i] = 1;
      }
      else
      {
        fib[i] = 2;
      }
    }

  }

  //Print for testing purposes
  // for(int i = 0; i < 50; i++)
  // {
  //   cout << fib[i] << endl;
  // }

  cin >> n;

  while(n != 0)
  {

    cout << fib[n - 1] << endl;

    cin >> n;
  }

  return 0;
}

//Author: David Hawkins
