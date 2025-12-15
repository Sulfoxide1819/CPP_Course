
CXX ?= g++-14
CXXFLAGS ?= -O2 
LDFLAGS ?=
MYPROGRAM = str-op

all: $(MYPROGRAM)

rebuild: clean all

$(MYPROGRAM): $(MYPROGRAM).cpp
	$(CXX) $(CXXFLAGS) -o $(MYPROGRAM) $(MYPROGRAM).cpp

clean:
	rm $(MYPROGRAM) 

test: $(MYPROGRAM)
	./$(MYPROGRAM)

.PHONY: all test clean
