FLAGS = -ansi -pedantic  -Wall -std=c++11 -g -D MAP

Catalogue: main.o Catalogue.o TrajetCompose.o TrajetSimple.o
	g++ -o Catalogue main.o Catalogue.o TrajetCompose.o TrajetSimple.o 

Catalogue.o: Catalogue.cpp Catalogue.h TrajetSimple.h TrajetCompose.h
	g++ -c Catalogue.cpp $(FLAGS)

TrajetSimple.o: Trajet.h  TrajetSimple.h TrajetSimple.cpp
	g++ -c TrajetSimple.cpp $(FLAGS)

TrajetCompose.o: Trajet.h  TrajetCompose.h TrajetCompose.cpp
	g++ -c TrajetCompose.cpp $(FLAGS)

main.o: main.cpp Catalogue.h
	g++ -c main.cpp $(FLAGS)

clean:
	rm *.o Catalogue
