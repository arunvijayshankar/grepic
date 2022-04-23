#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "grepiclib.h"
#include "LinkedList.h"
#include <stdlib.h>

LinkedList * search(char *, FILE *);

CONFIG parse_config(int argc, char **args) {
    assert(argc == 3 && "Not enough arguments");
    CONFIG nConfig;
    nConfig.query = args[1];
    nConfig.filename = args[2];

    return nConfig;
}

void run(CONFIG nConfig) {
    FILE *f = fopen(nConfig.filename, "r"); 
    if (f == NULL) {
        printf("Error opening file `%s`\n", nConfig.filename);
        return;
    }
    printf("With text:\n");
    LinkedList *results = search(nConfig.query, f);
    if (results != NULL ) {
       printList(results);
    }
    printf("\n");
    fclose(f);
    LinkedListFree(results);
}

LinkedList * search(char *query, FILE *f) {
    LinkedList *results = newList();
    char line[200];
    while(fgets(line, sizeof(line), f)) {
        if (strstr(line, query) != NULL) {
            push(&results, line);
        }
    }
    return results;
}