# gcc ./ex1.cpp -I ./include/ -ltvision -lstdc++ -Wl,-Bsymbolic-functions -lncurses -ltinfo -o ex1
#
NCURSES_LIBS=`pkg-config --libs ncurses`
LIBS=$(NCURSES_LIBS) -ltvision -lstdc++

CPP=gcc

all: ex1.o ex2.o
	$(CPP) ex1.o $(LIBS) -Wl,-Bsymbolic-functions -lncurses -ltinfo -o ex1
	$(CPP) ex2.o $(LIBS) -Wl,-Bsymbolic-functions -lncurses -ltinfo -o ex2

clean:
	rm ex1
	rm ex2
	rm *.o

ex1.o: ex1.cpp
	$(CPP) -c ex1.cpp

ex2.o: ex2.cpp
	$(CPP) -c ex2.cpp

