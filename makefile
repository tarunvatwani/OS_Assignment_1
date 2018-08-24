CC = g++
CFLAGS = -Wall -std=c++1z
DEPS = lsfunc.h canonical.h noncanonical.h globalvariables.h cursors.h
OBJ = file_explorer.o lsfunc.o canonical.o noncanonical.o cursors.o
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

file_explorer: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
