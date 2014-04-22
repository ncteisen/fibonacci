#Enables C++11
PATH := /usr/um/gcc-4.7.0/bin:$(PATH)
LD_LIBRARY_PATH := /usr/um/gcc-4.7.0/lib64
LD_RUN_PATH := /usr/um/gcc-4.7.0/lib64

#Default Flags
FLAGS = -Wall -Wextra -pedantic -Wvla -std=c++11

all : fib.cpp
	g++ $(FLAGS) fib.cpp -o fib

# make clean - remove .o files.  You can modify it to remove whatever
clean:
	rm -f *.o fib