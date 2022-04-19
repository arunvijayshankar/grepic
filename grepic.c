#include <stdio.h>
#include "string.h"

int main(int argc, char **argv) { // cmd line args count and strings stored in argc and **argv

    // store relavant cmd line args in variables
    char *query = argv[1];
    char *filename = argv[2];
    // init str buffer to hold strings in text file
    char str[100];
    printf("Searching for `%s`\n", query);
    printf("In file `%s`\n", filename);

    FILE *f = fopen(filename, "r"); 
    if (f == NULL) {
        printf("Error opening file\n");
        return(-1);
    }
    printf("With text:\n");
    // use fgets to read each line in filename into str
    while (fgets(str, 100, f) != NULL) {
        fputs(str, stdout); // use fputs to print the line to stdout 
    }
    printf("\n");
    fclose(f);
}