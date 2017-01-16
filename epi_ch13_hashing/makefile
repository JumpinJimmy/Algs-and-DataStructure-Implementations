
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chap_thirteen.o isbn_cache.o
LOCALOBJS = $(LIBOBJS) main.o

all : ch13_test
.PHONY : all

ch13_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o ch13_test

main.o: main.cc includes/chap_thirteen.h includes/isbn_cache.h
	$(CXX) $(CFLAGS) main.cc

chap_thirteen.o: includes/chap_thirteen.h chap_thirteen.cc
	$(CXX) $(CFLAGS) chap_thirteen.cc

isbn_cache.o: includes/isbn_cache.h isbn_cache.cc
	$(CXX) $(CFLAGS) isbn_cache.cc

clean:
	rm -f *.o
	rm -f ch13_test