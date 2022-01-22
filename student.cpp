#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"

using namespace std;

Student::Student() {}

char* Student::getFirstName()
{
  return firstName;
}
char* Student::getLastName()
{
  return lastName;
}
int Student::getID()
{
  return id;
}
float Student::getGPA()
{
  return gpa;
}
void Student::setFirstName(char* newFirstName)
{
  strcpy(firstName, newFirstName);
}
void Student::setLastName(char* newLastName)
{
  strcpy(lastName, newLastName);
}
void Student::setID(int newID)
{
  id = newID;
}
void Student::setGPA(float newGPA)
{
  gpa = newGPA;
}
void Student::displayStudent(char* first, char* last, int ID, float GPA)
{
  cout << first << " ";
  cout << last << " ";
  cout << ID << " ";
  cout<<fixed<<setprecision(2)<< GPA << endl;
}

Student::~Student() {}
