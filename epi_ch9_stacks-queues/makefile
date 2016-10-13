
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chap_nine.o max_stack.o
LOCALOBJS = $(LIBOBJS) main.o

all : ch9_test
.PHONY : all

ch9_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o ch9_test

main.o: main.cc includes/chap_nine.h includes/max_stack.h
	$(CXX) $(CFLAGS) main.cc

max_stack.o: includes/max_stack.h max_stack.cc
	$(CXX) $(CFLAGS) max_stack.cc

chap_nine.o: includes/bst_node_prototype.h includes/max_stack.h includes/chap_nine.h chap_nine.cc
	$(CXX) $(CFLAGS) chap_nine.cc

clean:
	rm -f *.o
	rm -f ch9_test