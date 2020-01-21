CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS= -O3 -Iinclude
LDFLAGS= -pthread

SRCS=src/main.cpp src/mutex_simple.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: test

test: $(OBJS)
	$(CXX) $(LDFLAGS) -o test $(OBJS)

test.o: $(SRCS)

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) tool
