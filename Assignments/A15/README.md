## Assignment 15: Presentation Problem

### Overview

I found this problem very interesting and fairly challenging as well. 760 involved string processing in a way that required dynamic programming in order to not go over the time limit. Essentially, the problem itself was this: you're given two DNA strands composed of 'a' 'g' 't' and 'c' characters, and your job is to find the greatest common substring(s) shared between the two strands of DNA.

### Solution

I was able to get an accepted solution by using dynamic programming to keep track of what the size of the largest substring was between the two DNA strands. Using this, I simply
traversed both DNA strands looking at substrings of length m (m being the maximum size of substring shared between the two DNA strands).

### Reflection

At the end of my presentation, Dr. Griffin and my classmates pointed out that there may be way to improve the dynamic programming aspect of the program and keep track of the actual
SUBSTRING instead of just the length of the substring. I would like to return to this problem and improve this.
