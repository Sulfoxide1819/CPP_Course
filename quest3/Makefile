FC = gfortran
FFLAGS = -O2

EXEC = solver

OBJS = linear_solver.o main.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(FC) -o $@ $^

linear_solver.o: linear_solver.f90
	$(FC) $(FFLAGS) -c $<

main.o: main.f90 linear_solver.mod
	$(FC) $(FFLAGS) -c $<
linear_solver.mod: linear_solver.o

clean:
	rm -f $(EXEC) $(OBJS) *.mod

.PHONY: all clean
