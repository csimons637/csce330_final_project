# Copyright 2022 Charles Simons
# Written for CSCE 350 - Final Project
cc = g++

flags = -std=c++17
flags += -w
flags += -g

link = $(cc) $(flags) -o
compile = $(cc) $(flags) -c

# executables and text files to be removed
obj = simons_charles_quickSort simons_charles_input 10randomFloats_1.txt 10randomFloats_2.txt 10randomFloats_3.txt 10randomFloats_4.txt 10randomFloats_5.txt 10randomFloats_6.txt 10randomFloats_7.txt 10randomFloats_8.txt 10randomFloats_9.txt 10randomFloats_10.txt 10randomFloats_11.txt 10randomFloats_12.txt 10randomFloats_13.txt 10randomFloats_14.txt 10randomFloats_15.txt 10randomFloats_16.txt 10randomFloats_17.txt 10randomFloats_18.txt 10randomFloats_19.txt 10randomFloats_20.txt 10randomFloats_21.txt 10randomFloats_22.txt 10randomFloats_23.txt 10randomFloats_24.txt 10randomFloats_25.txt 100randomFloats_1.txt 100randomFloats_2.txt 100randomFloats_3.txt 100randomFloats_4.txt 100randomFloats_5.txt 100randomFloats_6.txt 100randomFloats_7.txt 100randomFloats_8.txt 100randomFloats_9.txt 100randomFloats_10.txt 100randomFloats_11.txt 100randomFloats_12.txt 100randomFloats_13.txt 100randomFloats_14.txt 100randomFloats_15.txt 100randomFloats_16.txt 100randomFloats_17.txt 100randomFloats_18.txt 100randomFloats_19.txt 100randomFloats_20.txt 100randomFloats_21.txt 100randomFloats_22.txt 100randomFloats_23.txt 100randomFloats_24.txt 100randomFloats_25.txt 1000randomFloats_1.txt 1000randomFloats_2.txt 1000randomFloats_3.txt 1000randomFloats_4.txt 1000randomFloats_5.txt 1000randomFloats_6.txt 1000randomFloats_7.txt 1000randomFloats_8.txt 1000randomFloats_9.txt 1000randomFloats_10.txt 1000randomFloats_11.txt 1000randomFloats_12.txt 1000randomFloats_13.txt 1000randomFloats_14.txt 1000randomFloats_15.txt 1000randomFloats_16.txt 1000randomFloats_17.txt 1000randomFloats_18.txt 1000randomFloats_19.txt 1000randomFloats_20.txt 1000randomFloats_21.txt 1000randomFloats_22.txt 1000randomFloats_23.txt 1000randomFloats_24.txt 1000randomFloats_25.txt

# makes new quickSort and removes old compiled file
all : simons_charles_input simons_charles_quickSort

# makes compiled quickSort file
simons_charles_quickSort : Simons_Charles_QuickSort.cpp
							$(link) $@ $^ -lrt

simons_charles_input : Simons_Charles_InputFileGenerator.cpp
						$(link) $@ $^ -lrt

# directory clean-up
.PHONY : clean
clean :
		rm $(obj)