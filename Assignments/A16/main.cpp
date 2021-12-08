#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;

#define endl "\n"

// #define NARRAY SIZE   // Array size
// #define NBUCKET 10  // Number of buckets
// #define INTERVAL SIZE/NBUCKET  // Each bucket capacity

//Can't use Replit with sizes any higher than 1048576
const int SIZE = 1048576;

#define NARRAY SIZE   // Array size
#define NBUCKET SIZE/2  // Number of buckets
#define INTERVAL log2(SIZE) * (log2(SIZE) / 2)  // Each bucket capacity

struct NodeInt {
  int data;
  struct NodeInt *next;
};

// struct NodeFloat {
//   float data;
//   struct NodeFloat *next;
// };

//********Integer related functions********//
void integerSort();
void unsortedIntegers(int* val);
void partiallyUnsortedIntegers(int* val);
void reverseSortedIntegers(int* val);
void sortedIntegers(int* val);

//Integer Sorting Algorithm Functions
void quickIntSort(int* arr, int low, int high);
int partitionInt(int* arr, int low, int high);
void swapInt(int *a, int *b);
void countSortInt(int* arr, int size);
int getIntMax(int* arr, int n);
void countingRadixIntSort(int* arr, int size, int place);
void radixSort(int* arr, int size);

void BucketSortInt(int* arr);
struct NodeInt *InsertionSortInt(struct NodeInt *list);
int getBucketIndexInt(int value);
void printInt(int* ar);
void printBucketsInt(struct NodeInt *list);

void heapifyInt(int* arr, int n, int i);
void heapSortInt(int* arr, int n);

//********String related functions********//
void stringSort();
void unsortedStrings(string* arr);
void partiallyUnsortedStrings(string* arr);
void reverseSortedStrings(string* arr);
void sortedStrings(string* arr);


//String Sorting Algorithm Functions
void quickStringSort(string* arr, int low, int high);
int partitionString(string* arr, int low, int high);
void swapString(string *a, string *b);

void heapifyString(string* arr, int n, int i);
void heapSortString(string* arr, int n);

//********Float related functions********//
void floatSort();
void unsortedFloats(float* floats);
void sortedFloats(float* floats);
void partiallySortedFloats(float* floats);
void reverseSortedFloats(float* floats);

//Float Sorting Algorithm Functions
void quickFloatSort(float* arr, int low, int high);
int partitionFloat(float* arr, int low, int high);
void swapFloat(float *a, float *b);

void BucketSortFloat(float* arr);
struct NodeFloat *InsertionSortFloat(struct NodeFloat *list);
int getBucketIndexFloat(int value);
void printFloat(float* ar);
void printBucketsFloat(struct NodeFloat *list);

void heapifyFloat(float* arr, int n, int i);
void heapSortFloat(float* arr, int n);



int main() {

  //Sets the seed to the time of the computer to generate
  //truly random numbers
  srand(time(0));

  //string arr[SIZE];
  
  //integerSort();

  //stringSort();

  floatSort();


  return 0;
} 


//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Integer-Related Functions /////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void integerSort()
{
  //Used to hold random values
  int values[SIZE];

  //These function calls fill my integer array with specific kinds of data.
  //unsortedIntegers(values);
  //partiallyUnsortedIntegers(values);
  //reverseSortedIntegers(values);
  sortedIntegers(values);

  // Print loop for testing.
  // for(int i = 0; i < SIZE; i++)
  // {
  //   cout << values[i] << endl;
  // }

  //cout << endl;

  //Used to time the program.
  clock_t tStart = clock();

  //Call sort functions here.
  //quickIntSort(values, 0, SIZE - 1);
  //countSortInt(values, SIZE);
  //radixSort(values, SIZE);
  //BucketSortInt(values);
  heapSortInt(values, SIZE);

  //cout << "We finished the sort!" << endl;

  cout << "Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;

  // ofstream outfile;
  // outfile.open("test.txt");

  // for(int i = 0; i < SIZE; i++)
  // {
  //   outfile << values[i] << endl;
  // }

  // outfile.close();

  //cout << endl << endl;

  // Print loop for testing.
  // for(int i = 0; i < SIZE; i++)
  // {
  //   cout << values[i] << endl;
  // }

}

void unsortedIntegers(int* val)
{
  for(int i = 0; i < SIZE; i++)
  {
    val[i] = rand() % SIZE + 1;
    //cout << val[i] << "\n";
  }
}

