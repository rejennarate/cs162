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
        char *title;
        char *artist;
        int durationMin;
        int durationSec;
        char *album;
    public:
        //constructors
        //default constructor
        Song();
        //constructor with parameters
        Song(char [], char [], int, int, char []);
        //copy constructor
        Song(const Song &aSong);
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
        //assignment operator overloading
        const Song& operator= (const Song& aSong);       
};

#endif

