CC=clang++
CCFLAGS=-O3 -DNDEBUG -pedantic -Wall -std=c++11 -I/opt/homebrew/include -L/opt/homebrew/lib

all:		graphs_DIMACS simple_test

graphs_DIMACS:	graphs_DIMACS.cc canonical.h digraph.h util.h openssl_digests.h
		$(CC) -o graphs_DIMACS $(CCFLAGS) graphs_DIMACS.cc -lcrypto

simple_test:	simple_test.cc canonical.h digraph.h util.h
		$(CC) -o simple_test $(CCFLAGS) simple_test.cc

gripper_test:	gripper_test.cc canonical.h digraph.h util.h
		$(CC) -o gripper_test $(CCFLAGS) gripper_test.cc -std=c++11

gripper_test_direct:	gripper_test_direct.cc canonical.h digraph.h util.h
		$(CC) -o gripper_test_direct $(CCFLAGS) gripper_test_direct.cc -std=c++11

clean:
		rm -f graphs_DIMACS simple_test *~

