// CS162 Project 2
// Written by: Jenna Hildebrand
// Date: Aptil 17 2017
// Sources: Stack Overflow, Marisol Curtis (coworker, classmate), 
// Ryan Bean (coworker), course sample files

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

const int CAP = 100;
const int MAX_SIZE = 101;

struct Song {
    char songName[MAX_SIZE];
    char artist[MAX_SIZE];
    double duration;
    char album[MAX_SIZE];
};

int readInt(char prompt[]);
void displayMenu();
char readOption();
void convertCase(char tempStr[]);
void execute(char option, Song [], int &);


void openFile(char [], ifstream &);
void openFile(char [], ofstream &);
void loadData(ifstream &, Song [], int &);
void writeData(const Song [], int size, ofstream &);
void newSong(Song [], int &, const Song &);
void viewAllSongs(const Song [], const int);
void removeSong(Song [], int &);
void searchByArtist(Song [], int);
void searchByAlbum(Song [], int);
void abortProgram();

int main() {
    //create a variable for a single song
    char fileName[MAX_SIZE] = "songs.txt";
    char option;

    Song library[CAP];

    ifstream inFile;
    ofstream outFile;
    int size = 0;
    openFile(fileName, inFile);
    loadData(inFile, library, size);
    do {
        displayMenu();
        option = readOption();
        execute(option, library, size);
    }
    while(tolower(option != 'q'));
    openFile(fileName, outFile);
    writeData(library, size, outFile);
    return 0;
}

void displayMenu() {
    // Prompt user to make a selection
    cout << "Please make a selection:" << endl;
    cout << "E to (E)nter a new song;" << endl;
    cout << "V to (V)iew all songs;" << endl;
    cout << "R to (R)remove a song;" << endl;
    cout << "A to search for songs by (A)rtist;" << endl;
    cout << "B to search for song by al(B)um;" << endl;
    cout << "Q to (Q)uit" << endl;
}

//read the option from the user
char readOption() {
    char input;
    cin >> input;
    cin.ignore(100, '\n');
    return input;
}

//converts all text to upper case
void convertCase(char tempStr[]) {
    for (int i = 0; i < strlen(tempStr); i++) {
        tempStr[i] = toupper(tempStr[i]);
    }
}

void execute(char option, Song library[], int &size) {
    // initialize a new instance of the Song struct to pass into function calls
    Song aSong;

    switch (toupper(option)) {
    case 'E': {
        if(size == CAP) {
            cout << "Your library is full! Song not added!!";
            return;
        }
        newSong(library, size, aSong);
        break;
    }
    case 'V': {
        viewAllSongs(library, size);
        break;
    }
    case 'R':
        removeSong(library, size);
        break;
    case 'A':
        searchByArtist(library, size);
        break;
    case 'B':
        searchByAlbum(library, size);
        break;
    case 'Q':
        break;
        break;
    default:
        cout << "Please select a valid option." << endl;
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

void openFile(char fileName[], ifstream &inFile) {
    inFile.open(fileName);
    if(!inFile)
    {
        cout << "Input file did not open!! Program exiting!!!" << endl;
        exit(0);
    }
}

//This opens the output file
void openFile(char fileName[], ofstream &outFile) {
    outFile.open(fileName);
    if(!outFile)
    {
        cout << "Output file did not open!! Program exiting!!!" << endl;
        exit(0);
    }
}

void loadData(ifstream &inFile, Song library[], int &size) {
    while (inFile) {
        inFile.getline(library[size].songName, MAX_SIZE, ';');
        inFile.getline(library[size].artist, MAX_SIZE, ';');
        inFile >> library[size].duration;
        inFile.getline(library[size].album, MAX_SIZE, '\n');
    }
    size++;
    inFile.close();
}

//This function writes the data to the file
void writeData(const Song library[], int size, ofstream &outFile) {
    for(int i = 0; i < size; i++) {
        outFile << library[i].artist << "-" << library[i].album << "-" << library[i].songName << ";" << "(" << library[i].duration << ")" << endl;
    }
    outFile.close();
}

// add a new song
void newSong(Song library[], int &size, const Song &aSong) {
    library[size++] = aSong;
}

//populate aSong from the user
void newSong(Song &aSong) {
    int min;
    int sec;
    cout << "Song name: ";
    cin.get(aSong.songName, MAX_SIZE, '\n');
    cin.ignore(100, '\n');
    cout << "Artist: ";
    cin.get(aSong.artist, MAX_SIZE, '\n');
    cin.ignore(100, '\n');
    cout << "Duration: ";
    cin >> min;
    while (!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input!! Please try again!!";
        cin >> min;
    }
    cin.ignore(100, '\n');
    cout << "Album: ";
    cin >> aSong.album;
    cin.ignore(100, '\n');
}

// view all songs in the library
void viewAllSongs(const Song library[], const int size) {
    for(int i = 0; i < size; i++)
    {
        cout << i+1 << "." << library[i].artist << "-" << library[i].album << "-" << library[i].songName << ";" << "(" << library[i].duration << ")" << endl;
    }
    cout << endl;
}

// delete a song
void removeSong(Song library[], int &size) {
    int delIndex = 0;
    cout << "Please enter index of the song to delete:";
    cin >> delIndex;
    cin.ignore(100, '\n');
    if(delIndex < size)
    {
         for(int i = delIndex; i < size; i++)
        {
            library[i-1] = library[i];
        }
    }
    size--;
}

void searchByArtist(Song library[], int size) {
    char artist[MAX_SIZE];

    cout << "Please enter artist: " << endl;
    cin.get(artist, MAX_SIZE, '\n');

    for(int i = 0; i < size; i++)
    {
       convertCase(artist);
       convertCase(library[i].artist);     
       if( strstr (library[i].artist, artist) != NULL ){
            cout << library[i].artist << "-" << library[i].album << "-" << library[i].songName << ";" << "(" << library[i].duration << ")" << endl;
       }
    }
}

void searchByAlbum(Song library[], int size) {
    char album[MAX_SIZE];

    cout << "Please enter album name: " << endl;
    cin.get(album, MAX_SIZE, '\n');

    for(int i = 0; i < size; i++)
    {
       convertCase(album);
       convertCase(library[i].album);     
       if( strstr (library[i].album,  album) != NULL ){
            cout << library[i].artist << "-" << library[i].album << "-" << library[i].songName << ";" << "(" << library[i].duration << ")" << endl;
       }
    }
}

// This function stops the program 'flashing' off the screen.
void abortProgram() {
    char reply;

    cout << "Press q (or any other key) followed by 'Enter' to quit.";
    cin >> reply;
    exit(1);
}

