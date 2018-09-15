CPP = g++ 
CPPFLAGS = -Wall -g -std=c++14


all : Workspace

Map.o : Map.cc Map.h 
	$(CPP) $(CPPFLAGS) -c Map.cc 

Workspace.o : Workspace.cc 
	$(CPP) $(CPPFLAGS) -c Workspace.cc 

Workspace : Map.o Workspace.o
	$(CPP) $(CPPFLAGS) -o Workspace Map.o Workspace.o


.PHONY : clean 
clean : 
	rm -f core *.o *~
