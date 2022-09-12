.default: all

all: Task3output

clean:
	rm -rf task *.o *.dSYM
	
Task3output: Task3.o Utils.o
	g++ -Wall -Werror -pthread -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^