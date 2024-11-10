CFLAGS=-Wall -g

PROGRAMS=programm
OBJECTS=id.o person.o people.o relatives.o
ALLOBJECTS=$(OBJECTS) $(patsubst %,%.o,$(PROGRAMS))

default: $(PROGRAMS)

$(PROGRAMS): $(ALLOBJECTS)
	$(CC) -o $(PROGRAMS) $(ALLOBJECTS) 

clean:
	rm -f *.o *.d $(ALLOBJECTS) $(PROGRAMS)
