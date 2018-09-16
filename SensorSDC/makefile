CPP = g++
CPPFLAGS = -Wall -g -std=c++14


all : Workspace 

Sensor.o : Sensor.h Sensor.cc 
	$(CPP) $(CPPFLAGS) -c Sensor.cc 

Workspace.o : Workspace.cc 
	$(CPP) $(CPPFLAGS) -c Workspace.cc 

Workspace : Workspace.o Sensor.o 
	$(CPP) $(CPPFLAGS) -o Workspace Workspace.o Sensor.o ../MapSDC/Map.o


.PHONY : clean 
clean : 
	rm -f core *.o *~
