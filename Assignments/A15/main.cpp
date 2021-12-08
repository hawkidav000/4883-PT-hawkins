#include <iostream>
#include <string>
//#include <vector>
#include <map>
#include <fstream>

using namespace std;

string X,Y;
int s;

map<string, int> substrings;


int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( int m, int n ){
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(m-1, n-1);
    else
        return max(lcs(m, n-1), lcs( m-1, n));
}

// Code copied from:
// https://www.geeksforgeeks.org/longest-common-substring-dp-29/
int LCSubStr(int m, int n)
{
    // Create a table to store
    // lengths of longest
    // common suffixes of substrings.  
    // Note that LCSuff[i][j] contains
    // length of longest common suffix
    // of X[0..i-1] and Y[0..j-1].
 
    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
                    // longest common substring
 
    /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}


void LCSS(int len){
  bool equal = true;
  string ss = "";
  substrings.clear();

  for(int i=0;i<=(X.size()-len);i++){
    for(int j=0;j<=(Y.size()-len);j++){
      equal = true;
      ss = "";
      for(int k=0;k<len && equal;k++){// loops len of our substr
        if(X[i + k] == Y[j + k])
        {
          ss += X[i + k];
          if(k == len - 1)
          {
            substrings.insert(pair<string, int>(ss, 0));
          }
        }
        else
        {
          equal = false;
        }
      }
    }
  }
}
 
int main() 
{

  //Used to iterate through our map.
  map<string, int>::iterator it;

  bool check = false;

  while(cin>>X>>Y)
  {

    //Using this to avoid a presentation error
    if(check)
    {
      cout << endl;
    }

    s = LCSubStr(X.size(),Y.size());

    if(s == 0)
    {
      cout << "No common sequence." << endl;
    }
    else
    {

      LCSS(s);

      for (it = substrings.begin(); it != substrings.end(); it++)
      {
        cout << it->first << endl;
      }
    }

    //Do this so that the program will print a return carriage on
    //the next iteration.
    check = true;
  }
  return 0;
}