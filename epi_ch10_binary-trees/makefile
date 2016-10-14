
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chap_ten.o
LOCALOBJS = $(LIBOBJS) main.o

all : ch10_test
.PHONY : all

ch10_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o ch10_test

main.o: main.cc includes/chap_ten.h
	$(CXX) $(CFLAGS) main.cc

chap_ten.o: includes/chap_ten.h chap_ten.cc
	$(CXX) $(CFLAGS) chap_ten.cc

clean:
	rm -f *.o
	rm -f ch10_test