
CXX ?= g++-14
CXXFLAGS ?= -O2 
LDFLAGS ?=

all: bank-system

rebuild: clean all

bank-system: bank-system.cpp
	$(CXX) $(CXXFLAGS) -o bank-system bank-system.cpp

clean:
	rm bank-system 

test: bank-system
	./bank-system

.PHONY: all test clean
