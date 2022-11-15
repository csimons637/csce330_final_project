// C++ implementation QuickSort
// using Lomuto's partition Scheme.
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

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
    float num;
    f = fopen(file,"w");
    int i;
    for(i = 0; i < size; i++) {
        fprintf(f, "%.2f ", arr[i]);
    }
    fclose(f);
}


int main(int argc, char const *argv[]){
    float arr[200]; // declaring an array

    printf("Reading input file...");
    int n = readInput(argv[1], arr);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("Writing to output file...");
    writeOutput(argv[2], arr, n);
    return 0;
}