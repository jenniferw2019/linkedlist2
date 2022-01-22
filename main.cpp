#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "student.h"

void insertNode(Node* &head, Node* previous, Node* current, Student* newStudent);
void printStudent(Node* head, Node* next);

using namespace std;

int main()
{
  bool runProgram = true;
  char strInput[10];
  Node* studentList = NULL;
  
  while (runProgram == true)
    {
      cout << "Type ADD or PRINT" << endl;
      cin.get(strInput, 10);
      cin.get();

      if (strcmp(strInput, "ADD") == 0)
	{
	  char tempFirst[100];
	  char tempLast[100];
	  int tempID;
	  float tempGPA;

	  cout << "Type into for new student" << endl;
	  Student* ptrStudent = new Student();
	  cout << "Enter first name" << endl;
	  cin.get(tempFirst, 100);
	  cin.get();
	  cout << "Enter last name" << endl;
	  cin.get(tempLast, 100);
	  cin.get();
	  cout << "Enter id" << endl;
	  cin >> tempID;
	  cin.get();
	  cout << "Enter gpa" << endl;
	  cin >> tempGPA;
	  cin.get();
	  ptrStudent->setFirstName(tempFirst);
	  ptrStudent->setLastName(tempLast);
	  ptrStudent->setID(tempID);
	  ptrStudent->setGPA(tempGPA);
	}

      else if (strcmp(strInput, "PRINT") == 0)
	{

	}
    }
}
