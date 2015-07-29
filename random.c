#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include <time.h>
char* randUpperString(int length);

/**
 * main function for testing the randomized queue generation
 */
int main() {
  srand(time(0));
  int length = 11;
  char *s1 = randUpperString(length);
  char *s2 = randUpperString(length);
  char *s3 = randUpperString(length);
  char *s4 = randUpperString(length);
  char *s5 = randUpperString(length);

  Tnode *tnode = add_tnode(tnode, s1);
  tnode = add_tnode(tnode, s2);
  tnode = add_tnode(tnode, s3);
  tnode = add_tnode(tnode, s4);
  tnode = add_tnode(tnode, s5);

  print_tree(tnode);
  free_tree(tnode);
  return 0;
}

/**
 * generate uppercase character
 */
char randUpper() {
  int r; // Random number 0 to RAND_MAX
  int i; // Random number 0 to 25
  char c; // Random character A through Z.

  r = random();
  i = r % 26; // Readuce to 0 through 25.
  c = 'A' + i; // The upper-case characters are contiguous in ASCII.
  return c;
}

/** Generate a null-terminated string of random Upper-Case 
 * ASCII characters, A through Z,
 * with specified length. The string is allocated using malloc().
 *
 * @param length Number of characters in the string 
 *        (not counting the terminator).
 * @return The character
 *
 * Note: This function uses the standard function random(), so it will always
 * return the same sequence of random characters, unless you first call 
 * srand() with a different seed. For example, srand(time(0))
 * Should give you a different sequence each time.
*/

char* randUpperString(int length) {
  char* str; // Generated string.
  char c; // Random character
  char i; // Loop counter

  str = malloc(length + 1); // Alocate space for string
  for (i = 0; i < length; i++) { // Generate right number of characters
    str[i] = randUpper();
  }
  str[length] = '\0'; // Add terminator character

  return str;
}
