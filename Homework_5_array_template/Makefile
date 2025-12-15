CXX ?= g++-14
CXXFLAGS ?= -O2 
LDFLAGS ?=

all: array-template

rebuild: clean all

array-template: array-template.cpp
	$(CXX) $(CXXFLAGS) -o array-template array-template.cpp

test: array-template
	./array-template

clean:
	rm array-template

rebuild: clean all

.PHONY: all test clean
