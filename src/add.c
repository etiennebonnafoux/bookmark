#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "entry.h"
#include "path.h"

#define BUFFER_SIZE 1000

int add_bookmark(const char* key_to_add){
  int found = 0; // signal that the key already existe
  char value_to_add[BUFFER_SIZE];
  if (getcwd(value_to_add,BUFFER_SIZE) == NULL){
    printf("Error getting the current working directory\n");
    printf("%s\n",strerror(errno));
    return 1;
  }
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
    if (strcmp(entry->key,key_to_add) != 0){
      fprintf(fptr_swp, "%s\t%s\n",entry->key,entry->value);
    }
    else {
      fprintf(fptr_swp, "%s\t%s\n",key_to_add,value_to_add);
      found=1;
    }
    free(entry);
    entry = NULL;
  }
  if (found == 0){
    fprintf(fptr_swp, "%s\t%s\n",key_to_add,value_to_add);
  }
  fclose(fptr);
  fclose(fptr_swp);
  int err ;
  if ((err=remove(path))!=0){printf("Error removing the file");return 1;};
  if ((err=rename(path_swap,path))!=0){printf("Error coping the file : error %s \n",strerror(errno)); return 1;};
  free(path_swap);
  return 0;
}