void partiallyUnsortedIntegers(int* val)
{

  int temp, index1, index2;

  //I'm going to start by having a sorted array of integers.
  for(int i = 0; i < SIZE; i++)
  {
    val[i] = i;
  }

  //I will unsort/swap only "50%"" of the values.
  //It also won't truly be 50%, because this algorithm may repeat indeces.
  for(int i = 0; i < SIZE / 2; i++)
  {
    index1 = rand() % SIZE;
    index2 = rand() % SIZE;

    temp = val[index1];
    val[index1] = val[index2];
    val[index2] = temp;
  }
}

void reverseSortedIntegers(int* val)
{
  for(int i = 0; i < SIZE; i++)
  {
    val[i] = SIZE - i;
  }
}

void sortedIntegers(int* val)
{
  for(int i = 0; i < SIZE; i++)
  {
    val[i] = i + 1;
  }
}


//***********************Integer Quicksort Functions***********************//

void quickIntSort(int* arr, int low, int high) 
{
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partitionInt(arr, low, high);

    // recursive call on the left of pivot
    quickIntSort(arr, low, pi - 1);

    // recursive call on the right of pivot
    quickIntSort(arr, pi + 1, high);
  }
}

// function to rearrange array (find the partition point)
int partitionInt(int* arr, int low, int high) 
{
    
  // select the rightmost element as pivot
  int pivot = arr[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swapInt(&arr[i], &arr[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swapInt(&arr[i + 1], &arr[high]);
  
  // return the partition point
  return (i + 1);
}

// function to swap elements
void swapInt(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}

//***********************End Integer QuickSort Functions***********************//

//*****************************************************************************//

//***********************Integer Count Sort Functions***********************//

void countSortInt(int* arr, int size) 
{
  // The size of count must be at least the (max+1) but
  // we cannot assign declare it as int count(max+1) in C++ as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int max = arr[0];

  // Find the largest element of the array
  for (int i = 1; i < size; i++) {
    if (arr[i] > max)
      max = arr[i];
  }

  //cout << max << endl;

  int * output = new int[max+1];
  int * count = new int[max+1];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  //cout << "This is after initializing the arrays with 0's" << endl;

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[arr[i]]++;
  }

  //cout << "This is after storing the count of each element" << endl;

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  //cout << "This is after storing the cummulative count" << endl;

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  //cout << "Ngl, don't know what's happening here, but we made it" << endl;

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    arr[i] = output[i];
  }

  //cout << "Storing everything back where it's supposed to go" << endl;

  delete[] output;
  delete[] count;
}

//***********************End Integer Count Sort Functions***********************//

//*****************************************************************************//

//***********************Integer Radix Sort Functions***********************//

// Function to get the largest element from an array
int getIntMax(int* arr, int n) 
{
  int max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingRadixIntSort(int* arr, int size, int place) 
{
  const int max = 10;
  int* output = new int[size];
  int* count = new int[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(arr[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(arr[i] / place) % 10] - 1] = arr[i];
    count[(arr[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    arr[i] = output[i];

  delete[] output;
  delete[] count;
}

// Main function to implement radix sort
void radixSort(int* arr, int size) 
{
  // Get maximum element
  int max = getIntMax(arr, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingRadixIntSort(arr, size, place);
}

//***********************End Integer Radix Sort Functions***********************//

//*****************************************************************************//

//***********************Integer Bucket Sort Functions***********************//

void BucketSortInt(int* arr) 
{
  int i, j;
  struct NodeInt **buckets;

  // Create buckets and allocate memory size
  buckets = (struct NodeInt **)malloc(sizeof(struct Node *) * NBUCKET);

  // Initialize empty buckets
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = NULL;
  }

  // Fill the buckets with respective elements
  for (i = 0; i < NARRAY; ++i) {
    struct NodeInt *current;
    int pos = getBucketIndexInt(arr[i]);
    current = (struct NodeInt *)malloc(sizeof(struct NodeInt));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  // Print the buckets along with their elements
  // for (i = 0; i < NBUCKET; i++) {
  //   cout << "Bucket[" << i << "] : ";
  //   printBuckets(buckets[i]);
  //   cout << endl;
  // }

  // Sort the elements of each bucket
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = InsertionSortInt(buckets[i]);
  }

  // cout << "-------------" << endl;
  // cout << "Buckets after sorted" << endl;
  // for (i = 0; i < NBUCKET; i++) {
  //   cout << "Bucket[" << i << "] : ";
  //   printBuckets(buckets[i]);
  //   cout << endl;
  // }

  // Put sorted elements on arr
  for (j = 0, i = 0; i < NBUCKET; ++i) {
    struct NodeInt *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  for (i = 0; i < NBUCKET; ++i) {
    struct NodeInt *node;
    node = buckets[i];
    while (node) {
      struct NodeInt *tmp;
      tmp = node;
      node = node->next;
      free(tmp);
    }
  }
  free(buckets);
  return;
}

// Function to sort the elements of each bucket
struct NodeInt *InsertionSortInt(struct NodeInt *list) 
{
  struct NodeInt *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct NodeInt *ptr;
    if (nodeList->data > k->data) {
      struct NodeInt *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct NodeInt *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

int getBucketIndexInt(int value) 
{
  return value / INTERVAL;
}

// Print buckets
void printInt(int* ar) 
{
  int i;
  for (i = 0; i < NARRAY; ++i) {
    cout << setw(3) << ar[i];
  }
  cout << endl;
}

void printBucketsInt(struct NodeInt *list) 
{
  struct NodeInt *cur = list;
  while (cur) {
    cout << setw(3) << cur->data;
    cur = cur->next;
  }
}

//***********************End Integer Bucket Sort Functions***********************//

//*****************************************************************************//

//***********************Integer Heap Sort Functions***********************//

void heapifyInt(int* arr, int n, int i) 
{
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapifyInt(arr, n, largest);
  }
}

// main function to do heap sort
void heapSortInt(int* arr, int n) 
{
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapifyInt(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);

    // Heapify root element to get highest element at root again
    heapifyInt(arr, i, 0);
  }
}

//***********************End Integer Bucket Sort Functions***********************//

//*****************************************************************************//

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// String-Related Functions //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void stringSort()
{
  //In this function, I will call the other sort functions.

  //Temporary read-in variable.
  //string temp;

  string stringValues[SIZE];

  //Fill the array.
  //unsortedStrings(stringValues);
  //partiallyUnsortedStrings(stringValues);
  sortedStrings(stringValues);
  //reverseSortedStrings(stringValues);

  // ifstream infile;
  // ofstream outfile;

  // infile.open("Random_Strings_1048576.txt");
  // outfile.open("string_output.txt");

  // for(int i = 0; i < SIZE; i++)
  // {
  //   infile >> stringValues[i];
  // }

  // for(int i = 0; i < SIZE; i++)
  // {
  //   outfile << stringValues[i] << endl;
  // }

  // outfile << endl;

  //cout << stringValues[SIZE - 1];

  // for(int i = 0; i < SIZE; i++)
  // {
  //   cout << stringValues[i] << endl;
  // }

  

  clock_t tStart = clock();

  //Call sorting functions here
  //quickStringSort(stringValues, 0, SIZE - 1);
  heapSortString(stringValues, SIZE);

  cout << "Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;

  // for(int i = 0; i < SIZE; i++)
  // {
  //   outfile << stringValues[i] << endl;
  // }

  // for(int i = 0; i < SIZE; i++)
  // {
  //   cout << stringValues[i] << endl;
  // }

  // infile.close();
  // outfile.close();
}

void unsortedStrings(string* arr)
{
  ifstream infile;

  infile.open("Random_Strings_1048576.txt");

  for(int i = 0; i < SIZE; i++)
  {
    infile >> arr[i];
  }
}

void partiallyUnsortedStrings(string* arr)
{
  string temp;
  int index1, index2;

  ifstream infile;

  infile.open("sorted_strings.txt");

  //First I will fill the array with sorted values
  for(int i = 0; i < SIZE; i++)
  {
    infile >> arr[i];
  }

  //I will unsort/swap only "50%"" of the values.
  //It also won't truly be 50%, because this algorithm may repeat indeces.
  for(int i = 0; i < SIZE / 2; i++)
  {
    index1 = rand() % SIZE;
    index2 = rand() % SIZE;

    temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
  }
}

void reverseSortedStrings(string* arr)
{
  ifstream infile;

  infile.open("sorted_strings.txt");

  for(int i = 0; i < SIZE; i++)
  {
    infile >> arr[(SIZE - 1) - i];
  }

  //ofstream outfile;

  //outfile.open("string_output.txt");

  // for(int i = 0; i < SIZE; i++)
  // {
  //   outfile << arr[i] << endl;
  // }

  infile.close();
  //outfile.close();
}

void sortedStrings(string* arr)
{
  ifstream infile;

  infile.open("sorted_strings.txt");

  for(int i = 0; i < SIZE; i++)
  {
    infile >> arr[i];
  }

  //ofstream outfile;

  //outfile.open("string_output.txt");

  // for(int i = 0; i < SIZE; i++)
  // {
  //   outfile << arr[i] << endl;
  // }

  infile.close();
  //outfile.close();
}

//***********************String Quicksort Functions***********************//

void quickStringSort(string* arr, int low, int high)
{
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partitionString(arr, low, high);

    // recursive call on the left of pivot
    quickStringSort(arr, low, pi - 1);

    // recursive call on the right of pivot
    quickStringSort(arr, pi + 1, high);
  }
}

int partitionString(string* arr, int low, int high)
{
  // select the rightmost element as pivot
  string pivot = arr[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swapString(&arr[i], &arr[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swapString(&arr[i + 1], &arr[high]);
  
  // return the partition point
  return (i + 1);
}

void swapString(string *a, string *b)
{
  string t = *a;
  *a = *b;
  *b = t;
}

//***********************End String Quicksort Functions***********************//

//*****************************************************************************//

//***********************String Heap Sort Functions***********************//

void heapifyString(string* arr, int n, int i)
{
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapifyString(arr, n, largest);
  }
}

void heapSortString(string* arr, int n)
{
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapifyString(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);

    // Heapify root element to get highest element at root again
    heapifyString(arr, i, 0);
  }
}
//***********************End String Heap Sort Functions***********************//

//*****************************************************************************//

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Float-Related Functions ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void floatSort()
{
  //In this function, I will call the other sort functions.

  float floatValues[SIZE];

  //unsortedFloats(floatValues);
  sortedFloats(floatValues);
  //partiallySortedFloats(floatValues);
  //reverseSortedFloats(floatValues);

  // for(int i = 0; i < SIZE; i++)
  // {
  //   cout << floatValues[i] << endl;
  // }

  clock_t tStart = clock();

  //I'll call sorting algorithms here
  //quickFloatSort(floatValues, 0, SIZE - 1);
  heapSortFloat(floatValues, SIZE);
  //BucketSortFloat(floatValues);

  cout << "Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;

  // ofstream outfile;
  // outfile.open("sorted_floats.txt");

  // for(int i = 0; i < SIZE; i++)
  // {
  //   outfile << floatValues[i] << endl;
  // }

  // for(int i = 0; i < SIZE; i++)
  // {
  //   cout << floatValues[i] << endl;
  // }
}

void unsortedFloats(float* floats)
{
  for(int i = 0; i < SIZE; i++)
  {
    floats[i] = (float)(rand() % SIZE + 1) / (float)(rand() % SIZE + 1);
    //cout << floats[i] << "\n";
  }
}

void sortedFloats(float* floats)
{
  ifstream infile;
  infile.open("sorted_floats.txt");

  for(int i = 0; i < SIZE; i++)
  {
    infile >> floats[i];
    //cout << floats[i] << "\n";
  }

  infile.close();
}

void partiallySortedFloats(float* floats)
{
  float temp;
  int index1, index2;

  //I'm going to start by having a sorted array of integers.
  sortedFloats(floats);

  //I will unsort/swap only "50%"" of the values.
  //It also won't truly be 50%, because this algorithm may repeat indeces.
  for(int i = 0; i < SIZE / 2; i++)
  {
    index1 = rand() % SIZE;
    index2 = rand() % SIZE;

    temp = floats[index1];
    floats[index1] = floats[index2];
    floats[index2] = temp;
  }
}

void reverseSortedFloats(float* floats)
{
  ifstream infile;
  infile.open("sorted_floats.txt");

  for(int i = 0; i < SIZE; i++)
  {
    infile >> floats[(SIZE - 1) - i];
  }

  infile.close();
}

//***********************Float Quicksort Functions***********************//

void quickFloatSort(float* arr, int low, int high)
{
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partitionFloat(arr, low, high);

    // recursive call on the left of pivot
    quickFloatSort(arr, low, pi - 1);

    // recursive call on the right of pivot
    quickFloatSort(arr, pi + 1, high);
  }
}

int partitionFloat(float* arr, int low, int high)
{
  // select the rightmost element as pivot
  float pivot = arr[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swapFloat(&arr[i], &arr[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swapFloat(&arr[i + 1], &arr[high]);
  
  // return the partition point
  return (i + 1);
}

void swapFloat(float *a, float *b)
{
  float t = *a;
  *a = *b;
  *b = t;
}

//***********************End Float Quicksort Functions***********************//

//*****************************************************************************//

//***********************Float Heap Sort Functions***********************//

void heapifyFloat(float* arr, int n, int i)
{
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapifyFloat(arr, n, largest);
  }
}

void heapSortFloat(float* arr, int n)
{
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapifyFloat(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);

    // Heapify root element to get highest element at root again
    heapifyFloat(arr, i, 0);
  }
}

//***********************End Float Heap Sort Functions***********************//

//*****************************************************************************//

//***********************Float Bucket Sort Functions***********************//

// void BucketSortFloat(float* arr) 
// {
//   int i, j;
//   struct NodeFloat **buckets;

//   // Create buckets and allocate memory size
//   buckets = (struct NodeFloat **)malloc(sizeof(struct NodeFloat *) * NBUCKET);

//   // Initialize empty buckets
//   for (i = 0; i < NBUCKET; ++i) {
//     buckets[i] = NULL;
//   }

//   // Fill the buckets with respective elements
//   for (i = 0; i < NARRAY; ++i) {
//     struct NodeFloat *current;
//     int pos = getBucketIndexFloat(arr[i]);
//     current = (struct NodeFloat *)malloc(sizeof(struct NodeFloat));
//     current->data = arr[i];
//     current->next = buckets[pos];
//     buckets[pos] = current;
//   }

//   //Print the buckets along with their elements
//   for (i = 0; i < NBUCKET; i++) {
//     cout << "Bucket[" << i << "] : ";
//     printBucketsFloat(buckets[i]);
//     cout << endl;
//   }

//   // Sort the elements of each bucket
//   for (i = 0; i < NBUCKET; ++i) {
//     buckets[i] = InsertionSortFloat(buckets[i]);
//   }

//   cout << "-------------" << endl;
//   cout << "Buckets after sorted" << endl;
//   for (i = 0; i < NBUCKET; i++) {
//     cout << "Bucket[" << i << "] : ";
//     printBucketsFloat(buckets[i]);
//     cout << endl;
//   }

//   // Put sorted elements on arr
//   for (j = 0, i = 0; i < NBUCKET; ++i) {
//     struct NodeFloat *node;
//     node = buckets[i];
//     while (node) {
//       arr[j++] = node->data;
//       node = node->next;
//     }
//   }

//   for (i = 0; i < NBUCKET; ++i) {
//     struct NodeFloat *node;
//     node = buckets[i];
//     while (node) {
//       struct NodeFloat *tmp;
//       tmp = node;
//       node = node->next;
//       free(tmp);
//     }
//   }
//   free(buckets);
//   return;
// }

// // Function to sort the elements of each bucket
// struct NodeFloat *InsertionSortFloat(struct NodeFloat *list) 
// {
//   struct NodeFloat *k, *nodeList;
//   if (list == 0 || list->next == 0) {
//     return list;
//   }

//   nodeList = list;
//   k = list->next;
//   nodeList->next = 0;
//   while (k != 0) {
//     struct NodeFloat *ptr;
//     if (nodeList->data > k->data) {
//       struct NodeFloat *tmp;
//       tmp = k;
//       k = k->next;
//       tmp->next = nodeList;
//       nodeList = tmp;
//       continue;
//     }

//     for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
//       if (ptr->next->data > k->data)
//         break;
//     }

//     if (ptr->next != 0) {
//       struct NodeFloat *tmp;
//       tmp = k;
//       k = k->next;
//       tmp->next = ptr->next;
//       ptr->next = tmp;
//       continue;
//     } else {
//       ptr->next = k;
//       k = k->next;
//       ptr->next->next = 0;
//       continue;
//     }
//   }
//   return nodeList;
// }

// int getBucketIndexFloat(int value) 
// {
//   return value / INTERVAL;
// }

// // Print buckets
// void printFloat(float* ar) 
// {
//   int i;
//   for (i = 0; i < NARRAY; ++i) {
//     cout << ar[i] << " ";
//   }
//   cout << endl;
// }

// void printBucketsFloat(struct NodeFloat *list) 
// {
//   struct NodeFloat *cur = list;
//   while (cur) {
//     cout << cur->data << " ";
//     cur = cur->next;
//   }
// }

//***********************End Float Bucket Sort Functions***********************//

//*****************************************************************************//