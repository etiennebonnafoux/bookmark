#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#include "goto.h"
#include "path.h"
#include "list.h"



int add_bookmark(){
  printf("Adding bookmark");
  return 0;
}

int delete_bookmark(const char* key_to_delete){
  printf("deleting some bookmark");
  char * path = get_path();
  char data[50];
  FILE* fptr;
  FILE* fptr_swp;
  fptr = fopen(path,"r");
  fptr_swp = fopen("swap_bookmark","w");
  if (!fptr){printf("error reading the file \n"); return 1;}
  if (!fptr_swp){printf("error while opening the swap file \n");}
  int index_space = 0;
  while(fgets(data,50,fptr)){
    for (int i =0; i<50; i++){
      if (&data[i] == " ")
      {printf("finding the white space \n");
        index_space = i;}
    }
    if (index_space == 50){
      printf("Error line without value %s \n",data);
      fclose(fptr);
      fclose(fptr_swp);
      return 1;
    }
    fprintf(fptr_swp,data);
  }
  return 0;
}

int help(){
  printf("Help");
  return 0;
}
// Read command line argument and choose which action to do
int main(int argc, char **argv) {
  if (argc == 1) {
    return list_bookmark();
  }
  if (strcmp(argv[1], "-a") == 0) {
    return add_bookmark();
  }
  else if (strcmp(argv[1], "-d") == 0) {
    if (argc == 2){
      printf("A key to delete should be given \n");
      return 1;
    }
    return delete_bookmark(argv[2]);}

  else if (strcmp(argv[1], "-g") == 0) { 
    if (argc == 2){
      printf("A destination should be given \n");
      return 1;
    }
    return goto_bookmark(argv[2]); }
  else if (strcmp(argv[1], "-p") == 0) { return list_bookmark(); }
  else if (strcmp(argv[1], "-h") == 0) { return help(); }
  else if (strcmp(argv[1], "--help") == 0) { return help(); }
  else {printf("Error unknow argument %s \n", argv[1]);return 1;}
  return 0;
}

