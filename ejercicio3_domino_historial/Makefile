CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = domino
OBJS = main.o Ficha.o Jugador.o Movimiento.o JuegoDomino.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp JuegoDomino.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Ficha.o: Ficha.cpp Ficha.h
	$(CXX) $(CXXFLAGS) -c Ficha.cpp

Jugador.o: Jugador.cpp Jugador.h Ficha.h
	$(CXX) $(CXXFLAGS) -c Jugador.cpp

Movimiento.o: Movimiento.cpp Movimiento.h Ficha.h
	$(CXX) $(CXXFLAGS) -c Movimiento.cpp

JuegoDomino.o: JuegoDomino.cpp JuegoDomino.h Ficha.h Jugador.h Movimiento.h
	$(CXX) $(CXXFLAGS) -c JuegoDomino.cpp

clean:
	rm -f $(OBJS) $(TARGET) historial_domino.txt

run: $(TARGET)
	./$(TARGET)