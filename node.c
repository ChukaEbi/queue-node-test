/** node.c
 *  @author Chuka Ebi
 *  Functions to add values to tnode, sort and print tree out and free tree.
 */
#include "node.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** add node to root or any node
 *
 */

Tnode *add_tnode(Tnode *current_tnode, char* value) {
    // for leaf or root
	if (current_tnode == NULL) {
		Tnode *new_node = (Tnode*)malloc(sizeof(Tnode));
        // make sure initial value is null
		new_node->left = NULL;
		new_node->right = NULL;
		int length = strlen(value);
        // alloc memory for new value
		new_node->value = (char*)malloc(sizeof(char) * length);
        // copy value to structure field
		strcpy(new_node->value, value);

		return new_node;
	} else {
        // compare value
		int cmp = strcmp(current_tnode->value, value);
		if (cmp <= 0) {
		    // recursion on right child
			current_tnode->right = add_tnode(current_tnode->right, value);
			return current_tnode;
		} else {
            // recursion on left child
			current_tnode->left = add_tnode(current_tnode->left, value);
			return current_tnode;
		}
	}
}

/**
 * recursively print the node tree
 */
void print_tree(Tnode *node) {
	if (node == NULL) {
		return;
	}
	print_tree(node->left);
	printf("%s\n", node->value);
	print_tree(node->right);
}

/** 
 *  recursivley free node
 */
void free_tree(Tnode *node) {
	if (node == NULL) {
		return;
	}
	free_tree(node->left);
	free(node->value);
	free_tree(node->right);
	free(node);

}
