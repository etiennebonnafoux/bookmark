#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "entry.h"
#include "path.h"


int delete_bookmark(const char* key_to_delete){
  char* path = get_path();
  char* path_swap = get_path_swap();
  FILE* fptr;
  FILE* fptr_swp;
  fptr = fopen(path,"r");
  if (!fptr){printf("error reading the file \n"); return 1;}
  fptr_swp = fopen(path_swap,"w");
  if (!fptr_swp){printf("error while opening the swap file \n");fclose(fptr);return 1;}
  Entry* entry = NULL;
  while ((entry =  parse_line(fptr))!=NULL){
    if (strcmp(entry->key,key_to_delete) != 0){
      fprintf(fptr_swp, "%s\t%s\n",entry->key,entry->value);
    }
    free(entry);
    entry = NULL;
  }
  fclose(fptr);
  fclose(fptr_swp);
  int err ;
  if ((err=remove(path))!=0){printf("Error removing the file");return 1;};
  if ((err=rename(path_swap,path))!=0){printf("Error coping the file : error %s \n",strerror(errno)); return 1;};
  free(path_swap);
  return 0;
}
