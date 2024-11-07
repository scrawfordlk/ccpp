
default: programm

person.o: person.c
	cc -c person person.c

people.o: people.c
	cc -c people people.c

relatives.o: relatives.c
	cc -c relatives relatives.c

programm.o: programm.c
	cc -c programm programm.c

programm: programm.o person.o people.o relatives.o
	cc -o programm programm.o person.o people.o relatives.o

clean:
	rm *.o
