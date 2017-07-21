/**
 * File Line Count
 * http://www.cprogramming.com/challenges/count.html
 *
 * @author: Kyler Smith, 2017
 */
///////////////////////////////////////////////////////////////////////
// INCLUDES
#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////
// GLOBALS

///////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES

/**
 * Entry point for the program.
 */
int main(int argc, const char * argv[]) {
    
    char *fileName = malloc(sizeof(char) * 128), *buffer = NULL;
    ssize_t read;
    size_t len = 0;
    int lineCount = 0;
    printf("Enter a file: ");
    scanf("%s", fileName);
    
    FILE *fp;
    fp = fopen(fileName, "r");
    
    if(fp == NULL) {
        printf("File not found. Exiting.\n");
        return 1;
    }
    
    while((read = getline(&buffer, &len, fp)) != -1) {
        ++lineCount;
    }
    
    fclose(fp);
    
    printf("Line count: %d\n", lineCount);
    return 0;
}
