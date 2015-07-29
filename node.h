#ifndef NODE_H
#define NODE_H

 struct _Tnode{
	char* value;
	struct _Tnode* left;
	struct _Tnode* right;
}; 

typedef struct _Tnode Tnode;

// Function prototypes

/** Function to put a string into a tnode of tree.
 *  @param current_tnode Pointor to a tnode you want to add string.
 *  @param value The string to be added.
 *  @return Pointer to the new allocated Tnode structure.
 */
Tnode *add_tnode(Tnode *current_tnode, char* value);

void print_tree(Tnode *node);
/** Function to free all the nodes in tree.
 *  @param Pointer to the node in tree to free.
 */
void free_tree(Tnode *node);
#endif
