# Folders
SRC = src

# this is the directory I will compile from (i.e. the argument to -I)
IDIR := include

# all object files will be put here
OBJDIR := objdir

# Compiler (g++)
CCC = g++

# Compiling flags
CCFLAGS +=  -Wno-deprecated-declarations -Wall -Wextra -pedantic -std=c++1z -Weffc++ -I$(SFML_ROOT)/include

LDFLAGS += -L$(SFML_ROOT)/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

# file which contains the main function
MAINFILE := main.cpp

# Object modules
OBJECTS =  $(OBJDIR)/main.o  $(OBJDIR)/Game.o  $(OBJDIR)/Game_State.o  $(OBJDIR)/Menu_State.o  $(OBJDIR)/Ball.o 

# Main objetice - created with 'make' or 'make main'.
main: $(OBJECTS) Makefile 
	$(CCC) -I$(IDIR) $(CCFLAGS) -o main $(OBJECTS) $(LDFLAGS)

# Part objectives
$(OBJDIR)/main.o:  $(SRC)/main.cpp dir
	$(CCC) -I$(IDIR) $(CCFLAGS) -c $(SRC)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Game.o: $(SRC)/Game.cpp dir
	$(CCC) -I$(IDIR) $(CCFLAGS) -c $(SRC)/Game.cpp -o $(OBJDIR)/Game.o

$(OBJDIR)/Game_State.o: $(SRC)/Game_State.cpp dir
	$(CCC) -I$(IDIR) $(CCFLAGS) -c $(SRC)/Game_State.cpp -o $(OBJDIR)/Game_State.o

$(OBJDIR)/Menu_State.o: $(SRC)/Menu_State.cpp dir 
	$(CCC) -I$(IDIR) $(CCFLAGS) -c $(SRC)/Menu_State.cpp -o $(OBJDIR)/Menu_State.o

$(OBJDIR)/Ball.o: $(SRC)/Ball.cpp dir
	$(CCC) -I$(IDIR) $(CCFLAGS) -c $(SRC)/Ball.cpp -o $(OBJDIR)/Ball.o

dir:
	@mkdir -p $(OBJDIR)

# 'make clean' removes object files and memory dumps.
clean:
	@ \rm -rf $(OBJDIR)/*.o *.gch core

# 'make zap' also removes the executable and backup files.
zap: clean
	@ \rm -rf main *~
