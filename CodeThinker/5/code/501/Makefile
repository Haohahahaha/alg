501: IsAnagram.o main.o
	g++ IsAnagram.o main.o -o 501
IsAnagram.o: IsAnagram.cpp IsAnagram.h
	g++ -c IsAnagram.cpp
main: IsAnagram.cpp IsAnagram.h main.cpp
	g++ -c main.cpp 
.PHONY : clean
clean:
	rm 501 main.o IsAnagram.o

