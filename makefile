# Copyright 2022 Charles Simons
# Written for CSCE 350 - Final Project
cc = g++

flags = -std=c++17
# flags += -Wall
flags += -g

link = $(cc) $(flags) -o
compile = $(cc) $(flags) -c

# executables
obj = simons_charles_quickSort simons_charles_input 10randomFloats.txt 100randomFloats.txt 1000randomFloats.txt 10sortedFloats.txt 100sortedFloats.txt 1000sortedFloats.txt

# makes new quickSort and removes old compiled file
all : clean simons_charles_input simons_charles_quickSort

# makes compiled quickSort file
simons_charles_quickSort : Simons_Charles_QuickSort.cpp
							$(link) $@ $^ -lrt

simons_charles_input : Simons_Charles_InputFileGenerator.cpp
						$(link) $@ $^ -lrt

# directory clean-up
.PHONY : clean
clean :
		rm $(obj)