base2: main.o link.o acquireLinks.o node.o list.o
	g++ main.o link.o acquireLinks.o node.o list.o -o base2

base1: main.o link.o functions.o node.o list.o
	g++ main.o link.o functions.o node.o list.o -o base1

main.o: main.cpp
	g++ -c main.cpp -o main.o

link.o: link.cpp link.h
	g++ -c link.cpp -o link.o

functions.o: functions.cpp functions.h
	g++ -c functions.cpp -o functions.o

acquireLinks.o: acquireLinks.cpp functions.h
	g++ -c acquireLinks.cpp -o acquireLinks.o	

node.o: node.cpp node.h
	g++ -c node.cpp -o node.o

list.o: list.cpp list.h
	g++ -c list.cpp -o list.o

clean: 
	rm *.o base1 base2	