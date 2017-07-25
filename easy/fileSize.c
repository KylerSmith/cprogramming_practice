/* 
 * File size
 * http://www.cprogramming.com/challenges/file_size.html
 *
 * @author: Kyler Smith, 2017
 */
///////////////////////////////////////////////////////////////////////
// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////
// GLOBALS

///////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES

/**
 * Entry point for the program.
 */
int main(int argc, const char * argv[]) {
    
    char *fileName = malloc(sizeof(argv[1]));
    strcpy(fileName, argv[1]);
    
    FILE *fp;
    fp = fopen(fileName, "r");
    
    if(fp == NULL) {
        printf("File not found. Exiting.\n");
        return 1;
    }
   

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp); 
    printf("size: %ld\n", size);
    
    fclose(fp);
    return 0;
}
