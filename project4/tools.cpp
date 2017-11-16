//This is the implementation file for tools.h
#include "tools.h"
#include "song.h"
//Function implementations


//displays the menu
void displayMenu()
{
    cout << "Welcome to your song library:" << endl << endl;
    cout << "Pick an option" << endl;
    cout << "[D-d]: Display all songs" << endl;
    cout << "[A-a]: Search by Artist" << endl;
    cout << "[M-m]: Search by Album" << endl;
    cout << "[E-e]: Enter in a new song" << endl;
    cout << "[R-r]: Remove a song" << endl;
    cout << "[Q-q]: Quit" << endl;
}

// read the option from the user
char readOption()
{
    char input;
    cin >> input;
    cin.ignore(100, '\n');
    return input;
}

void exeCmd(char option, SongList &library)
{
    Song aSong;
    switch (tolower(option))
    {
    case 'e':
        addSong(aSong);
        library.addSong(aSong);
        break;
    case 'd':
        library.showList();
        break;
    case 'r':
        library.showList();
        library.removeSong();
        break;
    case 'a':
        library.searchByArtist();
        break;
    case 'm':
        library.searchByAlbum();
        break;
    case 'q':
        break;
    default:
        cout << "Invalid input, please try again!!" << endl;
    }
}

//Name: readInt (reads and validates an integer)
//input: none
//output: error message
//return: int
int readInt(char prompt[])
{
    int temp = 0;
    cout << prompt;
    cin >> temp;
    //data validation
    while (!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input!! Please try again!!";
        cin >> temp;
    }
    cin.ignore(100, '\n');

    return temp;
}

//add song to library
void addSong(Song &aSong)
{
    char letter;
    char tempTitle[MAXCHAR];
    char tempArtist[MAXCHAR];
    int tempDurationMin = 0;
    int tempDurationSec = 0;
    char tempAlbum[MAXCHAR];

    cout << "Enter a song name:";
    cin.get(tempTitle, MAXCHAR, '\n');
    cin.ignore(MAXCHAR, '\n');
    cout << "Enter an artist: ";
    cin.get(tempArtist, MAXCHAR, '\n');
    cin.ignore(MAXCHAR,'\n'); 
    tempDurationMin = readInt("Enter minutes portion of song duration: ");
    tempDurationSec = readInt("Enter seconds portion of song duration: ");
    cout << "Enter the album name: ";
    cin.get(tempAlbum, MAXCHAR, '\n');
    // cin.ignore(MAXCHAR,'\n'); 

    //populate aSong calling the mutator functions
    aSong.setTitle(tempTitle);
    aSong.setArtist(tempArtist);
    aSong.setDurationMin(tempDurationMin);
    aSong.setDurationSec(tempDurationSec);
    aSong.setAlbum(tempAlbum);
}

void convertCase(char tempStr[])
{
    for (int i = 0; i < strlen(tempStr); i++)
    {
        tempStr[i] = toupper(tempStr[i]);
    }
}