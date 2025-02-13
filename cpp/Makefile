# -MP adds phony target for each dependency
# -MMD generates dependency files (%.d)
CXXFLAGS=-pedantic -Wall -Wextra -g -MMD -MP
CC=$(CXX)

PROGRAMS=programm
OBJECTS=Identity.o People.o Person.o
ALLOBJECTS=$(OBJECTS) $(patsubst %,%.o,$(PROGRAMS))

default: $(PROGRAMS)

programm: $(OBJECTS)

clean:
	rm -f $(ALLOBJECTS) $(ALLOBJECTS:%.o=%.d) $(PROGRAMS)

-include $(ALLOBJECTS:%.o=%.d)
