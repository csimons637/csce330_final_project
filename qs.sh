echo 'Cleaning Directory'
make clean
clear
echo 'Compiling Executables'
make all


echo 'Generating Input Files'
./simons_charles_input

echo 'Running QuickSort Algorithm'
./simons_charles_quickSort

echo 'Execution Complete'
echo 'Please Observe Files "simons_charles_executionTime.txt" and "simons_charles_averageExecutionTime.txt" for timing results'