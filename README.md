# CSCE 330 - Section 001
## Charles Simons
### This is a QuickSort algorithm implemented in C++

### File Descriptions
#### *QuickSort.cpp
      Takes the input and output filenames as command line arguments
      Sorts the values from the input files
      Values are stored in a vector<float> for ease-of-use
      Writes the sorted values to the output files
#### *InputFileGenerator.cpp
      Creates three files for use by *QuickSort.cpp (one file for 10 floats, 100 floats and 1000 floats)
#### makefile
      Makes the executables and cleans up the directory

### Compilation
#### *input
      Run the command 'make simons_charles_input' to generate the executable for *InputFileGenerator.cpp
#### *quickSort
      Run the command 'make simons_charles_quickSort' to generate the executable for *QuickSort.cpp
#### all
      Alternatively, run the command 'make all' to generate both executables at once

### Execution
#### Step 1 - Run simons_charles_input first, to generate the required input files for sorting (no command-line arguments are required)
#### Step 2 - Next, run simons_charles_quickSort (again, no command-line arguments are required)

### Cleanup
#### make clean
      To remove all executables and input/outputfiles, run the command 'make clean'