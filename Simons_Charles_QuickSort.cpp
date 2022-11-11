// Author: Charles I. Simons
// Email: cisimons@email.sc.edu
// Section #: 001
// Copyright 2022 Charles I. Simons

// QuickSort algorithm
// Random pivot value, swapped with the left-most value in the list
// Record the time taken for completion

#include <iostream>
#include <random>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iterator>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::swap;

// reads the unsorted values from the input file
void readInputFile(string inputFile, vector<float> values) {
    ifstream input;
    input.open(inputFile);
    float num;

    if (!input) {
        cerr << "Error: Input file could not be opened" << endl;
        exit(1);
    }

    while (input) {
        input >> num;
        values.push_back(num);
    }

    input.close();
}

// writes the sorted values to the output file
void writeOutputFile(string outputFile, vector<float> values) {
    ofstream output;
    output.open(outputFile);

    if (!output) {
        cerr << "Error: Output file could not be opened" << endl;
        exit(1);
    }

    for (float f : values) {
        output << f;
        output << " ";
    }

    output.close();
}

// picks a random pivot value
int partition(vector<float> values, int start, int end) {
	int pivot = random() % sizeof(values);
	swap(values[pivot], values[0]); // swaps the two values at 0 and pivot
    return pivot;
}

// QuickSorts the vector at the specified pivot value
void quickSort(vector<float> values, int start, int end) {
	if (start > end)
		return;
	int part = partition(values, start, end);
	
	// sorts from start-of-vector to partition
	quickSort(values, start, part - 1);
	
	// sorts from partition to end-of-vector
	quickSort(values, part + 1, end);
}

void runQuickSort(string inputFile, string outputFile) {
    /*Runs the QuickSort algorithm*/
    vector<float> values;

    cout << "Reading from file..." << endl;
    readInputFile(inputFile, values);

    cout << "Running QuickSort on values..." << endl;
    quickSort(values, 0, values.size());

    cout << "Values sorted..." << endl;
    cout << "Writing to file..." << endl;
    writeOutputFile(outputFile, values);
    exit(0);
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        cout << "Usage: simons_charles_quickSort <input_file> <output_file>" << endl;
    } else {
        runQuickSort(argv[0], argv[1]);
    }
}
