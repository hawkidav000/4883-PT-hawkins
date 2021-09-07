// David Hawkins
// UVA Problem 161
// 4883 Programming Techniques : Dr. Griffin
// 9/7/2021

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {

  int timeSolved;
  int interval = 0;
  int tempContainer = 0;
  bool continueLooping = true;
  bool solutionFound;
  bool lightChange;
  bool notGreen;
  int hours, minutes, seconds;

  vector<int> lightIntervals;
  vector<int> lights;


  while(continueLooping)
  {

    solutionFound = false;
    lightChange = false;

    if (tempContainer != 0)
    {
      //add tempContainer to the vector of intervals
      lightIntervals.push_back(tempContainer);
    }

    cin >> interval;
    
    while(interval != 0)
    {
      //add intervals to a vector of intervals
      lightIntervals.push_back(interval);
      cin >> interval;
    }


    //////////////////////////// DATA PROCESSING ////////////////////////////

    //make the container that holds the status of the lights the same size as the one
    //holding the intervals for the lights and assign all the values.
    lights.resize(lightIntervals.size());
    fill(lights.begin(), lights.end(), 1);

    //Continue to search until we reach 5 hours or until a solution is found
    for(int time = 1; time <= 18000 && !solutionFound; time++)
    {
      for(int i = 0; i < lightIntervals.size(); i++)
      {
        if (lights[i] == 1)
        {
          if (time < lightIntervals[i])
          {
            if((lightIntervals[i] - time) == 5)
            {
              lights[i] = 2;
              
              //used to evaluate later if it's time to start checking for all lights being green
              lightChange = true;
            }
          }
          else
          {
            if ((time % lightIntervals[i]) == (lightIntervals[i] - 5))
            {
              lights[i] = 2;

              //used to evaluate later if it's time to start checking for all lights being green
              lightChange = true;
            }
          }
        }
        else if (lights[i] == 2)
        {
          if (time <= lightIntervals[i])
          {
            if ((time - lightIntervals[i]) == 0)
            {
              lights[i] = 3;
            }
          }
          else
          {
            if ((time % lightIntervals[i]) == 0)
            {
              lights[i] = 3;
            }
          }
        }
        else if (lights[i] == 3)
        {
          if ((time % lightIntervals[i]) == 0)
          {
            lights[i] = 1;
          }
        }
      }

      notGreen = false;
        //Check to see if they're all green!
        if (lightChange)
        {
          for(int j = 0; j < lights.size() && !notGreen; j++)
          {
            if (lights[j] != 1)
            {
              notGreen = true;
            }
          }

          if (!notGreen)
          {
            solutionFound = true;
            timeSolved = time;
          }
        }
    }

    //////////////////////////// END DATA PROCESSING ////////////////////////////

    if(solutionFound)
    {
      hours = timeSolved / 3600;
      minutes = (timeSolved - hours * 3600) / 60;
      seconds = timeSolved - (hours * 3600) - (minutes * 60);

      cout << setw(2) << setfill('0') << hours << ":";
      cout << setw(2) << setfill('0') << minutes << ":";
      cout << setw(2) << setfill('0') << seconds << "\n";
    }
    else
    {
      cout << "Signals fail to synchronise in 5 hours\n";
    }

    //clears the vector to make room for the next set
    lightIntervals.clear();
    lights.clear();

    //checks to see if the next value in the input is a 0. if so, quit the program.
    cin >> interval;
    if (interval == 0)
    {
      continueLooping = false;
    }
    else
    {
      tempContainer = interval;
    }
  }
  
  return 0;
}
