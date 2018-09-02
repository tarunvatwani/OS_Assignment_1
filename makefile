CC = g++
CFLAGS = -Wall -std=c++1z
DEPS = globalheader.h
OBJ = file_explorer.o lsfunc.o canonical.o noncanonical.o globalheader.o cursors.o enterdirectory.o traversal.o \
		cmdmode.o readcmd.o cpcmd.o create_dir.o create_file.o

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

file_explorer: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o file_explorer
