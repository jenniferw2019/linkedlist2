/*
This program allows user to add student info, print it out, delete them, and calculate the average gpa.
User can enter student first and last name, id, and gpa. 
Author: Jennifer Wang
1/29/22
 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "student.h"

//declare functions
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

      // if ADD is typed, creates a new entry for a student.
      if (strcmp(strInput, "ADD") == 0)
	{
	  char tempFirst[100];
	  char tempLast[100];
	  int tempID;
	  float tempGPA;

	  //input info for new student
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
	      //error message if not int value
	      cout << "Error. Student ID input should be a integer value." << endl;
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(),'\n');
	    }
	  else
	    {
	    cin.get();
	    cout << "Enter gpa" << endl;
	    cin >> tempGPA;
	    if (cin.fail())
	      {
		// error if not float value
		cout << "Error. Student GPA input should be a float value." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	      }
	    else
	      {
		cin.get();
		//set into to student pointer
		ptrStudent->setFirstName(tempFirst);
		ptrStudent->setLastName(tempLast);
		ptrStudent->setID(tempID);
		ptrStudent->setGPA(tempGPA);

		//insert node
		insertNode(studentList, studentList, studentList, ptrStudent);
	      }
	    }
	}

      // if PRINT is typed, all students currently stored are printed
      else if (strcmp(strInput, "PRINT") == 0)
	{
	  printStudent(studentList, studentList);
	}
      // if DELETE is typed, deletes the student with the corresponding id
      else if (strcmp(strInput, "DELETE") == 0)
	{
	  int deleteID;
	  cout << "Type a id to delete" << endl;
	  cin >> deleteID;
	  if (cin.fail())
	    {
	      cout << "Error. Student ID input should be a integer value." << endl;
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(),'\n');
	    }
	  else
	    {
	      cin.get();
	      //delete the student 
	      deleteNode(studentList, studentList, studentList, deleteID);
	    }  
	}
      // if AVERAGE is typed, calculate the average of all student GPAs
      else if (strcmp(strInput, "AVERAGE") == 0)
	{
	  float sum = 0;
	  float counter = 0;
	  float averageGpa;
	  averageGpa = averageGPA(studentList, studentList, sum, counter);
	  cout << fixed<<setprecision(2) << averageGpa << endl;
	}
      // stops the program
      else if (strcmp(strInput, "QUIT") == 0)
	{
	  runProgram = false;
	}
    }
  return 0;
}

//insert node function (add function using recursion)
void insertNode(Node* &head, Node* previous, Node* current, Student* newStudent)
{

  //if head is null, set new student as head
  if (head == NULL)
    {
      head = new Node(newStudent);

    }
  // set new student as head
  else if (newStudent->getID() < (head->getStudent())->getID())
    {
      Node* temp = head;
      head = new Node(newStudent);
      head->setNext(temp);
    }
  //set new student as last node in list
  else if (current == NULL)
    {
      Node* tempNode = new Node(newStudent);
      previous->setNext(tempNode);
      (previous->getNext())->setNext(NULL);
    }
  // set new student in between two students
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

//print function using recursion
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

//delete function using recursion
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

//calculate average gpa function using recursion
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
