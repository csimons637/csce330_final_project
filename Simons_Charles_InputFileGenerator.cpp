
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>
#include <iomanip>

using std::cout;
using std::endl;
using std::ofstream;
using std::fixed;
using std::setprecision;

// generates the random floats between 0.00000 and 999.99999 cast as an integer
float genRandFloat() {
    float max = 501.00000;
    float num = (float(rand()) / float((RAND_MAX)) * max);
    return num;
}

// creates a file and populates it with 10 random floats
void createInputFile_10() {
    ofstream out("./10randomFloats.txt");
    for (int i = 0; i < 10; i++) {
        // generates 10 random floats and writes them to the file
        out << fixed << setprecision(5) << genRandFloat() << " ";
    }
    out.close();
}

// creates a file and populates it with 100 random floats
void createInputFile_100() {
    ofstream out("./100randomFloats.txt");
    for (int i = 0; i < 100; i++) {
        // generates 100 random floats and writes them to the file
        out << fixed << setprecision(5) << genRandFloat() << " ";
    }
    out.close();
}

// creates a file and populates it with 10 random floats
void createInputFile_1000() {
    ofstream out("./1000randomFloats.txt");
    for (int i = 0; i < 1000; i++) {
        // generates 1000 random floats and writes them to the file
        out << fixed << setprecision(5) << genRandFloat() << " ";
    }
    out.close();
}

int main (int arg) {
    createInputFile_10();
    createInputFile_100();
    createInputFile_1000();
}