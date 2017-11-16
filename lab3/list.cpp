#include "list.h"
#include <iostream>
using namespace std;

bool insert(int val, int intList[], int& size)
{
    if(size == 0)
    {
      intList[size] = val;
      size++;
      cout << "size: " << size << endl;
      cout << "val: " << val << endl;
    }
    else 
    {
    		// go through the array and shift everything greater than the value to the right by 1
    	  // then insert the value when you find where you want the item to go 
    		for(int i = 0; i < size; i++)
    		{
            cout << "Inserting value " << val << " into array..." << endl;
    				// check if the value already exists in the array, because if so it's a duplicate
    			  if(intList[i] == val)
    			  {
    				  	cout << "Value " << val << " already exists in array." << endl;
    				  	return false;
    			  }
            else
            {
                // if val is less than the first item in the array
                if(val < intList[i])
                {
                    // shift everything one right
                    intList[i+1] = intList[i];
                    intList[i] = val;
                    size++;
                    cout << "Value " << val << " added." << endl;
                    break;
                }
                // if the value is greater than the last item in the array
                // assuming everything is sorted okay
                // because size is not 0-based and the array is, the last item in the array
                // is size-1
                else if (val > intList[size-1])
                {
                    // just add the value to the end
                    intList[size] = val;
                    cout << "Value " << val << " added." << endl;
                    size++;
                    break;
                }
                // otherwise assume the value is between two items in the array
                else {
                    for(int j = 0; j < size;  j++)
                    {
                        if(intList[j] < val && val < intList[j+1])
                        {
                            // shift j+1 right one and insert val at intList[i]
                            intList[j+2] = intList[j+1];
                            intList[j+1] = val;
                            size++;
                            break;
                        }
                    }
                }
            }
        }
    }
    return true;
}



bool remove(int val, int intList[], int& size)
{
		for(int i = 0; i < size; i++)
		{
        if(intList[i] == val)
        {
        		for(; i < size; i++)
        		{
        				intList[i] = intList[i+1];
        		}

        		cout << "Value " << val << " removed." << endl;
				    size--;
        }
    }
		return true;
}

void print(const int intList[], int size)
{
		cout << endl << "[ ";
		for(int i=0; i<size; i++)
		{
			cout << intList[i] << " ";
		}
		cout << "]" << endl;
}
