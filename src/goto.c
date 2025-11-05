#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "path.h"

int goto_bookmark(char const* target){
	char * path = get_path();
	char data[50];
	char index_space[50];
	FILE* fptr;
	fptr = fopen(path,"r");
	if (!fptr){printf("error reading the file \n");
		fclose(fptr);
		return 1;}
	else {
		while(fgets(data,50,fptr)){
				return 1;
			}
		}
	printf("Nothing found \n");
	fclose(fptr);
	return 0;
	}

