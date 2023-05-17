
##################################
dir = .
src_name = test.cpp
##################################

path = $(dir)/$(src_name)
run: compile
	./test
compile: 
	g++ $(path) -o test
gdb: compile
	gdb ./test
	