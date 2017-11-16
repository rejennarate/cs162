#ifndef SONG_H
#define SONG_H
//Class object for song has title, artist, duration and album name
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//constants
const int MAXCHAR = 101;

//data type for Song
class Song
{
    private:
        char title[MAXCHAR];
        char artist[MAXCHAR];
        int durationMin;
        int durationSec;
        char album[MAXCHAR];
    public:
        //constructors
        //default constructor
        Song();
        //constructor with parameters
        Song(char [], char [], int, int, char []);
        //destructor
        ~Song();
        //mutator functions
        void setTitle(char []);
        void setArtist(char []);
        void setDurationMin(int);
        void setDurationSec(int);
        void setAlbum(char []);
        //accessor functions
        void getTitle(char []) const;
        char getArtist(char []) const;
        int getDurationMin() const;
        int getDurationSec() const;
        char getAlbum(char []) const;
        //print song
        void printSong();
        void printSong(ofstream &);    
};

#endif

