502: Intersec.o main.o
	g++ Intersec.o main.o -o 502
Intersec.o: Intersec.cpp Intersec.h
	g++ -c Intersec.cpp
main.o: Intersec.cpp Intersec.h main.cpp
	g++ -c -o main.o main.cpp
.PHONY: clean
clean:
	rm 502 main.o Intersec.o
