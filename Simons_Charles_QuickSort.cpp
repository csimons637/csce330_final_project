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

const string FILENAME = "./Simons_Charles_executionTime.txt";
const string FILENAME_AVG = "./Simons_Charles_averageExecutionTime.txt";

const string FILES_10[25] = {"./10randomFloats_1.txt", "./10randomFloats_2.txt", "./10randomFloats_3.txt", "./10randomFloats_4.txt", "./10randomFloats_5.txt", "./10randomFloats_6.txt", "./10randomFloats_7.txt", "./10randomFloats_8.txt", "./10randomFloats_9.txt", "./10randomFloats_10.txt", "./10randomFloats_11.txt", "./10randomFloats_12.txt", "./10randomFloats_13.txt", "./10randomFloats_14.txt", "./10randomFloats_15.txt", "./10randomFloats_16.txt", "./10randomFloats_17.txt", "./10randomFloats_18.txt", "./10randomFloats_19.txt", "./10randomFloats_20.txt", "./10randomFloats_21.txt", "./10randomFloats_22.txt", "./10randomFloats_23.txt", "./10randomFloats_24.txt", "./10randomFloats_25.txt"};
const string FILES_100[25] = {"./100randomFloats_1.txt", "./100randomFloats_2.txt", "./100randomFloats_3.txt", "./100randomFloats_4.txt", "./100randomFloats_5.txt", "./100randomFloats_6.txt", "./100randomFloats_7.txt", "./100randomFloats_8.txt", "./100randomFloats_9.txt", "./100randomFloats_10.txt", "./100randomFloats_11.txt", "./100randomFloats_12.txt", "./100randomFloats_13.txt", "./100randomFloats_14.txt", "./100randomFloats_15.txt", "./100randomFloats_16.txt", "./100randomFloats_17.txt", "./100randomFloats_18.txt", "./100randomFloats_19.txt", "./100randomFloats_20.txt", "./100randomFloats_21.txt", "./100randomFloats_22.txt", "./100randomFloats_23.txt", "./100randomFloats_24.txt", "./100randomFloats_25.txt"};
const string FILES_1000[25] = {"./1000randomFloats_1.txt", "./1000randomFloats_2.txt", "./1000randomFloats_3.txt", "./1000randomFloats_4.txt", "./1000randomFloats_5.txt", "./1000randomFloats_6.txt", "./1000randomFloats_7.txt", "./1000randomFloats_8.txt", "./1000randomFloats_9.txt", "./1000randomFloats_10.txt", "./1000randomFloats_11.txt", "./1000randomFloats_12.txt", "./1000randomFloats_13.txt", "./1000randomFloats_14.txt", "./1000randomFloats_15.txt", "./1000randomFloats_16.txt", "./1000randomFloats_17.txt", "./1000randomFloats_18.txt", "./1000randomFloats_19.txt", "./1000randomFloats_20.txt", "./1000randomFloats_21.txt", "./1000randomFloats_22.txt", "./1000randomFloats_23.txt", "./1000randomFloats_24.txt", "./1000randomFloats_25.txt"};

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
        // part is the partition index
        int part = partition(arr, low, high);

        // Separately sort elements before and after part
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
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

void write10s(const string files[]) {
    clock_t start, stop; // tracks start and stop times
    double milsec, avgMilsec;

    ofstream execTime, avgExecTime; // output filestreams
    execTime.open(FILENAME, ios::app);
    avgExecTime.open(FILENAME_AVG, ios::app);

    avgMilsec = 0.00;

    for (int i = 0; i <= 25; i++) { // for the 10-input files
        float* arr = new float[1000];
        int f = readInput(files[i].c_str(), arr);
        
        start = clock(); // start timing
        quickSort(arr, 0, 10);
        stop = clock(); // stop timing

        milsec = ((double)(stop - start)) * 1000 / CLOCKS_PER_SEC;

        execTime << 10 << "            " << milsec << endl;
        avgMilsec += milsec;
    }
    avgMilsec /= 25.000;
    avgExecTime << 10 << "            " << avgMilsec << endl;
    execTime.close();
    avgExecTime.close();
}

void write100s(const string files[]) {
    clock_t start, stop; // tracks start and stop times
    double milsec, avgMilsec;

    ofstream execTime, avgExecTime; // output filestreams
    execTime.open(FILENAME, ios::app);
    avgExecTime.open(FILENAME_AVG, ios::app);

    avgMilsec = 0.00;

    for (int i = 0; i <= 25; i++) { // for the 100-input files
        float* arr = new float[1000];
        int f = readInput(files[i].c_str(), arr);
        
        start = clock(); // start timing
        quickSort(arr, 0, 100);
        stop = clock(); // stop timing

        milsec = ((double)(stop - start)) * 1000 / CLOCKS_PER_SEC;

        execTime << 100 << "            " << milsec << endl;
        avgMilsec += milsec;
    }
    avgMilsec /= 25.000;
    avgExecTime << 100 << "            " << avgMilsec << endl;
    execTime.close();
    avgExecTime.close();
}

void write1000s(const string files[]) {
    clock_t start, stop; // tracks start and stop times
    double milsec, avgMilsec;

    ofstream execTime, avgExecTime; // output filestreams
    execTime.open(FILENAME, ios::app);
    avgExecTime.open(FILENAME_AVG, ios::app);

    avgMilsec = 0.00;

    for (int i = 0; i <= 25; i++) { // for the 10-input files
        float* arr = new float[1000];
        int f = readInput(files[i].c_str(), arr);
        
        start = clock(); // start timing
        quickSort(arr, 0, 1000);
        stop = clock(); // stop timing

        milsec = ((double)(stop - start)) * 1000 / CLOCKS_PER_SEC;

        execTime << 1000 << "            " << milsec << endl;
        avgMilsec += milsec;
    }
    avgMilsec /= 25.000;
    avgExecTime << 1000 << "            " << avgMilsec << endl;
    execTime.close();
    avgExecTime.close();
}


int main() {

    write10s(FILES_10); // writes the results of the 10-input files
    write100s(FILES_100); // writes the results of the 100-input files
    write1000s(FILES_1000); // writes the results of the 1000-input files

    return 0;
}
