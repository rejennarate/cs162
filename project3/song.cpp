//This is the implementation file for song.h (the Song class)
#include "song.h"

//default constructor
Song::Song()
{
    strcpy(title, "No title");
    strcpy(artist, "No artist");
    durationMin = 0;
    durationSec = 0;
    strcpy(album, "No album");
}

//constructor with parameters
Song::Song(char tempTitle[], char tempArtist[], int tempDurationMin, int tempDurationSec, char tempAlbum[])
{
    strcpy(title, tempTitle);
    strcpy(artist, tempArtist);
    durationMin = tempDurationMin;
    durationSec = tempDurationSec;
    strcpy(album, tempAlbum);
}

//destructor
Song::~Song()
{

//nothing to do now
}

//mutator functions
void Song::setTitle(char newTitle[])
{
    strcpy(title, newTitle);
}

void Song::setArtist(char newArtist[])
{
    strcpy(artist, newArtist);
}

void Song::setDurationMin(int newDurationMin)
{
    durationMin = newDurationMin;
}

void Song::setDurationSec(int newDurationSec)
{
    durationSec = newDurationSec;
}

void Song::setAlbum(char newAlbum[])
{
    strcpy(album, newAlbum);
}

//accessor functions
void Song::getTitle(char returnTitle[]) const
{
    strcpy(returnTitle, title);
}

char Song::getArtist(char returnArtist[]) const
{
    strcpy(returnArtist, artist);
}

int Song::getDurationMin() const
{
    return durationMin;
}

int Song::getDurationSec() const
{
    return durationSec;
}

char Song::getAlbum(char returnAlbum[]) const
{
    strcpy(returnAlbum, album);
}

//prints to console
void Song::printSong()
{
    cout << title << " | " << artist << " | " << durationMin << ":" << durationSec << " | ";
    cout << album << endl;
}

//prints to file
void Song::printSong(ofstream &outFile)
{
    cout << title << " | " << artist << " | " << durationMin << ":" << durationSec << " | ";
    cout << album << endl;
} 