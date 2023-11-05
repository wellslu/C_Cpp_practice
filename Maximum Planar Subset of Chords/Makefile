CC=gcc
LDFLAGS=-std=c11 -O3 -lm
SOURCES=*.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=mps
INCLUDES=*.h

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o:  %.c  ${INCLUDES}
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
