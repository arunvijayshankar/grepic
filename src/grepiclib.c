#include <stdio.h>
#include "string.h"
#include <assert.h>
#include "grepiclib.h"

struct config parse_config(int argc, char **args) {
    assert(argc == 3 && "Not enough arguments");
    struct config nConfig;
    nConfig.query = args[1];
    nConfig.filename = args[2];

    return nConfig;
}

void run(struct config nConfig) {
    char str[100];
    FILE *f = fopen(nConfig.filename, "r"); 
    if (f == NULL) {
        printf("Error opening file `%s`\n", nConfig.filename);
        return;
    }
    printf("With text:\n");
    // use fgets to read each line in filename into str
    while (fgets(str, 100, f) != NULL) {
        fputs(str, stdout); // use fputs to print the line to stdout 
    }
    printf("\n");
    fclose(f);
}