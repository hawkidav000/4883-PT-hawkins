## Assignment 16: Sorting Algorithm Comparison Experiment

### Overview

Essentially, we were asked to take different kinds of data sets and compare run times between different sorting algorithms on those data sets. I found this problem super interesting,
and I really enjoyed doing it.

### Solution

For the scope of the problem, there was just too much coding to not use a function-oriented approach for me. I ended up splitting up what kind of data sets would be used by calling
different functions, and I also split the different sorting algorithms up into functions based on their data type. Every time I wanted to use a different kind of data set, different
size of data set, or a different sorting algorithm, I would go comment out what I was currently using and uncomment command that would invoke the function I wanted. I also tried to keep
everything uniform by having a constant SIZE that the entire program was built upon.

### Issues I Ran Into and Reflection

I quickly learned that Quick Sort is not a stable sorting algorithm! Replit would end up just timing out a lot of the time, and I was also trying to do more work on other algorithms in
Replit, so I came up with a solution: for the larger problem sizes that took much longer to process through, I used my Stampede2 login that I got from Parallel Programming with Dr.
Colmenares and just let Stampede2 handle the larger data sets. That way I could passively be timing those sorting algorithms in Stampede2 while I continued working. I also ran into
issues with Counting Sort, Radix Sort, and Bucket Sort when trying to handle anything other than integers. Counting sort required you to use your elements as indices for your array, so
obviously I couldn't implement Counting Sort with floats or strings. Furthermore, Radix Sort was built using a Counting Sort, so the same issue applied. I faced a similar issue with
trying to get Bucket Sort to handle strings. However, I'll be totally honest, I definitely got a little lazy when trying to process floats with Bucket Sort. I know that it can be done,
but the solution was giving me a headache so I moved on. Overall, I learned a lot from this assignment. I learned about flexibility versus efficiency in different sorting algorithms.
For example, Counting Sort is incredible at handling strings and will probably be superior to most other sorting algorithms in this arena; however, I found that a Heap Sort is 
incredibly dynamic in the types of data that it's able to handle, and it's incredibly scalable to different problem sizes. In this respect, while Counting Sort may have better times for
integers and be more efficient, Heap Sort is much more flexible in the kind of data that it can handle. I've also learned that I just hate QuickSort. You hand it a million sorted
values, and it just breaks. Found it to be one of the least scalable sorting algorithms out there. Also, I found Bucket Sort to be very interesting. I had to play with the values of the
number of buckets and how much each bucket could hold, but I found that it was still a fairly efficient and scalable sorting algorithm under the right circumstances. That was my first
time ever using it, and I thought it was pretty cool. Overall, I really enjoyed this assignment, and I found it super fascinating.

## **NOTE:

When you click on the charts on my Excel spreadsheet, they're set up where if you've selected chart, the labels will show for points when you hover over a specific area. Just wanted to let you know so that you don't have to try and read the tables to understand what's going on.
