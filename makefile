COMPILATION = -ansi -pedantic -Wall -std=c++11

#MAP = -DMAP

OBJ = Main.o Catalogue.o Elem.o ListeTrajet.o Trajet.o TrajetSimple.o TrajetCompose.o 

Main: $(OBJ)
	g++ -o trajet $(OBJ)
MainTest.o : Main.cpp
	g++ -c Main.cpp $(COMPILATION)

Catalogue.o : Catalogue.cpp
	g++ -c Catalogue.cpp $(MAP) $(COMPILATION)

Elem.o : Elem.cpp
	g++ -c Elem.cpp $(MAP) $(COMPILATION)

ListeTrajet.o : ListeTrajet.cpp
	g++ -c ListeTrajet.cpp $(MAP) $(COMPILATION)

Trajet.o : Trajet.cpp
	g++ -c Trajet.cpp $(MAP) $(COMPILATION)

TrajetSimple.o : TrajetSimple.cpp
	g++ -c TrajetSimple.cpp $(MAP) $(COMPILATION)

TrajetCompose.o : TrajetCompose.cpp
	g++ -c TrajetCompose.cpp $(MAP) $(COMPILATION)

clean:
	rm -rf *.o trajet
