# By default, make all the executables:
all: stacktest queuetest testnode random

# Make each executable:
stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -o stacktest

queuetest: queuetest.o queue.o
	gcc -g queuetest.o queue.o -o queuetest

testnode: node.o testnode.o 
	gcc -g node.o testnode.o -o testnode

random: random.o node.o
	gcc -g node.o random.o -o random

# Compile each source file:
stack.o: stack.c stack.h
	gcc -g -c stack.c

queue.o: queue.c queue.h
	gcc -g -c queue.c

node.o: node.c node.h
	gcc -g -c node.c

random.o: random.c node.h
	gcc -g -c random.c

stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c

queuetest.o: queuetest.c queue.h
	gcc -g -c queuetest.c

testnode.o: testnode.c node.h
	gcc -g -c testnode.c

# Other targets:
clean:
	rm -f *.o
	rm -f stacktest queuetest testnode random

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2301/assig6
