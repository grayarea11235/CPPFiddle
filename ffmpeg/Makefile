#
# Make makefile here!
#

# gcc ./ffmpeg_ex1.c -I/mingw64/include -L/mingw64/lib -lavformat -lavcodec -lavutil -o ffmpeg_ex1

CC=gcc -I/mingw64/include -c
LINK=gcc
LIBS=-L/mingw64/lib -lavformat -lavcodec -lavutil -lswresample


all: ffmpeg_ex1.exe 

clean:
	rm -f *.o
	rm -f ffmpeg_ex1.exe

ffmpeg_ex1.exe: ffmpeg_ex1.o
	$(LINK) ffmpeg_ex1.o $(LIBS) -o ffmeg_ex1.exe

ffmpeg_ex1.o: ffmpeg_ex1.c
	$(CC) ffmpeg_ex1.c
