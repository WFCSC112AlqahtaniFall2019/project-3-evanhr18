#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
#include <cstdlib>
using namespace std;

// MergeSort function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd);

// BubbleSort function declaration
void swap (int *a, int *b);
void bubbleSort(int *a, int n);

int main(int argc, char* argv[]) {
    // get input: first is random seed, second is vector length
    int seed, length;
    seed = atoi(argv[0]);           // Task 1: change cin input to command line arguments
    length = atoi(argv[1]);
    srand(seed);

    vector<int> v(length); // vector to be sorted
    vector<int> t(length); // temporary workspace

    // define an integer pointer dynamically allocate an array of integers
    int* array = new int[200];

    // Task 3: unit test for swap
    cout << "Testing values *a = 5 and *b = 10 in swap function" << endl;
    int x = 5;
    int y = 10;
    int* a = &x;
    int* b = &y;
    swap(*a, *b);
    if (*a > *b) {
        cout << "*a = " << *a << ", *b = " << *b << endl;
        cout << "Unit test successful." << endl;
    }
    else {
        cout << "*a = " << *a << ", *b = " << *b << endl;
        cout << "UNIT TEST FAILED" << endl;
    }

    // initialize and print input
    cout << "Unsorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // copy the random list of integers from vector to array
    for (int i = 0; i < v.size(); i++) {
        array[i] = v.at(i);
    }

    clock_t start_mergeSort = clock();
    // sort vector using mergeSort
    mergeSort(v,t, 0, v.size() - 1);
    clock_t end_mergeSort = clock();

    // check output, make sure vector is sorted after mergeSort
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    // check output, make sure array is sorted after bubbleSort
    /* your code here */

    clock_t start_bubbleSort = clock();
    // sort array using bubbleSort
    /* your code here */
    clock_t end_bubbleSort = clock();


    // print sorted vector after mergeSort
    cout << "Sorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // print sorted array after bubbleSort
    /* your code here */

    // print elapsed time for mergeSort and bubbleSort
    double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;

    cout << elapsed_mergeSort << " " << elapsed_bubbleSort << endl;

    return 0;
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function
void swap(int *a, int *b) {         // Task 2: wrote swap function

    int temp;

    temp = *b;
    *b = *a;
    *a = temp;

}

// BubbleSort function
void bubbleSort(int *a, int n) {
    /* your code here */
}