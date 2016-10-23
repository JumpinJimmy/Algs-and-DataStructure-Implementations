
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chap_twelve.o
LOCALOBJS = $(LIBOBJS) main.o

all : ch12_test
.PHONY : all

ch12_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o ch12_test

main.o: main.cc includes/chap_twelve.h
	$(CXX) $(CFLAGS) main.cc

chap_twelve.o: includes/chap_twelve.h chap_twelve.cc
	$(CXX) $(CFLAGS) chap_twelve.cc

clean:
	rm -f *.o
	rm -f ch12_test