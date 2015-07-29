#include <stdio.h>
#include "node.h"
#include <stdlib.h>

/**
 * main fucntion for testing the node operation
 */
int main() {
	Tnode* tnode = NULL;
	char *s = (char*) malloc(sizeof(char) * 2);
	s[0] = '1';
	s[1] = '\0';
	
	Tnode *newtnode = add_tnode(tnode, s);
	newtnode = add_tnode(tnode, "0");
	newtnode = add_tnode(tnode, "2");
	printf("%\n%s\n%s\n", newtnode->value, newtnode->left->value, newtnode->right->value);
	print_tree(newtnode);
	free_tree(newtnode);
	return 0;
}

