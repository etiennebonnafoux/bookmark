#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define DEFAULT_PATH "~/.bookmark";

// Get the path name from environment
// if not set get the default
// then check file exist otherwise create it
char * get_path(){
  char* hdir = getenv("HOME");
  char* path = (char* )malloc(strlen(hdir)+11*sizeof(hdir[0]));
  strcpy(path,hdir);
  strcat(path,"/.bookmark");
  return path;
}

char* get_path_swap(){
  char* hdir = getenv("HOME");
  char* swap_path = (char* )malloc(strlen(hdir)+17*sizeof(hdir[0]));
  strcpy(swap_path,hdir);
  strcat(swap_path,"/.swap_bookmark");
  return swap_path;
}

int create_file_if_not_exist(char* path){
 FILE* fptr = fopen(path,"r");
 if (fptr == NULL){
   fptr = fopen(path,"w");
   fclose(fptr);
   return 0;
 }
 fclose(fptr);
 return 0;
}
