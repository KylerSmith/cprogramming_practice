/* File size
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
const char B = 'B';

///////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
double convertSize(long bytes);
char* getStr(long bytes);

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
    
    printf("Size: %.1f%s\n", convertSize(size), getStr(size));
    fclose(fp);
    return 0;
}

/**
 * Converts the size of the file.
 *
 * @param bytes: file size in bytes.
 * @return size converted.
 */
double convertSize(long bytes) {
    long size = bytes;
    if(size < 1024) {
        return bytes; 	                                // bytes < 1 KB
    } else if(size < (1024*1024)) {
        return ((double)bytes / 1024);                  // bytes < 1 MB
    } else if (size < (1024*1024*1024)) {
        return (double)bytes / (1024*1024);             // bytes < 1 GB
    } else {
        return (double)bytes /  (1024*1024*1024);
    }
}

char* getStr(long bytes) {
    long size = bytes;
    char* str = "";

    if(size < 1024) {
        return " B"; 	                                // bytes < 1 KB
    } else if(size < (1024*1024)) {
        return "KB";            		      // bytes < 1 MB
    } else if (size < (1024*1024*1024)) {
        return "MB"; 			            // bytes < 1 GB
    } else {
        return "GB";
    }
}


