#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "student.h"

void insertNode(Node* &head, Node* previous, Node* current, Student* newStudent);
void printStudent(Node* head, Node* next);
void deleteNode(Node* &head, Node* previous, Node* current, int id);
float averageGPA(Node* head, Node* current, float sum, int counter);
using namespace std;

int main()
{
  bool runProgram = true;
  char strInput[10];
  Node* studentList = NULL;
  
  while (runProgram == true)
    {
      cout << "Type ADD, PRINT, DELETE, AVERAGE,  or QUIT" << endl;
      cin.get(strInput, 10);
      cin.get();

      if (strcmp(strInput, "ADD") == 0)
	{
	  char tempFirst[100];
	  char tempLast[100];
	  int tempID;
	  float tempGPA;

	  cout << "Type info for new student" << endl;
	  Student* ptrStudent = new Student();
	  cout << "Enter first name" << endl;
	  cin.get(tempFirst, 100);
	  cin.get();
	  cout << "Enter last name" << endl;
	  cin.get(tempLast, 100);
	  cin.get();
	  cout << "Enter id" << endl;
	  cin >> tempID;
	  if (cin.fail())
	    {
	      cout << "Error. Student ID input should be a integer value." << endl;
	      cin.clear();
	      //cin.ignore();	      
	      //break;
	      cin.ignore(numeric_limits<streamsize>::max(),'\n');
	    }
	  cin.get();
	  cout << "Enter gpa" << endl;
	  cin >> tempGPA;
	  if (cin.fail())
	    {
	      cout << "Error. Student GPA input should be a float value." << endl;
	      cin.clear();
	      cin.ignore();
	      break;
	    }
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
      else if (strcmp(strInput, "DELETE") == 0)
	{
	  int deleteID;
	  cout << "Type a id to delete" << endl;
	  cin >> deleteID;
	  cin.get();
	  deleteNode(studentList, studentList, studentList, deleteID);
	    
	}
      else if (strcmp(strInput, "AVERAGE") == 0)
	{
	  float sum = 0;
	  float counter = 0;
	  float averageGpa;
	  averageGpa = averageGPA(studentList, studentList, sum, counter);
	  cout << fixed<<setprecision(2) << averageGpa << endl;
	}
      
      else if (strcmp(strInput, "QUIT") == 0)
	{
	  runProgram = false;
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

void deleteNode(Node* &head, Node* previous, Node* current, int id)
{
  
  if (head == NULL)
    {
      cout << "No students in list" << endl;
    }
  else
    {
  
      if ((head->getStudent())->getID() == id)
	{
	  Node* temph = head;
	  head = (head->getNext());
	  delete temph;
	}
      else if (current == NULL)
	{
	  cout << "No such ID" << endl;
	}
      else if ((current->getStudent())->getID() == id)
	{
	  Node* tempN = current->getNext();
	  previous->setNext(current->getNext());
	  delete current;
	}
      else
	{
	  deleteNode(head, current, current->getNext(), id);
	}
    }
}

float averageGPA(Node* head, Node* current, float sum, int counter)
{
  
  if (head == NULL)
    {
      cout << "No GPA to average" << endl;
      return 0;
    }
  
  else
    {
      if (current != NULL)
	{
	  sum = sum + (current->getStudent())->getGPA();
	  counter++;
	  return averageGPA(head, current->getNext(), sum, counter);
	}
      else
	{
	  return sum/counter;
	}
    }
 
  
}
