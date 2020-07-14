MAKEFLAGS+=--no-builtin-rules --no-builtin-variables

OUTPUT=exe
CXXFLAGS=-O0 -g -Wall -MMD -Wno-unused-function
CXXFLAGS+=-Iinclude
CFLAGS=$(CXXFLAGS)
CC=gcc
CXX=g++

LDLIBS=-lglfw

MAP_SRCPPS=$(wildcard *.cpp)
MAP_OBJS=$(MAP_SRCPPS:.cpp=.o)
OBJS=$(MAP_OBJS)
DEPS=$(OBJS:.o=.d)

.PHONY: all clean

all: $(OUTPUT)

-include $(DEPS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(OUTPUT): $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $^ $(LDLIBS)

clean:
	rm -f $(OBJS) $(OBJS:.o=.d) $(OUTPUT)