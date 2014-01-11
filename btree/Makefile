# Makefile
# For binary search tree
# Uses google unit test lib
# Author: Michael J. Kiernan

CC=g++

CFLAGS=-std=c++11 -Wall -Werror -Wuninitialized

# google unit test lib
LDFLAGS=-I../gtest*/include/ ../libgtest.a -lpthread

btest:
	$(CC) $(CFLAGS) $(LDFLAGS) btest.cpp -o btest

btree:
	$(CC) $(CFLAGS) -c btree.h
