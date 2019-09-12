
main: main.o document.o recent_list.o library.o
	g++ main.o document.o recent_list.o library.o

main.o: main.cpp
	g++ -c main.cpp

document.o: document.cpp document.h
	g++ -c document.cpp

recent_list.o: recent_list.cpp recent_list.h
	g++ -c recent_list.cpp

library.o: library.cpp library.h
	g++ -c library.cpp

#CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#CFLAGS  = -g -Wall

# the build target executable:
#TARGET = main

#SOURCE = document

#all: $(TARGET)

#$(TARGET): $(TARGET).cpp $(SOURCE).cpp
#$(CC) $(CFLAGS) -o $(TARGET).o $(SOURCE).o $(TARGET).cpp $(SOURCE).cpp

#clean:
#$(RM) $(TARGET) 