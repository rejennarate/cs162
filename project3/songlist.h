#ifndef SONGLIST_H
#define SONGLIST_H
//class object for a list of songs
#include "song.h"

//constants
const int CAP = 100;

//define class SongList for array of songs and size

class SongList
{
    private:
        Song list[CAP];
        int size;
    public:
        //constructors
        SongList();
        SongList(char []);
        //destructor
        ~SongList();
        //database functions
        void writeData(char []);
        void addSong(Song);
        void showList();
        void removeSong();
        void searchByTitle();
        void searchByArtist();
        void searchByAlbum();
};

#endif
