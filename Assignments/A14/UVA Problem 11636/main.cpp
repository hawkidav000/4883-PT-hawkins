//David Hawkins

#include <iostream>
#include <math.h>

using namespace std;

#define endl "\n"

int main() {

  int temp, temp2;
  int i = 1;
  cin >> temp;
  while(temp > 0)
  {
    //Figured it out! It's all based on powers of 2.
    temp2 = (int)log2(temp);
    if ((int)pow(2.0, (double)temp2) < temp)
    {
      temp2++;
    }
    cout << "Case " << i  << ": " << temp2 << endl;

    i++;
    cin >> temp;
  }

  return 0;
} 