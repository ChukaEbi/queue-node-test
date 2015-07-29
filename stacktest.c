#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct {
  int x;
  double y;
} Foo; // Just some arbitrary struct


int main() {
  const int max_entries = 5; // size of stack
  Foo* new_foo1;
  Foo* new_foo2; 
  Foo* returned_foo;
  Foo* new_foo3;
  Foo* new_foo4;
  Foo* new_foo5;
  Foo*  new_foo6;
  // First, create a stack
  Stack *new_stack = create_stack(max_entries);

  // Allocate a Foo and push it onto the stack.
  new_foo1 = (Foo *) malloc(sizeof(Foo));
  new_foo1->x = 6;
  new_foo1->y = 14.79;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
  push(new_stack, (void *) new_foo1);

  // Allocate another Foo and push it onto the stack.
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 217;
  new_foo2->y = 3.14159;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push(new_stack, (void *) new_foo2);

// Allocate another Foo and push it onto the stack.
  new_foo3 = (Foo *) malloc(sizeof(Foo));
  new_foo3->x = 21;
  new_foo3->y = 35;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo3->x, new_foo3->y);
  push(new_stack, (void *) new_foo3);

// Allocate another Foo and push it onto the stack.
  new_foo4 = (Foo *) malloc(sizeof(Foo));
  new_foo4->x = 2.45;
  new_foo4->y = 67.11;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo4->y);
  push(new_stack, (void *) new_foo4);

// Allocate another Foo and push it onto the stack.
  new_foo5 = (Foo *) malloc(sizeof(Foo));
  new_foo5->x = 73.431;
  new_foo5->y = 18.12;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo5->x, new_foo5->y);
  push(new_stack, (void *) new_foo5);

// Allocate another Foo and push it onto the stack.
  new_foo6 = (Foo *) malloc(sizeof(Foo));
  new_foo6->x = 434;
  new_foo6->y = 63.425;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo6->x, new_foo6->y);
  push(new_stack, (void *) new_foo6);

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stack);
  printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  // Retrieve the Foos and print them.
  returned_foo = (Foo *) pop(new_stack);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stack);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  // Clean up
  delete_stack(new_stack);
  free(new_foo1);
  free(new_foo2);

  return 0;
}
