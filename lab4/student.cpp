#include "student.h"
#include <cstring>

// initialize a newly created student object with the passed in value
Student::Student(const char initId[], double gpa)
{
  strcpy(this->id, initId);
  this->gpa = gpa;
}

// compare the current student object with the passed in one by id
bool Student::isLessThanByID(const Student& aStudent) const
{
  if (strcmp(this->id, aStudent.id) < 0)
  {
    return true;
  }
  else 
    return false;
}

// compare the current student object with the passed in one by gpa
bool Student::isLessThanByGpa(const Student& aStudent) const
{
  if (this->gpa < aStudent.gpa)
  {
    return true;
  }
  else
    return false;
}

void Student::print() const
{
	cout << id << '\t' << gpa << endl;
}

