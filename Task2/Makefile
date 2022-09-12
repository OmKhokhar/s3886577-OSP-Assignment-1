.default: all

all: Task2output

clean:
	rm -rf task *.o *.dSYM
	
Task2output: Task2.o Utils.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^

