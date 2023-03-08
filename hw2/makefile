CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 

all: 0811549

delrepeat.o: FindMaxArray.cpp
	g++ -c FindMaxArray.cpp
0811549: FindMaxArray.o
	g++ -o 0811549 FindMaxArray.o

do:
	./0811549 input_2.in output.out

diff:
	diff -w output1.out an1 > diff1

check:
	$(CHECKCC) $(CHECKFLAGS) ./0811549 input_2.in output.out

clean:
	rm -rf *.o 0811549 *.out