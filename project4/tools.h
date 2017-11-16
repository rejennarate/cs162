#ifndef TOOLS_H
#define TOOLS_H

#include "song.h"
#include "songlist.h"

//function prototypes
void displayMenu();
char readOption();
void exeCmd(char option, SongList &);
int readInt(char prompt[]);
void addSong(Song &);
void convertCase(char tempStr[]);

#endif
