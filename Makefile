CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g 
LDFLAGS=-g -pthread

SRCS=src/main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: test

test: $(OBJS)
	$(CXX) $(LDFLAGS) -o test $(OBJS)

test.o: main.cpp

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) tool
