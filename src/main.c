#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#include "goto.h"
#include "path.h"
#include "list.h"
#include "delete.h"
#include "add.h"

#define VERSION "0.1.0"
#define CHECK_ARG(REQUIRED_COUNT, ERROR_MSG) \
  if (argc < REQUIRED_COUNT){\
    printf(ERROR_MSG "\n");\
    return 1;\
  }

int version(){
  printf("version %s\n",VERSION);
  return 0;
}

int help(){
  printf("Usage : bookmark [-a|-d|-g|-h|-l|--help] [key]\n"
      "Save working directory with a key and print it back\n\n"
      "Options: \n"
      "\t-h, --help\t this message\n"
      "\t-a <key>\t add bookmark\n"
      "\t-d <key>\t delete bookmark\n"
      "\t-g <key>\t print bookmark value\n"
      "\t-v, --version\t the version number\n"
      "version: %s\n",
    VERSION
      );
  return 0;
}
// Read command line argument and choose which action to do
int main(int argc, char **argv) {
  if (argc == 1) {
    return list_bookmark();
  }
  if (strcmp(argv[1], "-a") == 0) {
    CHECK_ARG(3,"A key to add should be given \n")
    return add_bookmark(argv[2]);
  }
  else if (strcmp(argv[1], "-d") == 0) {
    CHECK_ARG(3,"A key to delete should be given \n")
    return delete_bookmark(argv[2]);}

  else if (strcmp(argv[1], "-g") == 0) { 
    CHECK_ARG(3,"A destination should be given \n")
    return goto_bookmark(argv[2]); }
  else if (strcmp(argv[1], "-p") == 0) { return list_bookmark(); }
  else if (strcmp(argv[1], "-v") == 0) { return version();}
  else if (strcmp(argv[1], "--version") == 0) { return version();}
  else if (strcmp(argv[1], "-h") == 0) { return help(); }
  else if (strcmp(argv[1], "--help") == 0) { return help(); }
  else {printf("Error unknow argument %s \n", argv[1]);return 1;}
  return 0;
}

