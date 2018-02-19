/*
 * linked_list.h
 *
 *  Created on: Feb 18, 2018
 *      Author: Slobodchikov_RS
 */

#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_
#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <cstddef>

class Elemen_c
{
	void *ptr;
	size_t size;
public:
	Elemen_c(void * data, size_t sz)
	{
		ptr = new char[sz];
		memcpy(ptr, data, sz);
		size = sz;
	};
	~Elemen_c()
	{
		delete (char *) ptr;
		size = 0;
	};
	size_t getElement(void *outPtr)
	{
		memcpy(outPtr, ptr, size);
		return size;
	};
	void printElement()
	{
		for(size_t i = 0; i < size; i++)
		{
			printf("%X", ((uint8_t*)ptr)[i]);
		}
		printf("\n");
	};
};

class Node_c
{
	Elemen_c *elementPtr;
	Node_c *next;
public:
	Node_c(void *data, size_t sz)
	{
		elementPtr = new Elemen_c(data, sz);
		next = NULL;
	};
	~Node_c()
	{
		delete elementPtr;
		next = NULL;
	};
	void setNextNode(Node_c *nextNode)
	{
		next = nextNode;
	};
	Node_c *getNextNode()
	{
		return next;
	};
	size_t getNodeElement(void *outPtr)
	{
		return elementPtr->getElement(outPtr);
	};
	void printElement()
	{
		elementPtr->printElement();
	};
};

class LinkedList{
	Node_c *first;
	Node_c *head;
public:
	LinkedList()
	{
		first = NULL;
		head = NULL;
	};
	~LinkedList()
	{
		while(head)
		{
			Node_c *prev = head;
			head = head->getNextNode();
			delete prev;
		}
	};
	void push(void *elem, size_t elemSize);
	size_t pop(void *elemPtr);
	void printLinkedList()
	{
		Node_c *printHead = head;

		if(printHead == NULL)
		{
			printf("Is empty\n");
		}

		while(printHead)
		{
			printHead->printElement();
			printHead = printHead->getNextNode();
		}
	};
};

#endif /* LINKED_LIST_HPP_ */
