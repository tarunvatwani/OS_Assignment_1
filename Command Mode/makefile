CC = g++
CFLAGS = -Wall -std=c++1z
DEPS = readcmd.h globalcmdmode.h noncanonical.h canonical.h cpcmd.h
OBJ = cmdmode.o readcmd.o globalcmdmode.o noncanonical.o canonical.o cpcmd.o
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

cmd_mode: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o cmd_mode
