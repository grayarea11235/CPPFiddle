# Makefile for CPPFiddle Poco Fun!

COMPILE=g++ -c
LINK=g++

all: poco_json_ex
	@echo "Building..."

clean:
	rm -f *.o
	rm -f poco_json_ex

poco_json_ex: poco_json_ex.o
	$(LINK) poco_json_ex.o -o poco_json_ex -lPocoFoundation -lPocoUtil -lPocoJSON

poco_json.ex.o:
	$(COMPILE) poco_json_ex.c


