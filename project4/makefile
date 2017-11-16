CPPFLAGS = -Wall -g -std=c++11

all: song

song: songlist.o song.o tools.o driver.o
		g++ songlist.o song.o tools.o driver.o -o song

songlist.o: songlist.cpp
		g++ -c songlist.cpp
song.o: song.cpp
		g++ -c song.cpp

driver.o: driver.cpp
		g++ -c driver.cpp

tools.o: tools.cpp
		g++ -c tools.cpp

clean:
		rm *.o song