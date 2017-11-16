#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
	int list[CAP];
	int size = 10;
    build(list, size);
    display(list, size);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    sumOfEvens(list, size);
    remove(list, size, 5);

    cout << "The list after removal: " << endl;
    display(list, size);
    
    return 0;
}


/*
Proficiency Test Midterm
Start with the code in ~gd.iyer/cs162/proficiencyTest/midterm. You will want to copy
it into a directory of your own.
File supplied.o contains binary code that can build, and display an array.
For this test, you will need to write the following functions in array.cpp, add function
prototypes for them to array.h and invoke the functions in main.cpp. You should label
the output of your test, such as “the list after removal: “ etc.
 int sumOfEvens(int list[], int size)
compute and return the sum of even integers in list
 void remove(int list[], int& size, int numOfInt)
remove the first “numOfInt” integers in the list and update the size of the list E.g.
remove(list, size, 5);
will remove the first 5 integers in the list
Create a makefile for the project and build it. Please don’t forget the supplied.o when
generating the executable.
For test submission, copy the above function implementation into solution.txt, then
append the output of the app to the file. ftp solution.txt to your local machine and upload it
to the Desire2Learn Assignment dropbox.
./main >> solution.txt //assuming the executable is called main
*/