
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = user.o user_service.o input_parser.o
LOCALOBJS = $(LIBOBJS) main.o

all : custom_observer
.PHONY : all

custom_observer: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o custom_observer

main.o: main.cc $(INC_DIR)user.h $(INC_DIR)input_parser.h
	$(CXX) $(CFLAGS) main.cc

user.o: $(INC_DIR)user.h user.cc
	$(CXX) $(CFLAGS) user.cc

user_service.o: $(INC_DIR)user.h $(INC_DIR)user_service.h user_service.cc
	$(CXX) $(CFLAGS) user_service.cc

input_parser.o: $(INC_DIR)user.h $(INC_DIR)user_service.h $(INC_DIR)input_parser.h input_parser.cc
	$(CXX) $(CFLAGS) input_parser.cc

clean:
	rm -f *.o
	rm -f custom_observer