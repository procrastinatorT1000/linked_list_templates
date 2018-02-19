/*
 * linked_list.c
 *
 *  Created on: Feb 18, 2018
 *      Author: Slobodchikov_RS
 */
#include "linked_list.hpp"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>



void LinkedList::push(void *elem, size_t elemSize)
{
	Node_c *tmp = new Node_c (elem, elemSize);

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

size_t LinkedList::pop(void *elemPtr)
{
	size_t elemSize = 0;
	elemSize = head->getNodeElement(elemPtr);

	Node_c *prev = head;
	head = head->getNextNode();
	delete prev;

	return elemSize;
}

