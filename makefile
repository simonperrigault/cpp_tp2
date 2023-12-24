ECHO = @echo
RM = @rm
COMP = @g++
EDL = @g++
CCFLAGS = -Wall -pedantic -ansi -std=c++11 -g #-DMAP
LDFLAGS = 
LIBS =
INT = $(wildcard *.h)
SRC = main.cpp $(INT:.h=.cpp)
OBJ = $(SRC:.cpp=.o)
EXE = trajets
EFFACE = clean

$(EXE) : $(OBJ)
	$(ECHO) "EdL de <$(EXE)>"
	$(COMP) -o $(EXE) $(LDFLAGS) $(OBJ) $(LIBS)

main.o : main.cpp
	$(ECHO) "Compilation de $<"
	$(COMP) -c main.cpp $(CCFLAGS)

Catalogue.o : Catalogue.cpp Catalogue.h
	$(ECHO) "Compilation de $<"
	$(COMP) -c $< $(CCFLAGS)

Trajet.o : Trajet.cpp Trajet.h
	$(ECHO) "Compilation de $<"
	$(COMP) -c $< $(CCFLAGS)

TrajetSimple.o : TrajetSimple.cpp TrajetSimple.h
	$(ECHO) "Compilation de $<"
	$(COMP) -c $< $(CCFLAGS)

TrajetCompose.o : TrajetCompose.cpp TrajetCompose.h
	$(ECHO) "Compilation de $<"
	$(COMP) -c $< $(CCFLAGS)

TableauTrajets.o : TableauTrajets.cpp TableauTrajets.h
	$(ECHO) "Compilation de $<"
	$(COMP) -c $< $(CCFLAGS)

DFS.o : DFS.cpp DFS.h
	$(ECHO) "Compilation de $<"
	$(COMP) -c $< $(CCFLAGS)

.PHONY : $(EFFACE)
$(EFFACE) :
	$(ECHO) "nettoyage"
	$(RM) -f $(OBJ) $(EXE) core