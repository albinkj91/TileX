# Folders
SRC = src

# this is the directory I will compile from (i.e. the argument to -I)
IDIR := include

# all object files will be put here
OBJDIR := obj

# Compiler (g++)
CCC = g++

# Compiling flags
CCFLAGS +=  -Wno-deprecated-declarations -Wall -Wextra -pedantic -std=c++17 -Weffc++ -I$(SFML_ROOT)/include

LDFLAGS += -L$(SFML_ROOT)/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

# file which contains the main function
MAINFILE := main.cc

# Object modules
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/Tile.o $(OBJDIR)/Image_Loader.o $(OBJDIR)/Grid.o $(OBJDIR)/Scene.o $(OBJDIR)/Large_Tile.o

# Main objetice - created with 'make' or 'make main'.
main: $(OBJECTS) makefile 
	$(CCC) -I$(IDIR) $(CCFLAGS) -o main $(OBJECTS) $(LDFLAGS)

# Part objectives
$(OBJDIR)/main.o:  $(SRC)/main.cc
	$(CCC) -I$(IDIR) $(CCFLAGS) -c $(SRC)/main.cc -o $(OBJDIR)/main.o

$(OBJDIR)/Tile.o: $(SRC)/Tile.cc $(IDIR)/Tile.h
	$(CCC) -I$(IDIR) $(CCFLAGS) -c $(SRC)/Tile.cc -o $(OBJDIR)/Tile.o

$(OBJDIR)/Image_Loader.o: $(SRC)/Image_Loader.cc $(IDIR)/Image_Loader.h
	$(CCC) -I$(IDIR) $(CCFLAGS) -c $(SRC)/Image_Loader.cc -o $(OBJDIR)/Image_Loader.o

$(OBJDIR)/Grid.o: $(SRC)/Grid.cc $(IDIR)/Grid.h
	$(CCC) -I$(IDIR) $(CCFLAGS) -c $(SRC)/Grid.cc -o $(OBJDIR)/Grid.o

$(OBJDIR)/Scene.o: $(SRC)/Scene.cc $(IDIR)/Scene.h
	$(CCC) -I$(IDIR) $(CCFLAGS) -c $(SRC)/Scene.cc -o $(OBJDIR)/Scene.o

$(OBJDIR)/Large_Tile.o: $(SRC)/Large_Tile.cc $(IDIR)/Large_Tile.h
	$(CCC) -I$(IDIR) $(CCFLAGS) -c $(SRC)/Large_Tile.cc -o $(OBJDIR)/Large_Tile.o

# 'make clean' removes object files and memory dumps.
clean:
	@ \rm -rf $(OBJDIR)/*.o *.gch core

# 'make zap' also removes the executable and backup files.
zap: clean
	@ \rm -rf main *~
