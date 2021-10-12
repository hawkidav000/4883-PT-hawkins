## Assignment 8.1
### UVA Problem 10226: Hardwood Species

#### Overview:
In this problem, my program accepted a series of inputs, and I had to determine if the series of inputs was something called a "Jolly Jumper." In essence, a Jolly Jumper is a series of numbers where the successive differences between them include all numbers from 1 to n-1, where n is the number of inputs in the sequence.

#### Solution:
I solved the problem by first figuring out how to read in all inputs. Once I solved that problem, I moved on to actually processing the data. I calculated the differences between each of the elements in each of the sequences of numbers, and then I ordered those differences using a quick sort (my quick sort code is largely based on code used in this website: https://www.geeksforgeeks.org/cpp-program-for-quicksort/). Once the differences between successive elements were sorted, I compared the sorted vector of differences with an array--that I previously loaded with all values from 1 to 3000, because the program said there would be no numbers larger than 3000--to check and see if there were any differences betweeen that array and my sorted vector of differences. If there were any differences, it was not a Jolly Jumper. Otherwise, the sequence of numbers was Jolly Jumper. Also, one edge case that took account for was receiving a sequence that only had 1 element (which, according to instructions, is considered a Jolly Jumper).

#### Reflection:
I'm really happy with how I solved this problem, because I ended up getting a processing time of 0.000 seconds for my solution, and I'm not usually very good at getting low times. I'm pretty proud of how I solved this one.
