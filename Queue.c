#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"


/***********************************************************************************
* Function name: createQueue
* Input: none
* Output: Queue*
* Function Operation: the function creates an empty queue  by palcing the
*					rear and the front of the to be null as first.
*					than that function will return a pointer to that ptr address .
***********************************************************************************/
Queue* createQueue()
{
	//allocation of memory for queue variable
	Queue* queue = (Queue*)malloc(sizeof(Queue));

	/*if the malloc has failed*/
	if (queue == NULL) {
		printf("Malloc failed!\n");
		free(queue);
		exit(1);
	}
	//like linked list, the front will be null fron now and also the rear
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

/***********************************************************************************
* Function name: enQueue
* Input: Queue* queue, void* data (data means name and ID)
* Output: void
* Function Operation: the function adds a elenent to the queue by palcing the
*					rear and the front of the (the first object of the queue) to be null as first
*					than that function will return a pointer to that first element of
*					the queue!
***********************************************************************************/
void enQueue(Queue* queue, void* data)
{
	//initialization of generic ptr, and a ptr to the element.
	Qnode* ptr;
	Qnode* element;
	element = malloc(sizeof(Qnode));

	/*Iif the malloc failed*/
	if (element == NULL) {
		printf("Malloc Failed!\n");
		free(element);
		exit(1);
	}
	//initialization of ptr to be the last element of the queue
	ptr = queue->rear;
	queue->rear = element;

	/*Add the new data at the end of queue and change rear */
	element->next = NULL;
	element->data = data;

	/*if queue front place is null*/
	if (queue->front == NULL) {
		queue->front = element;
	}

	/*if ptr isnt null, ill place the element there*/
	if (ptr!= NULL) {
		ptr->next = element;
	}
}

/***********************************************************************************
* Function name: deQueue
* Input: Queue* queue, void* data (data means name and ID)
* Output: void
* Function Operation: the function removes an element from the queue
*					on that data structure, it removes from the front.
***********************************************************************************/
void deQueue(Queue* queue)
{
	//initialiazation of an ptr pinter
	Qnode* ptr;
	//ptr points on the front element of the queue 
	ptr = queue->front;

	/*if the front is null, the queue is empty*/
	if (queue->front == NULL) {
		return;
	}
	//placement of the front of queue to be the next ptr
	queue->front = ptr->next;

	/*if the pointrt isnt NULL, ill free him*/
	if (ptr != NULL) {
		free(ptr);
	}
}

/***********************************************************************************
* Function name: isEmpty
* Input: Queue* queue
* Output: int. 1 for NULL, 0 for not null
* Function Operation: the function checks if the front of the queue is null. if it is
*					it id empty, and the function will return 1.
***********************************************************************************/
int isEmpty(Queue* queue)
{
	if (queue->front == NULL) {
		return 1;
	}
	return 0;
}
