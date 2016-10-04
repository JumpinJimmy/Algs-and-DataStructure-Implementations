
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chap_seven.o
LOCALOBJS = $(LIBOBJS) main.o

all : ch7_test
.PHONY : all

ch7_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o ch7_test

main.o: main.cc includes/chap_seven.h
	$(CXX) $(CFLAGS) main.cc

chap_seven.o: includes/chap_seven.h chap_seven.cc
	$(CXX) $(CFLAGS) chap_seven.cc

clean:
	rm -f *.o
	rm -f ch7_test