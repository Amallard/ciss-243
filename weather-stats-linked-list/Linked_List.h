/*****************************************
Class Linked_List.h

This is a linked list template class which can append, insert, and delete 
	elements from the list. It also has functions to display the list
	and search for an element in this list.
A function to return a specific item has been added - this function is 
   utilized in the Weather Statistics program where the function in thrown 
   in a loop to test every item in the list. 

Author: Adam Allard
Created: 04/15/15
Revisions: 04/15/15 - Initial
		   04/16/15 - Added searchList function
		   04/17/15 - Added checkNode function

******************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

template <class T>
class Linked_List
{
private:

	struct ListNode
	{
		T value;
		struct ListNode *next;
	};

	ListNode *head;

public:
	Linked_List();
	~Linked_List();

	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;

	int searchList(T) const;

	T checkNode(int) const;
};

/********* constructor ***********/
template <class T>
Linked_List<T>::Linked_List()
{
	head = nullptr;
}

/********* destructor ***********/
template <class T>
Linked_List<T>::~Linked_List()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

/********* append ***********/
template <class T>
void Linked_List<T>::appendNode(T num)
{
	ListNode *newNode;
	ListNode *nodePtr;

	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;

		while (nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
	}
}

/********* insert ***********/
template <class T>
void Linked_List<T>::insertNode(T num)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	newNode = new ListNode;
	newNode->value = num;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

/********* delete ***********/
template <class T>
void Linked_List<T>::deleteNode(T num)
{
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	if (!head)
		return;

	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

/********* display ***********/
template <class T>
void Linked_List<T>::displayList() const
{
	ListNode *nodePtr;
	nodePtr = head;

	while (nodePtr)
	{
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

/********* search ***********/
template <class T>
int Linked_List<T>::searchList(T num) const
{
	int index = 0;

	ListNode *nodePtr;
	nodePtr = head;

	while (nodePtr)
	{
		if (nodePtr->value == num)
			return index;
		else
		{
			nodePtr = nodePtr->next;
			index++;
		}
	}
	
	// if the loop doesn't find the passed number, it will safely exit the program,
	// where the value -1 will be returned to signify that the value was not found
	index = -1;
	return index;
}

/********* check ***********/
// accepts an int to determine which element in the list to return
template <class T>
T Linked_List<T>::checkNode(int m) const
{
	ListNode *nodePtr;
	nodePtr = head;

	if (m == 1)
		return head->value;
	else
	{
		for (int i = 1; i < m; i++)
		{
			nodePtr = nodePtr->next;
		}

		return nodePtr->value;
	}
}

#endif