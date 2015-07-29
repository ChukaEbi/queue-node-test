/** queuetest.c
 *  @author Chuka Ebi
 *  Function to test queue.c
 */

#include <stdio.h>
#include "queue.h"
typedef struct {
  int x;
  double y;
}
Foo2; // Just some arbitrary struct
void print_queue(Queue* queue, int number);
void print_dequeue(void *ptr);

/**
 * main function for testing the queue
 */
int main() {
	int max_cells = 3;
	Foo2 f1;
	f1.x = 1;
	f1.y = 1.01;

	Foo2 f2;
	f2.x = 2;
	f2.y = 2.02;

	Foo2 f3;
	f3.x = 3;
	f3.y = 3.03;

	Foo2 *f;
	Queue *new_queue = create_queue(max_cells);
	printf("dequeue\n");
	void *testforemptyqueue = dequeue(new_queue);
	if (testforemptyqueue == NULL) {
		printf("empty test pass\n");
	} else {
		printf("%d\n", testforemptyqueue);
	}
	printf("enqueue 1 1.01\n");
	enqueue(new_queue, &f1);
	f = (Foo2*) dequeue(new_queue);
	printf("dequeue %d %f\n", f->x, f->y);

	printf("enqueue 1 1.01\n");
	enqueue(new_queue, &f1);
	printf("enqueue 2 2.02\n");
	enqueue(new_queue, &f2);
	f = (Foo2*) dequeue(new_queue);
	printf("dequeue %d %f\n", f->x, f->y);
	f = (Foo2*) dequeue(new_queue);
	printf("dequeue %d %f\n", f->x, f->y);

	printf("enqueue 1 1.01\n");
	enqueue(new_queue, &f1);
	printf("\n");

	printf("enqueue 2 2.02\n");
	enqueue(new_queue, &f2);
	printf("\n");	

	f = (Foo2*) dequeue(new_queue);
	printf("dequeue %d %f\n", f->x, f->y);

	printf("enqueue 3 3.03\n");
	enqueue(new_queue, &f3);
	f = (Foo2*) dequeue(new_queue);
	printf("dequeue %d %f\n", f->x, f->y);
	f = (Foo2*) dequeue(new_queue);
	printf("dequeue %d %f\n", f->x, f->y);

	printf("enqueue 1 1.01\n");
	enqueue(new_queue, &f1);
	printf("enqueue 2 2.02\n");
	enqueue(new_queue, &f2);
	printf("enqueue 3 3.03\n");
	enqueue(new_queue, &f3);
	printf("enqueue 1 1.01\n");
	int result = enqueue(new_queue, &f1);
	printf("%d\n", result);

	print_dequeue(dequeue(new_queue));
	printf("enqueue 1 1.01\n");
	enqueue(new_queue, &f1);
	print_dequeue(dequeue(new_queue));
	print_dequeue(dequeue(new_queue));
	print_dequeue(dequeue(new_queue));
	return 0;
}

/**
 * helper method for printing the dequeue operation
 */
void print_dequeue(void *ptr) {
	Foo2 *f = (Foo2*) ptr;
	printf("dequeue: %d %f\n", f->x, f->y);
}

/**
 * helper method for printing the queue
 */
void print_queue(Queue* queue, int number) {
	int i;
	printf("head: %d tail: %d\n", queue->head, queue->tail);
	for (i = 0; i < number; i ++) {
		Foo2 *f = (Foo2*)queue->queue_base[i];
		printf("%d %f\n", f->x, f->y);
	}
}
