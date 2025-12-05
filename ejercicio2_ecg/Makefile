CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = ecg
OBJS = main.o SenalECG.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp SenalECG.h
	$(CXX) $(CXXFLAGS) -c main.cpp

SenalECG.o: SenalECG.cpp SenalECG.h
	$(CXX) $(CXXFLAGS) -c SenalECG.cpp

clean:
	rm -f $(OBJS) $(TARGET) senal_procesada.txt

run: $(TARGET)
	./$(TARGET)