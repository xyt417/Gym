
dir = Module
src_name = high_precision.cpp

path = $(dir)/$(src_name)
compile: 
	g++ $(path) -o test
	./test
	