
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chap_eight.o
LOCALOBJS = $(LIBOBJS) main.o

all : ch8_test
.PHONY : all

ch8_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o ch8_test

main.o: main.cc includes/chap_eight.h
	$(CXX) $(CFLAGS) main.cc

chap_eight.o: includes/linked_list_prototype.h includes/doubly_linked_list_prototype.h includes/chap_eight.h chap_eight.cc
	$(CXX) $(CFLAGS) chap_eight.cc

clean:
	rm -f *.o
	rm -f ch8_test