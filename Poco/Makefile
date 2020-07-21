# Makefile for CPPFiddle Poco Fun!

COMPILE=g++ -c
LINK=g++
LIBS=-lPocoFoundation -lPocoUtil -lPocoJSON
INCLUDEPATH=/mingw64/include
LIBPATH=

all: poco_json_ex poco_build_json_ex
	@echo "Done"

clean:
	rm -f *.o
	rm -f poco_json_ex
	rm -f poco_build_json_ex

poco_json_ex: poco_json_ex.o
	$(LINK) poco_json_ex.o -o poco_json_ex $(LIBS)

poco_build_json_ex: poco_build_json_ex.o
	$(LINK) poco_build_json_ex.o -o poco_build_json_ex $(LIBS)

poco_json.ex.o:
	$(COMPILE) -I$(INCLUDEPATH) poco_json_ex.cpp

poco_build_json_ex.o: 
	$(COMPILE) -I$(INCLUDEPATH) poco_build_json_ex.cpp 

  
