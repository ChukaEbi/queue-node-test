/** queue.c
 *  @author Chuka Ebi
 *  Functions to create queue, enqueue and dequeue, which would be tested in file queuetest.c.
 */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/**
 * create an queue and return the newly ceated queue
 */
Queue *create_queue(int max_cells) {
	// Holds pointer to the newly-allocated Stack structure.
	Queue *new_queue = (Queue*)malloc(sizeof(Queue));

	// Error--unable to allocate.
	if (new_queue == NULL) return NULL;

	new_queue->max_cells = max_cells;
	new_queue->head = 0;
	new_queue->tail = 0;
	new_queue->isInitial = 1;
	new_queue->queue_base = (void**) calloc(sizeof(void *), max_cells);
	if (new_queue->queue_base == NULL) {
		free(new_queue); // Unable to allocate stack entries, so free struct.
		return NULL;
	}

	return new_queue;
}

/**
 * add node to into queue
 */
int enqueue(Queue *which_queue, void *ptr) {
	printf("head: %d tail: %d\n", which_queue->head, which_queue->tail);
	if (which_queue->head % which_queue->max_cells== which_queue->tail % which_queue->max_cells) {
		if (which_queue->isInitial) {
			which_queue->isInitial = 0;
		} else {
				return -1; // queue full
		}
	}

    // assign ptr to new position of queue
	which_queue->queue_base[which_queue->head % which_queue->max_cells] = ptr;
    
    // modify index pointer by increaseing
	which_queue->head = which_queue->head + 1;

	return 0;
}

/**
 * remove an element from queue and return this element
 */
void* dequeue(Queue *which_queue) {
	printf("head: %d tail: %d\n", which_queue->head, which_queue->tail);
	if (which_queue->head == which_queue->tail) {
		return NULL; // queue empty
	}
    // retrieve pointer from queue
	void* ptr = (void*)which_queue->queue_base[which_queue->tail % which_queue->max_cells];
    // move tail and and delete tail element
	which_queue->tail = which_queue->tail + 1;
	if (which_queue->tail == which_queue->head) {
		which_queue->isInitial = 1;
	}
	return ptr;

}
