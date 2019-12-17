CC=g++
CFLAGS=-Wall -pedantic -g
INCLUDE=-I./include 

stack_test: stack_test.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o stack_test stack_test.cpp

.PHONY: clean
clean:
	rm -f stack_test *.o