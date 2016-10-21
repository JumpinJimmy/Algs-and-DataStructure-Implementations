
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chap_eleven.o
LOCALOBJS = $(LIBOBJS) main.o

all : ch11_test
.PHONY : all

ch11_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o ch11_test

main.o: main.cc includes/chap_eleven.h
	$(CXX) $(CFLAGS) main.cc

chap_eleven.o: includes/chap_eleven.h chap_eleven.cc
	$(CXX) $(CFLAGS) chap_eleven.cc

clean:
	rm -f *.o
	rm -f ch11_test