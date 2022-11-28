// Author: Charles I. Simons
// Email: cisimons@email.sc.edu
// Section #: 001
// Copyright 2022 Charles I. Simons

// QuickSort algorithm
// Random pivot value, swapped with the left-most value in the list (Lomuto's partition scheme)
// Record the time taken for completion

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

const char FILENAME[sizeof("./Simons_Charles_executionTime.txt")] = {'.','/','S','i','m','o','n','s','_','C','h','a','r','l','e','s','_','e','x','e','c','u','t','i','o','n','T','i','m','e','.','t','x','t'};
const char FILENAME_AVG[sizeof("./Simons_Charles_averageExecutionTime.txt")] = {'.','/','S','i','m','o','n','s','_','C','h','a','r','l','e','s','_','a','v','e','r','a','g','e','E','x','e','c','u','t','i','o','n','T','i','m','e','.','t','x','t'};

// swaps elements
void swap(float* a, float* b) {
    float t = *a;
    *a = *b;
    *b = t;
}

// partitions the array with Lomuto's scheme
int partition (float arr[], int low, int high) {
    float pivot = arr[high]; // pivot
    int i = (low - 1); // index of smaller element

    for (int j = low; j <= high- 1; j++) {
        // if current <= pivot
        if (arr[j] <= pivot)
        {
        i++; // increment index of smaller element
        swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// sorts the array
void quickSort(float arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// prints the sorted array
void printArray(float arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
    printf("%.5f\n", arr[i]);
    printf("\n");
}

// reads input from file and populates arr
int readInput(const char *file, float *arr) {
    FILE* f = NULL;
    float num;
    f = fopen(file,"r");

    int size = 0;
    while(!feof(f)) {
        fscanf(f, "%f", &num);
        arr[size] = num;
        size++;
    }
    fclose(f);
    return size;
}

// writes the sorted array to the output file
void writeOutput(const char *file, float *arr, int size) {
    FILE* f = NULL;
    f = fopen(file,"w");
    int i;
    for(i = 0; i < size; i++) {
        fprintf(f, "%.2f ", arr[i]);
    }
    fclose(f);
}

// writes the execution times to a file; take a file name, a vector of times and an input count
void writeDuration(const char *file, vector<microseconds> durations, int count) {
    FILE* f = NULL;
    string col1 = to_string(count) + "    ";
    f = fopen(file,"a");
    for (microseconds m : durations) {
        double out = duration<double>(m).count(); // casts the duration as a double for output to the file
        fprintf(f, "%s", col1); // writes the first cell of a row
        fprintf(f, "%g", out); // writes the time
        fprintf(f, "%c", '\n'); // writes a newline after each row
    }
    fclose(f);
}

// writes average execution times for each size of input
void writeAverageDuration(const char *file, vector<microseconds> durations, int count) {
    FILE* f = NULL;
    f = fopen(file,"a");
    string col1 = to_string(count) + "    ";
    double sum = 0.000000000;
    for (microseconds m : durations) {
        double out = duration<double>(m).count(); // casts the duration as a double
        sum += out;
    }
    sum /= (double)count; // computes the mean of the times
    fprintf(f, "%s", col1);
    fprintf(f, "%g", sum);
    fclose(f);
}

int main() {

    FILE* f = NULL;                                     // for overall execution times
    f = fopen(FILENAME,"a");                            // opens the execution time file
    string header = "Input Size    Execution Time\n";   // then
    fprintf(f, "%s", header);                           // writes header for file
    fclose(f);                                          // then the closes file

                                                                    // for average execution times
    f = fopen(FILENAME_AVG,"a");                                    // opens the average execution time file
    string header_avg = "Input Size    Average Execution Time\n";   // then
    fprintf(f, "%s", header_avg);                                   // writes header for file
    fclose(f);                                                      // then the closes file


    vector<microseconds> tenDur;
    vector<microseconds> hunDur;
    vector<microseconds> thouDur;

    // loop for the 10 float inputs
    int i = 1;
    while (i < 26) { // i goes until the max number of files (i.e. 25)
        auto start = high_resolution_clock::now(); // start time

        string file = "./10randomFloats_" + to_string(i) + ".txt";
        char fileNum = (char) i;
        char filename[sizeof(file)] = {'.','/','1','0','r','a','n','d','o','m','F','l','o','a','t','s','_',fileNum,'.','t','x','t'};
        float arr[10]; // declaring an array of size 10 to be sorted
        int n = readInput(filename, arr); // reads file into arr
        quickSort(arr, 0, n-1); // sorts and outputs

        auto stop = high_resolution_clock::now(); // end time
        auto duration = duration_cast<microseconds>(stop - start); // total duration of one sort
        tenDur.push_back(duration); // durations of all 10 float input sorts
        i++;
    }

    // loop for the 100 float inputs
    int j = 1;
    while (j < 26) { // j goes until the max number of files (i.e. 25)
        auto start = high_resolution_clock::now(); // start time

        string file = "./100randomFloats_" + to_string(j) + ".txt";
        char fileNum = (char) j;
        char filename[sizeof(file)] = {'.','/','1','0','0','r','a','n','d','o','m','F','l','o','a','t','s','_',fileNum,'.','t','x','t'};
        float arr[100]; // declaring an array of size 100 to be sorted
        int n = readInput(filename, arr); // reads file into arr
        quickSort(arr, 0, n-1); // sorts and outputs

        auto stop = high_resolution_clock::now(); // end time
        auto duration = duration_cast<microseconds>(stop - start); // total duration of one sort
        hunDur.push_back(duration); // durations of all 100 float input sorts
        j++;
    }

    // loop for the 1000 float inputs
    int k = 1;
    while (k < 26) { // k goes until the max number of files (i.e. 25)
        auto start = high_resolution_clock::now(); // start time

        string file = "./1000randomFloats_" + to_string(k) + ".txt";
        char fileNum = (char) k;
        char filename[sizeof(file)] = {'.','/','1','0','0','0','r','a','n','d','o','m','F','l','o','a','t','s','_',fileNum,'.','t','x','t'};
        float arr[1000]; // declaring an array of size 1000 to be sorted
        int n = readInput(filename, arr); // reads file into arr
        quickSort(arr, 0, n-1); // sorts and outputs

        auto stop = high_resolution_clock::now(); // end time
        auto duration = duration_cast<microseconds>(stop - start); // total duration of one sort
        thouDur.push_back(duration); // durations of all 1000 float input sorts
        k++;
    }

    writeDuration(FILENAME, tenDur, 10);
    writeDuration(FILENAME, hunDur, 100);
    writeDuration(FILENAME, thouDur, 1000);

    writeAverageDuration(FILENAME_AVG, tenDur, 10);
    writeAverageDuration(FILENAME_AVG, hunDur, 100);
    writeAverageDuration(FILENAME_AVG, thouDur, 1000);

    return 0;
}