CC = g++
CFLAGS = -Wall -std=c++1z
DEPS = globalheader.h
OBJ = file_explorer.o lsfunc.o canonical.o noncanonical.o globalheader.o cursors.o enterdirectory.o traversal.o
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

file_explorer: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o file_explorer
