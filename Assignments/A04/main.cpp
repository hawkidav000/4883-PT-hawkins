/**
* David Hawkins
* 4883 Programming Techniques
* 8/30/2021
* UVA Problem 10055
*/
#include <iostream>

#define endl "\n"

using namespace std;

int main() {
  
    long long int B = 0, A = 0;
    
    while (cin >> A >> B) {
      
      if(B > A)
        cout << B - A << endl;
      else
        cout << A - B << endl;

    }
    return 0;
}
