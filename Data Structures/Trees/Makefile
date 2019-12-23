CC=g++
CFLAGS=-Wall -pedantic -g
INCLUDE=-I./include

binarytree_test: binarytree_test.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o binarytree_test binarytree_test.cpp

bst_test: bst_test.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o bst_test bst_test.cpp

avltree_test: avltree_test.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o avltree_test avltree_test.cpp

.PHONY:clean
clean:
	rm -f *.o binarytree_test bst_test avltree_test