Name: Chuka Ebi	

Username: cebi

List of files:
Doxyfile 
makefile 			  
queue.h 
queue.c 
queuetest.c
node.h 
node.c 
testnode.c
random.c

Description:
Doxyfile: Used to generate HTML files.
makefile: The file translate the program from human-readable form into a which can be executed by the computer.

queue.h:  Contains the function prototypes for queue.c
queue.c:  code which contains the functions for queuetest.c
queuetest.c:  code for executing the functions in queue.c

node.h:  Contains the function prototypes for node.c
node.c: code for each function used in testnode.c and random.c
testnode.c: code for executing the functions in node.c 
random.c:  code for executing functions to generate a random string and test node.c


In terminal
1. make
2../queuetest
dequeue
head: 0 tail: 0
empty test pass
enqueue 1 1.01
head: 0 tail: 0
head: 1 tail: 0
dequeue 1 1.010000
enqueue 1 1.01
head: 1 tail: 1
enqueue 2 2.02
head: 2 tail: 1
head: 3 tail: 1
dequeue 1 1.010000
head: 3 tail: 2
dequeue 2 2.020000
enqueue 1 1.01
head: 3 tail: 3

enqueue 2 2.02
head: 4 tail: 3

head: 5 tail: 3
dequeue 1 1.010000
enqueue 3 3.03
head: 5 tail: 4
head: 6 tail: 4
dequeue 2 2.020000
head: 6 tail: 5
dequeue 3 3.030000
enqueue 1 1.01
head: 6 tail: 6
enqueue 2 2.02
head: 7 tail: 6
enqueue 3 3.03
head: 8 tail: 6
enqueue 1 1.01
head: 9 tail: 6
-1
head: 9 tail: 6
dequeue: 1 1.010000
enqueue 1 1.01
head: 9 tail: 7
head: 10 tail: 7
dequeue: 2 2.020000
head: 10 tail: 8
dequeue: 3 3.030000
head: 10 tail: 9
dequeue: 1 1.010000


3. ./random
DARZOWKKYHI
DDQSCDXRJMO
EFSARCBYNEC
NWLRBBMQBHC
WFRXSJYBLDB


