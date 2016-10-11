
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chap_nine.o
LOCALOBJS = $(LIBOBJS) main.o

all : ch9_test
.PHONY : all

ch9_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o ch9_test

main.o: main.cc includes/chap_nine.h
	$(CXX) $(CFLAGS) main.cc

chap_nine.o: includes/chap_nine.h chap_nine.cc
	$(CXX) $(CFLAGS) chap_nine.cc

clean:
	rm -f *.o
	rm -f ch9_test