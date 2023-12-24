ECHO = @echo
RM = @rm
COMP = @g++
EDL = @g++
CCFLAGS = -Wall -pedantic -ansi -std=c++11 -g #-DMAP
LDFLAGS = 
LIBS =
INT = $(wildcard int/*)
SRC = $(wildcard src/*)
OBJ = $(SRC:src/%.cpp=obj/%.o)
EXE = trajets
EFFACE = clean

$(EXE) : $(OBJ)
	$(ECHO) "EdL de <$(EXE)>"
	$(COMP) -o $(EXE) $(LDFLAGS) $(OBJ) $(LIBS)

obj/main.o : src/main.cpp
	$(ECHO) "Compilation de $(@F)"
	$(COMP) -c src/main.cpp -o obj/main.o $(CCFLAGS)

obj/%.o : src/%.cpp int/%.h
	$(ECHO) "Compilation de $(@F)"
	$(COMP) -c $< -o $@ $(CCFLAGS)

.PHONY : $(EFFACE)
$(EFFACE) :
	$(ECHO) "nettoyage"
	$(RM) -f $(OBJ) $(EXE) core
