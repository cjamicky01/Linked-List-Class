//#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <cstddef>
#include <iostream>

#define max 10

Linked_List::Linked_List() 
{ 
	head = nullptr; 
	int count = 0;

}
Linked_List::~Linked_List() { }

void Linked_List::ClearList()
{
	ListItem *next = new ListItem;
	ListItem *current = new ListItem;
	current = head;
	
	while(current!=nullptr)
	{
		next = current->next;
		free(current);
		current = next;
	}

	head->next = nullptr;
}

bool Linked_List::Search(int key, float *retVal)
{
	ListItem *nextNode = new ListItem;
	ListItem *previous = new ListItem;
	nextNode = head;
	cout << "Node " << count << " out of " << max << endl;
	while(nextNode != nullptr && nextNode->key != key)
	{
		previous = nextNode;
		nextNode= previous->next;
	}
	if(nextNode != nullptr)
	{
		*retVal = nextNode->theData;
	}
	else
	{
		return false;
	}
	return true;
}
int Linked_List::ListLength()
{
	
	return count;
	/*int count;
	ListItem *temp = new ListItem;
	temp->next = head->next;
	
	while(temp!=nullptr)
	{
		temp = temp->next;
		count++;
	}
	return count;*/
	
}

bool Linked_List::Insert(int key, float f)
{
	ListItem *temp = new ListItem;
	ListItem *newNode = new ListItem;
	ListItem *previous = new ListItem;
	if(count == max)
	{
		cout << "List has hit max size." << endl;
		return false;
	}
	count++;
	//temp = head;
	
	if(head == nullptr)
	{
		newNode->theData = f;
		newNode->key = key;
		head = newNode;
		newNode->next=nullptr;
		
	}
	else{
		temp = head;
		while(temp != nullptr)
		{				
			previous = temp;
			temp = previous->next;
		}
			newNode->key = key;		
			newNode->theData = f;			
			previous->next = newNode;		
			newNode->next = nullptr;
		
		
	}
	return true;
}

bool Linked_List::Delete(int key)
{
	ListItem *previous = new ListItem;
	ListItem *nextNode = new ListItem;
	if(head->key == key)
	{
		nextNode = head->next;
		previous = head;
		free(previous);
		head = nextNode;
	}
	else
	{
		nextNode=head;
		while(nextNode!=nullptr && nextNode->key!=key)
		{
			previous = nextNode;
			nextNode = previous->next;
		}
		if(nextNode!=nullptr)
		{
			previous->next=nextNode->next;
			free(nextNode);
		}
		else
		{
			return false;
		}
	}
	count--;	
	return true;
}

bool Linked_List::isEmpty()
{
	if(head == nullptr)
	{
		return true;
	} else {
		return false;
	}
}

bool Linked_List::isFull()
{
	if(count == max)
	{
		return true;
	}
	else
	{
		return false;	
	}
}

void Linked_List::PrintList()
{
	if(isEmpty())
	{
		cout << "Empty!" << endl;
	}	
	ListItem *nextNode = new ListItem;
	nextNode = head;
	while(nextNode!=nullptr)
	{
		cout << "Key: " << nextNode->key << endl;
		cout << "theData: " << nextNode->theData << endl;
		nextNode = nextNode->next;		
	}
}
