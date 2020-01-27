CC=g++
CFLAGS=-Wall -pedantic -g
INCLUDE=-I./include 

queue_test: queue_test.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o queue_test queue_test.cpp

.PHONY: clean
clean:
	rm -f queue_test *.o