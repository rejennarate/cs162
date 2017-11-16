//This is the implementation file for song.h (the Song class)
#include "song.h"

//default constructor
Song::Song()
{
    //if title exists, then delete then allocate new memory
    if(title)
    {
        delete [] title;
        title = NULL;
    }

    //allocate memory for title
    title = new char[MAXCHAR];
    strcpy(title, "No title");

    //if artist exists, then delete then allocate new memory
    if(artist)
    {
        delete [] artist;
        artist = NULL;
    }

    //allocate memory for artist
    artist = new char[MAXCHAR];
    strcpy(artist, "No artist");
    
    durationMin = 0; 
    durationSec = 0;
    
    //if album exists, then delete then allocate new memory
    if(album)
    {
        delete [] album;
        album = NULL;
    }

    //allocate memory for album
    album = new char[MAXCHAR];
    strcpy(album, "No album");
}

//constructor with parameters
Song::Song(char tempTitle[], char tempArtist[], int tempDurationMin, int tempDurationSec, char tempAlbum[])
{
    //if title exists, then delete then allocate new memory
    if(title)
    {
        delete [] title;
        title = NULL;
    }

    //allocate memory for title
    title = new char[MAXCHAR];
    strcpy(title, tempTitle);

    //if artist exists, then delete then allocate new memory
    if(artist)
    {
        delete [] artist;
        artist = NULL;
    }

    artist = new char[MAXCHAR];
    strcpy(artist, tempArtist);

    durationMin = tempDurationMin;
    durationSec = tempDurationSec;

    //if album exists, then delete then allocate new memory
    if(album)
    {
        delete [] album;
        album = NULL;
    }

    album = new char[MAXCHAR];
    strcpy(album, tempAlbum);
}

//Copy Constructor
Song::Song(const Song &aSong)
{
    title = new char[strlen(aSong.title) + 1];
    artist = new char[strlen(aSong.artist) + 1];
    album = new char[strlen(aSong.album) + 1];
    *this = aSong;
}

//destructor
Song::~Song()
{
    //deallocate memory
    if(title)
    {
        delete [] title;
        title = NULL;
    }

    if(artist)
    {
        delete [] artist;
        artist = NULL;
    }

    if(album)
    {
        delete [] album;
        album = NULL;
    }
}

//mutator functions
void Song::setTitle(char newTitle[])
{
    //if title exists, delete and reallocate just enough for newTitle
    if(title)
    {
        delete [] title;
        title = NULL;
    }
    title = new char[strlen(newTitle)+1];
    strcpy(title, newTitle);
}

void Song::setArtist(char newArtist[])
{
    //if artist exists, delete and reallocate just enough for newArtist
    if(artist)
    {
        delete [] artist;
        artist = NULL;
    }
    artist = new char[strlen(newArtist)+1];
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
    //if album exists, delete and reallocate just enough for newAlbum
    if(album)
    {
        delete [] album;
        album = NULL;
    }
    album = new char[strlen(newAlbum)+1];
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

//assignment operator overloaded
const Song& Song::operator= (const Song& aSong)
{
    //if it is a self copy, don't do anything
    if (this == &aSong)
        return *this;
    //make current object *this a copy of the passed in student
    else
    {
        strncpy(this->title, aSong.title, strlen(aSong.title) + 1);
        strncpy(this->artist, aSong.artist, strlen(aSong.artist) + 1);
        this->durationMin = aSong.durationMin;
        this->durationSec = aSong.durationSec;
        strncpy(this->album, aSong.album, strlen(aSong.album) + 1);

        return *this;
    }
}