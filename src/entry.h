#ifndef BOOKMARK_ENTRY
#define BOOKMARK_ENTRY
#include <stdio.h>

#define MAX_FIELD_SIZE 100
#define MAX_LINE_BUFFER (2 * MAX_FIELD_SIZE + 5)

typedef struct {
	char key[MAX_FIELD_SIZE];
	char value[MAX_FIELD_SIZE];
} Entry;

/*parse a line and separate the key and the value
Suppose that they are separeted by a whitespace
Return a null pointer if there is a key without a value or EOF
*/
Entry *parse_line(FILE *fptr);

#endif
