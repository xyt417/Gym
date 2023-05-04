
##################################
dir = .
src_name = test.cpp
##################################

path = $(dir)/$(src_name)
compile: 
	g++ $(path) -o test
	./test
	