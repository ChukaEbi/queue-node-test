#ifndef QUEUE_H
#define QUEUE_H

/** Struct to define a stack; each entry can hold a pointer to anything.
 */
struct _Queue {
  void **queue_base; // Pointer to base of stack
  int head, tail;  // Pointer to next free cell;
  int max_cells; // Maximum number of entries in the stack
  int isInitial;
};

typedef struct _Queue Queue;

// Function prototypes

/** Create a queue by allocating a Queue structure, initializing it,
 *  and allocating memory to hold the queue entries.
 * @param max_cells Maximum entries in the queue
 * @return Pointer to newly-allocated Queue structure, NULL if error.
 */

Queue *create_queue(int max_cells);

void delete_queue(Queue *which_queue);
void* dequeue(Queue *which_queue);

/** Adds a pointer onto a Queue.
 * @param which_queue Pointer to Queue.
 * @param ptr Pointer to be added.
 * @return 0 if successful, -1 if not.
 */
int enqueue(Queue *which_queue, void *ptr);



#endif
