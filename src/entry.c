#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXBUFFER 50

typedef struct {
	char key[MAXBUFFER];
	char value[MAXBUFFER];
}
 Entry;

/*parse a line and separate the key and the value
Suppose that they are separeted by a whitespace
Return a null pointer if there is a key without a value or EOF
*/
Entry *parse_line(FILE *fptr){
  char line_buffer[MAXBUFFER] ;
  if (fgets(line_buffer,MAXBUFFER,fptr) == NULL){
    return NULL;
  };
  Entry *entry = (Entry *)malloc(sizeof(Entry));
  if (entry == NULL){
    perror("Failed to allocate memory for new entry");
    return NULL;
  }
  int result = sscanf(line_buffer, "%49s %49s",entry->key,entry->value);
  if (result != 2){
    free(entry);
    return NULL;
  }
  return entry;
}
