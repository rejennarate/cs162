// CS162 Project 2
// Written by: Jenna Hildebrand
// Date: Aptil 17 2017
// Sources: Stack Overflow, Marisol Curtis (coworker, classmate), 
// Ryan Bean (coworker), course sample files

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 101;
const int CAP = 100;
const int MAX_TIME = 3;

struct Song 
{
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char durationMin[MAX_TIME];
    char durationSec[MAX_TIME];
    char album[MAX_SIZE];
};

void displayMenu();
char readOption();
void exeCmd(char option, Song [], int &);
void loadData(ifstream &, Song [], int &);
void writeData(const Song [], int size, ofstream &);
void addSong(Song [], int &, const Song &);
void addSong(Song &);
void showList(const Song [], const int);
void removeSong(Song [], int &);
void searchByArtist( Song [], int );
void searchByAlbum( Song [], int );
void convertCase(char tempStr[]);

int main()
{

    //c reate a variable for a single song
    Song library[CAP];
    char fileName[MAX_SIZE] = "songs.txt";
    char option;
    ifstream inFile;
    ofstream outFile;
    int size = 0;

    // this opens the input file
    inFile.open(fileName);
    if(!inFile)
    {
        cout << "Input file did not open!! Program exiting!!!" << endl;
        exit(0);
    }

    loadData(inFile, library, size);
    
    do
    {
        displayMenu();
        option = readOption();
        exeCmd(option, library, size);
    } while(tolower(option != 'q'));

    // This opens the output file
    outFile.open(fileName);
    if(!outFile)
    {
        cout << "Output file did not open!! Program exiting!!!" << endl;
        exit(0);
    }

    writeData(library, size, outFile);
    return 0;
}

void writeData(const Song library[], int size, ofstream &outFile)
{
    for(int i = 0; i < size; i++)
    {
        outFile << library[i].title << ";" << library[i].artist << ";";
        outFile << library[i].durationMin << ";" << library[i].durationSec << ";" << library[i].album << endl;
    }
    outFile.close();
}

// loads data from file
void loadData(ifstream &inFile, Song library[], int &size)
{
    while (inFile) 
    {   
        inFile.get(library[size].title, MAX_SIZE, ';');
        inFile.ignore(MAX_SIZE,';'); 
        inFile.get(library[size].artist, MAX_SIZE, ';');
        inFile.ignore(MAX_SIZE,';'); 
        inFile.get(library[size].durationMin, MAX_TIME, ';');
        inFile.ignore(MAX_SIZE,';'); 
        inFile.get(library[size].durationSec, MAX_TIME, ';');
        inFile.ignore(MAX_SIZE,';'); 
        inFile.get(library[size].album, MAX_SIZE, '\n');
        inFile.ignore(MAX_SIZE,'\n'); 
    if (inFile.good())
            size++;
    }

    inFile.close();
}

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

void exeCmd(char option, Song library [], int &size)
{
    Song aSong;
    switch (tolower(option))
    {
    case 'e':
        if(size == CAP)
        {
            cout << "Your list is Full! Song not added!!";
            return;
        }
        addSong(aSong);
        addSong(library, size, aSong);
        break;
    case 'd':
        showList(library, size);
        break;
    case 'r':
        showList(library, size);
        removeSong(library, size);
        break;
    case 'a':
        searchByArtist(library, size);
        break;
    case 'm':
        searchByAlbum(library, size);
        break;
    case 'q':
        break;
    default:
        cout << "Invalid input, please try again!!" << endl;
    }
}

// This function prints the list of songs    
void showList(const Song library[], const int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << i+1 << ". " << "Song Title: " << library[i].title << " | " << "Artist: " << library[i].artist << " | ";
        cout << "Duration: " << library[i].durationMin << ":" << library[i].durationSec << " | ";
        cout << "Album: " << library[i].album << endl;
    }
    cout << endl;
}

void searchByArtist( Song library[], int size )
{
    char searchArtist[MAX_SIZE];
    cout << "Please enter artist: " << endl;
    cin.get(searchArtist, MAX_SIZE, '\n');

    for(int i = 0; i < size; i++)
    {
       convertCase(searchArtist);
       convertCase(library[i].artist);     
       if( strstr(library[i].artist,  searchArtist) != NULL )
       {
        cout << "Song Title: " << library[i].title << " | " << "Artist: " << library[i].artist << " | ";
        cout << "Duration: " << library[i].durationMin << ":" << library[i].durationSec << " | ";
        cout << "Album: " << library[i].album << endl;
       }
    }
}

void searchByAlbum( Song library[], int size )
{
    char searchAlbum[MAX_SIZE];
    cout << "Please enter album: " << endl;
    cin.get(searchAlbum, MAX_SIZE, '\n');

    for(int i = 0; i < size; i++)
    {
       convertCase(searchAlbum);
       convertCase(library[i].album);     
       if( strstr (library[i].album,  searchAlbum) != NULL )
       {
        cout << "Song Title: " << library[i].title << " | " << "Artist: " << library[i].artist << " | ";
        cout << "Duration: " << library[i].durationMin << ":" << library[i].durationSec << " | ";
        cout << "Album: " << library[i].album << endl;
       }
    }
}

//add song to library
void addSong(Song library[], int &size, const Song &aSong)
{
    library[size++] = aSong;
}


void addSong(Song &aSong)
{
    cout << "Enter a song title: ";
    cin.get(aSong.title, MAX_SIZE, '\n');
    cin.ignore(MAX_SIZE,'\n'); 
    cout << "Enter an artist: ";
    cin.get(aSong.artist, MAX_SIZE, '\n');
    cin.ignore(MAX_SIZE,'\n'); 
    cout << "Enter minutes portion of song duration: ";
    cin.get(aSong.durationMin, MAX_TIME, '\n');
    cin.ignore(MAX_SIZE,'\n');  
    cout << "Enter seconds portion of song duration: ";
    cin.get(aSong.durationSec, MAX_TIME, '\n');
    cin.ignore(MAX_SIZE,'\n'); 
    cout << "Please enter the album: ";
    cin.get(aSong.album, MAX_SIZE, '\n');
    cin.ignore(MAX_SIZE,'\n'); 

}

//Removes a song from the list
void removeSong(Song library[], int &size)
{
    int delIndex = 0;
    cout << "Please enter index of song to delete: ";
    cin >> delIndex;
        if (delIndex > size)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a valid index: ";
            cin >> delIndex;
                if (!cin)
                {   cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Please enter a valid index: ";
                    cin >> delIndex;
                }
        }
    if(delIndex < size)
    {
         for(int i = delIndex; i < size; i++)
        {
            library[i-1] = library[i];
        }
    }
    size--;
}  

void convertCase(char tempStr[])
{
    for (int i = 0; i < strlen(tempStr); i++)
    {
        tempStr[i] = toupper(tempStr[i]);
    }
}
