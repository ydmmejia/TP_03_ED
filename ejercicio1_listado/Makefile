CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = listado
OBJS = main.o Estudiante.o ListadoEstudiantil.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp ListadoEstudiantil.h Estudiante.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Estudiante.o: Estudiante.cpp Estudiante.h
	$(CXX) $(CXXFLAGS) -c Estudiante.cpp

ListadoEstudiantil.o: ListadoEstudiantil.cpp ListadoEstudiantil.h Estudiante.h
	$(CXX) $(CXXFLAGS) -c ListadoEstudiantil.cpp

clean:
	rm -f $(OBJS) $(TARGET) listado_estudiantes.txt

run: $(TARGET)
	./$(TARGET)