/*
 ============================================================================
 Name        : linked_list.c
 Author      : Slobodchikov_RS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.hpp"

typedef struct
{
	int x;
	int y;
	int z;
}Coordinate;

int main(void)
{
//	Node* head = NULL;

	Coordinate dotA;
	Coordinate dotB;

	dotA.x = 100;
	dotA.y = 200;
	dotA.z = -137;

	dotB.x = -1;
	dotB.y = 5000;
	dotB.z = -100000;

	LinkedList Llist;

	Llist.push(&dotA, sizeof(dotA));
	Llist.push(&dotB, sizeof(dotB));
	Llist.printLinkedList();


	Coordinate dotC;
	int a = Llist.pop(&dotC);
	printf("%d\n", a);
	printf("dotC: x=%d y=%d z=%d\n", dotC.x, dotC.y, dotC.z);
	Llist.printLinkedList();

	return EXIT_SUCCESS;
}
