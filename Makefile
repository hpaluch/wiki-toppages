
CFLAGS  = -Wall -g
LDFLAGS = -g

all: toppages

toppages : toppages.o

toppages.o : toppages.c

clean:
	rm -f toppages toppages.o

