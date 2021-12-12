#ifndef _QUEUE_H
#define _QUEUE_H

// A linked list (LL) node to store a queue entry 
typedef struct Qnode
{
	void* data;
	struct Qnode* next;
}Qnode;
// The queue, front stores the front node of LL and rear stores the 
// last node of LL 
typedef struct Queue
{
	struct Qnode* front;
	struct Qnode* rear;
}Queue;

Queue* createQueue();
//q - the queue, k- the key (element)
void enQueue(Queue* queue, void* data);
void deQueue(Queue* queue);
// retutn 1 if empty and zero if not empty
int isEmpty(Queue* queue);

#endif
