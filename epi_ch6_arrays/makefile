
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chap_six.o
LOCALOBJS = $(LIBOBJS) main.o

all : ch6_test
.PHONY : all

ch6_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o ch6_test

main.o: main.cc includes/chap_six.h
	$(CXX) $(CFLAGS) main.cc

chap_six.o: includes/chap_six.h chap_six.cc
	$(CXX) $(CFLAGS) chap_six.cc

clean:
	rm -f *.o
	rm -f ch6_test