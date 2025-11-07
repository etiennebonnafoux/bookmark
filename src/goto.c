#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "path.h"
#include "entry.h"

int goto_bookmark(char const* target){
	char * path = get_path();
	FILE* fptr;
	fptr = fopen(path,"r");
  if (!fptr){printf("error reading the file \n");return 1;}
  Entry* entry = NULL;
  while((entry = parse_line(fptr)) != NULL){
    if (strcmp(target,entry->key) == 0){
      printf("%s \n",entry->value);
      return 0;
    }
    free(entry);
    entry = NULL;
  }
  printf("No entry found for %s \n", target);
  fclose(fptr);
  return 1;
}

