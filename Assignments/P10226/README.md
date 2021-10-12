## Assignment 8.1
### UVA Problem 10226: Hardwood Species

#### Overview:
In this problem, my program was supposed to accept a series of test cases. Each of the test cases contained an unspecified number of different strings, and each string was a type of species of tree. Each test case was separated by blank line. My objective was to read each test case into a data structure, find out how many of each species of tree there was, and then calculate what percentage each species of tree contributed to the whole population of trees in the test case.

#### Solution:
I used a c++ standard template library map to solve my problem. Maps are extremely useful because--like a dictionary in Python--they don't allow for duplicate keys. Specifically, the function map::emplace() came in very handy. Whenever I inserted a key into my map, I used the emplace function. When I used the emplace the function, it would return true if the value was not in the map yet, and it would return false if the value was already in the map. If emplace() returned true, I would simply give the key (or treeType as I called it in the program) the value of 1, because it was the first key of that tree species we had seen, and there was only one of its kind (so far). If emplace() returned false, I would simply increment the value associated with that key, because another tree of that species had been read in. Also, each time I read in a value Once the diction

#### Reflection:

