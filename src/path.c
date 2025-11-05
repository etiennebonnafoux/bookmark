#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define DEFAULT_PATH "~/.bookmark";

// Get the path name from environment
// if not set get the default
// then check file exist otherwise create it
char * get_path(){
  char* path = getenv( "BOOKMARK_PATH" );
  if (!path){
    char* homedir = getenv("HOME");
    if(!homedir){
      printf("No Home");
    }
    strcat(homedir,"/.bookmark");
    return homedir;
  }
  if (path[0]=='\0'){
    return DEFAULT_PATH;
  }

  if (isspace(path[0])){
    return DEFAULT_PATH;
  }

  return path;

}
