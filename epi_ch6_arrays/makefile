
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chap_six.o
LOCALOBJS = $(LIBOBJS) main.o

all : chap_six_test
.PHONY : all

chap_six_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o chap_six_test

main.o: main.cc includes/chap_six.h
	$(CXX) $(CFLAGS) main.cc

chap_six.o: includes/chap_six.h chap_six.cc
	$(CXX) $(CFLAGS) chap_six.cc

clean:
	rm -f *.o
	rm -f chap_six_test