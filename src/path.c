#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define DEFAULT_PATH "/users/l1123180/project/test_c/bookmark/book.txt";

// Get the path name from environment
// if not set get the default
// then check file exist otherwise create it
char * get_path(){
  char * path = getenv( "BOOKMARK_PATH" );
  if (!path){
    return DEFAULT_PATH;
  }
  printf("Path: %s \n",path);
  if (path[0]=='\0'){
    return DEFAULT_PATH;
  }

  if (isspace(path[0])){
    return DEFAULT_PATH;
  }

  return path;

}
