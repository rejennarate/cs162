#include <iostream>
using namespace std;

void fill(int **table, int rows);
void print(int **table, int rows);

int main()
{
  int **table;
  int rows = 9;

  //write code here to allocate memory for the table
  table = new int *[rows];
  for (int i = 0; i < rows; i++)
  {
    table[i] = new int[i+1];
  }

  //call functions to fill/print table
  fill(table, rows);
  print(table, rows);

  //write code here to deallocate memory for the table
  for(int i = 0; i < rows; i++)
  {
    delete [] table[i];
  }
  delete [] table;
  table = NULL;

  return 0;
}

//write code here to populate it with required integers
void fill(int **table, int rows)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j <=i; j++)
    {
      table[i][j]= j;
    }
  }
}

//write code here to print the table
void print(int **table, int rows)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << table[i][j] << " ";
    }
    cout << endl;
  }
}

