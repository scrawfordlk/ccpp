CXXFLAGS=-pedantic -Wall
CC=$(CXX)

PROGRAMS=programm
OBJECTS=Identity.o People.o Person.o people.o
ALLOBJECTS=$(OBJECTS) $(patsubst %,%.o,$(PROGRAMS))

default: $(PROGRAMS)

$(PROGRAMS): $(ALLOBJECTS)
	$(CXX) -o $(PROGRAMS) $(ALLOBJECTS) 

clean:
	rm -f $(ALLOBJECTS) $(PROGRAMS)
