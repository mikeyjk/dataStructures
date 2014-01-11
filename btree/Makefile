# Makefile
# For binary search tree
# Uses google unit test lib
# Author: Michael J. Kiernan

CC=clang++

CFLAGS=-std=c++11 -Wall -Werror -Wuninitialized

# google unit test lib
# this is pretty pedantic, GLIB has to be after best.cpp

GINC=-pthread -isystem ../gtest*/include 
GLIB=../gtest*/libgtest.a

# binary search tree unit test, depending on gunittest
btest: libgtest.a
	$(CC) $(CFLAGS) $(GINC) btest.cpp $(GLIB) -o btest

# parse btree.. I think clang does this implictly, chucks an
# error when done manually
btree:
	$(CC) $(CFLAGS) -c btree.h

# build google unit test
libgtest.a:
	
	cd ../gtest*/; cmake .; make; clang++ -isystem include/ \
	    -I. -pthread -c ./src/gtest-all.cc; \
	    ar -rv libgtest.a gtest-all.o

# remove dll's and binary if made
clean:
	cd ../gtest*/; rm *.o; rm *.a; cd ../btree/; rm btest; 
