## Assignment 10.1
### UVA Problem 900: Brick Wall Patterns

#### Overview:
Essentially, instead of describing the problem, I'm just going to talk about what it was: it was just the fibonacci sequence. We had to make a program that could
generate the fibonacci sequence. We would receive inputs from a file, and each number would be a position of a number in the fibonacci sequence. We had to print out
the fibonacci number associated with that index.

#### Solution:
Our program had to be able to handle large numbers resulting from the fibonacci sequence, and (to be efficient) it needed to avoid costly calculations that would slow
it down. I created an array that had preloaded the values of the fibonacci sequence, and then every number I read in had a O(1) lookup time for the associated fibonacci
number.

#### Reflection:
I was pretty happy that I got 0.000 time. I know it was an easy problem, but it still feels good to have solved that.
