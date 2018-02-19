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

template< class T >
class Elemen_c
{
	T *ptr;
public:
	Elemen_c(T data)
	{
		ptr = new T;
		*ptr = data;
	};
	~Elemen_c()
	{
		delete ptr;
	};
	T getElement()
	{
		return *ptr;
	};
	void printElement()
	{
		for(size_t i = 0; i < sizeof(T); i++)
		{
			printf("%X", ((uint8_t*)ptr)[i]);
		}
		printf("\n");
	};
};

template< class T >
class Node_c
{
	Elemen_c < T > *elementPtr;
	Node_c < T > *next;
public:
	Node_c(T data)
	{
		elementPtr = new Elemen_c < T >(data);
		next = NULL;
	};
	~Node_c()
	{
		delete elementPtr;
		next = NULL;
	};
	void setNextNode(Node_c < T > *nextNode)
	{
		next = nextNode;
	};
	Node_c < T > *getNextNode()
	{
		return next;
	};
	T getNodeElement()
	{
		return elementPtr->getElement();
	};
	void printElement()
	{
		elementPtr->printElement();
	};
};

template< class T >
class LinkedList{
	Node_c < T > *first;
	Node_c < T > *head;
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
			Node_c < T > *prev = head;
			head = head->getNextNode();
			delete prev;
		}
	};
	void push(T elem);
	T pop();
	void printLinkedList()
	{
		Node_c < T > *printHead = head;

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

template< class T >
void LinkedList < T >::push(T elem)
{
	Node_c < T > *tmp = new Node_c < T > (elem);

	if(head == NULL)
	{
		head = tmp;
	}
	else
	{
	    tmp->setNextNode(head);
	    head = tmp;
	}

	if(first == NULL)
	{
		first = head;
	}
}

template< class T >
T LinkedList < T >::pop()
{
	T elemSize = head->getNodeElement();

	Node_c < T > *prev = head;
	head = head->getNextNode();
	delete prev;

	return elemSize;
}

#endif /* LINKED_LIST_HPP_ */
