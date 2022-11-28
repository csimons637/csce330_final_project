#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>
#include <iomanip>

using namespace std;

const string FILENAME = "./Simons_Charles_executionTime.txt";
const string  FILENAME_AVG = "./Simons_Charles_averageExecutionTime.txt";

// generates the random floats between -500.00000 and 500.00000 cast as an integer
float genRandFloat() {
    float min = -500.00000;
    float max = 500.00000;
    float num = min + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX/(max-min)));
    return num;
}

// creates a file and populates it with 10 random floats
void createInputFile_10() {
    ofstream out;
    for (int j = 0; j < 25; j++) {
        int fileNum = (j + 1);
        string fileName = "./10randomFloats_" + to_string(fileNum) + ".txt";
        out.open(fileName);
        for (int i = 0; i < 10; i++) {
            // generates 10 random floats and writes them to the file
            out << fixed << setprecision(5) << genRandFloat() << " ";
        }
        out.close();
    }
}

// creates a file and populates it with 100 random floats
void createInputFile_100() {
    ofstream out;
    for (int j = 0; j < 25; j++) {
        int fileNum = (j + 1);
        string fileName = "./100randomFloats_" + to_string(fileNum) + ".txt";
        out.open(fileName);
        for (int i = 0; i < 10; i++) {
            // generates 10 random floats and writes them to the file
            out << fixed << setprecision(5) << genRandFloat() << " ";
        }
        out.close();
    }
}

// creates a file and populates it with 10 random floats
void createInputFile_1000() {
    ofstream out;
    for (int j = 0; j < 25; j++) {
        int fileNum = (j + 1);
        string fileName = "./1000randomFloats_" + to_string(fileNum) + ".txt";
        out.open(fileName);
        for (int i = 0; i < 10; i++) {
            // generates 10 random floats and writes them to the file
            out << fixed << setprecision(5) << genRandFloat() << " ";
        }
        out.close();
    }
}

int main () {
    ofstream execTime, avgExecTime;
    execTime.open(FILENAME);
    avgExecTime.open(FILENAME_AVG);

    execTime << "Input Size    Execution Time (ms)" << endl; // writes header
    avgExecTime << "Input Size    Average Execution Time (ms)" << endl; // writes header

    execTime.close();
    avgExecTime.close();
    
    createInputFile_10();
    createInputFile_100();
    createInputFile_1000();
}