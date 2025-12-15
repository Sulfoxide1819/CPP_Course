
CXX ?= g++-14
CXXFLAGS ?= -O2 -I./src
LDFLAGS ?= -lgtest -lgtest_main -pthread

all: bank-system

rebuild: clean all

bank-system: src/bank-system.cpp src/main.cpp
	$(CXX) $(CXXFLAGS) -o bank-system src/bank-system.cpp src/main.cpp

bank-system-tests: tests/bank-system-tests.cpp src/bank-system.cpp
	$(CXX) $(CXXFLAGS) -o bank-system-tests src/bank-system.cpp tests/bank-system-tests.cpp $(LDFLAGS)

test: bank-system-tests
	./bank-system-tests

clean:
	rm bank-system bank-system-tests

rebuild: clean all

.PHONY: all test clean
