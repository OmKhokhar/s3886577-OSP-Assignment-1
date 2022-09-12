.default: all

all: Task1output

clean:
	rm -rf task *.o *.dSYM
	
Task1output: TaskFilter.o Utils.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
