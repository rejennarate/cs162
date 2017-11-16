//This is the implementation file for SongList class
#include "songlist.h"
#include "tools.h"

//constructors
SongList::SongList()
{
    capacity = CAP;

    if(list)
    {
        delete [] list;
        list = NULL;
    }

    //allocate memory for an array of videos
    list = new Song[capacity];
    size = 0;
}

//constructor from file
SongList::SongList(char fileName[])
{
    capacity = CAP;

    if(list)
    {
        delete [] list;
        list = NULL;
    }

    list = new Song[capacity];
    size = 0;
    ifstream inFile;
    Song aSong;
    char tempTitle[MAXCHAR];
    char tempArtist[MAXCHAR];
    int tempDurationMin;
    int tempDurationSec;
    char tempAlbum[MAXCHAR];

    inFile.open(fileName);
    if(!inFile)
    {
        cout << "cannot open file! Exiting!!" << endl;
        exit(0);
    }

    inFile.getline(tempTitle, MAXCHAR, ';');
    while(!inFile.eof())
    {
        inFile.getline(tempArtist, MAXCHAR, ';');
        inFile >> tempDurationMin;
        inFile.ignore(MAXCHAR, ';');
        inFile >> tempDurationSec;
        inFile.ignore(MAXCHAR, ';');
        inFile.getline(tempAlbum, MAXCHAR, '\n');

        //populate aSong;
        aSong.setTitle(tempTitle);
        aSong.setArtist(tempArtist);
        aSong.setDurationMin(tempDurationMin);
        aSong.setDurationSec(tempDurationSec);
        aSong.setAlbum(tempAlbum);
        addSong(aSong);
        inFile.getline(tempTitle, MAXCHAR, ';');
    }
    inFile.close();
}

//destructor
SongList::~SongList()
{
    //delete list
    if(list)
    {
        delete [] list;
        list = NULL;
    }
}

//Add a song to the library
void SongList::addSong(Song aSong)
{
    //check if size ==  cap
    //If yes, then grow the array
    if(size == capacity)
    {
        growList();
    }
    //!!!!! Assignment operator overloaded-So, ok to copy
    list[size++] = aSong;

    char tempTitle[MAXCHAR];
    aSong.getTitle(tempTitle);
    list[size].setTitle(tempTitle);

    char tempArtist[MAXCHAR];
    aSong.getArtist(tempArtist);
    list[size].setArtist(tempArtist);

    list[size].setDurationMin(aSong.getDurationMin());
    list[size].setDurationSec(aSong.getDurationSec());

    char tempAlbum[MAXCHAR];
    aSong.getAlbum(tempAlbum);
    list[size].setAlbum(tempAlbum);

    size++;
}

//search by Title
void SongList::searchByTitle()
{
    char searchTitle[MAXCHAR];
    char tempTitle[MAXCHAR];
    cout << "Please enter title to search for:";
    cin.get(searchTitle, MAXCHAR, '\n');
    convertCase(searchTitle);
    for(int i = 0; i < size; i++)
    {
        list[i].getTitle(tempTitle);
        convertCase(tempTitle);
        if(strstr(tempTitle, searchTitle) != NULL)
        {
            list[i].printSong();
        }
    }
}

//search by Artist
void SongList::searchByArtist()
{
    char searchArtist[MAXCHAR];
    char tempArtist[MAXCHAR];
    cout << "Please enter artist to search for: " << endl;
    cin.get(searchArtist, MAXCHAR, '\n');
    convertCase(searchArtist);

    for(int i = 0; i < size; i++)
    {
        list[i].getArtist(tempArtist);
        convertCase(tempArtist);     
        if( strstr(tempArtist,  searchArtist) != NULL )
        {
            list[i].printSong();
        }
    }
}

//search by Album
void SongList::searchByAlbum()
{
    char searchAlbum[MAXCHAR];
    char tempAlbum[MAXCHAR];
    cout << "Please enter album to search for: " << endl;
    cin.get(searchAlbum, MAXCHAR, '\n');
    convertCase(searchAlbum);

    for(int i = 0; i < size; i++)
    {
        list[i].getAlbum(tempAlbum);
        convertCase(tempAlbum);     
        if( strstr(tempAlbum,  searchAlbum) != NULL )
        {
            list[i].printSong();
        }
    }
}

//writes the data to the file
void SongList::writeData(char fileName[])
{
  ofstream outFile;
  outFile.open(fileName);
  for(int i = 0; i < size; i++)
  {
    list[i].printSong(outFile);
  }
}
  
//displays the list
void SongList::showList()
{
  for(int i = 0; i < size; i++)
  {
    cout << i+1 << ") ";
    list[i].printSong();
  }
  cout << endl;
}

//removes a song from the list
void SongList::removeSong()
{
    int delIndex = 0;
        delIndex = readInt("Please enter index of song to delete:");
        if(delIndex < size)
        {
            for(int i = delIndex; i < size; i++)
            {
                list[i-1] = list[i];
            }
        }
    size--;
}

//adds to capacity of list when full
void SongList::growList()
{
    capacity += GROWTH;
    char tempTitle[MAXCHAR];
    char tempArtist[MAXCHAR];
    char tempAlbum[MAXCHAR];

    Song *tempList = new Song[capacity];
    for (int i = 0; i < size; i++)
    {
        list[i].getTitle(tempTitle);
        tempList[i].setTitle(tempTitle);

        list[i].getArtist(tempArtist);
        tempList[i].setArtist(tempArtist);

        tempList[i].setDurationMin(list[i].getDurationMin());
        tempList[i].setDurationSec(list[i].getDurationSec());

        list[i].getAlbum(tempAlbum);
        tempList[i].setAlbum(tempAlbum);

        //assignment operator overloaded
        tempList[i] = list[i];
    }

    delete[] list;
    list = tempList;
    tempList = NULL;
}
