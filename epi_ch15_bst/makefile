
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chap_fifteen.o
LOCALOBJS = $(LIBOBJS) main.o

all : bst_test
.PHONY : all

bst_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o bst_test

main.o: main.cc $(INC_DIR)chap_fifteen.h
	$(CXX) $(CFLAGS) main.cc

chap_fifteen.o: $(INC_DIR)bst_prototype.h $(INC_DIR)chap_fifteen.h chap_fifteen.cc
	$(CXX) $(CFLAGS) chap_fifteen.cc

clean:
	rm -f *.o
	rm -f bst_test