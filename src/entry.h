#ifndef BOOKMARK_ENTRY
#define BOOKMARK_ENTRY
#define MAXBUFFER 50
#include <stdio.h>

typedef struct {
	char key[MAXBUFFER];
	char value[MAXBUFFER];
} Entry;

/*parse a line and separate the key and the value
Suppose that they are separeted by a whitespace
Return a null pointer if there is a key without a value or EOF
*/
Entry *parse_line(FILE *fptr);

#endif
