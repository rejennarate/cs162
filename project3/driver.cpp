#include "song.h"
#include "tools.h"

int main()
{
    //create a list of songs.
    char fileName[MAXCHAR] = "songs.txt";
    SongList library(fileName);
    char option;
    do
    {
        displayMenu();
        option = readOption();
        exeCmd(option, library);
    } while(tolower(option != 'q'));
    library.writeData(fileName);

    return 0;
}
