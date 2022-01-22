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

	  insertNode(studentList, studentList, studentList, ptrStudent);
	}

      else if (strcmp(strInput, "PRINT") == 0)
	{
	  printStudent(studentList, studentList);
	}
    }
  return 0;
}

void insertNode(Node* &head, Node* previous, Node* current, Student* newStudent)
{

  if (head == NULL)
    {
      head = new Node(newStudent);
      cout << (head->getStudent())->getFirstName() << endl;
    }
  else if (newStudent->getID() < (head->getStudent())->getID())
    {
      Node* temp = head;
      head = new Node(newStudent);
      head->setNext(temp);
    }
  else if (current == NULL)
    {
      Node* tempNode = new Node(newStudent);
      previous->setNext(tempNode);
      (previous->getNext())->setNext(NULL);
    }
  else if (newStudent->getID() < (current->getStudent())->getID())
    {
      Node* tempN = new Node(newStudent);
      previous->setNext(tempN);
      tempN->setNext(current);
    }
  else
    {
      insertNode(head, current, current->getNext(), newStudent);
    }
}

void printStudent(Node* head, Node* next)
{

  if (next == head)
    {
      cout << "list: " << endl;
    }
  if (next != NULL)
    {
      Student* tempstu = next->getStudent();
      tempstu->displayStudent();

      printStudent(head, next->getNext());
    }
}
