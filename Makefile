CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS= -O3
LDFLAGS= -pthread

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
