CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 

all: 0811549

delrepeat.o: divide_and_conquer.cpp
	g++ -c divide_and_conquer.cpp
0811549: divide_and_conquer.o
	g++ -o 0811549 divide_and_conquer.o

do:
	./0811549 input.in output.out

diff:
	diff -w output1.out an1 > diff1

check:
	$(CHECKCC) $(CHECKFLAGS) ./0811549 input.in output.out

clean:
	rm -rf *.o 0811549 *.out