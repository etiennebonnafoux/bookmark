#include <stdio.h>
#include <stdlib.h>
#include "entry.h"
#include "path.h"

/*List all entries in the bookmark*/
int list_bookmark() { 
  char * path = get_path();
  create_file_if_not_exist(path);
  FILE* fptr;
  fptr = fopen(path,"r");
  if (!fptr){printf("error reading the file \n"); return 1;}
  Entry* entry = NULL;
  while((entry = parse_line(fptr)) != NULL){
    printf("%s \t %s\n ",entry->key,entry->value);
    free(entry);
    entry = NULL;
  }
  fclose(fptr);
  return 0; 
  }
