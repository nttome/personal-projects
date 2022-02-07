 # Make environment Custom Shell Project
CC=gcc
CFLAGS= -Wall -pthread

# Files
OBJECT_FILES= csapp.c shellex.c

# Productions
myShell : $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o myShell

clean :
	rm -v myShell
