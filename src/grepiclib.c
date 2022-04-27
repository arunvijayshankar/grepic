#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "grepiclib.h"
#include "LinkedList.h"
#include <stdlib.h>

LinkedList * search(char *, FILE *);
LinkedList * search_case_insensitive(char *, FILE *);

CONFIG parse_config(int argc, char **args) {
    if (argc < 3) {
        fprintf(stderr, "Not enough arguments\n");
    }
    CONFIG nConfig;
    nConfig.query = args[1];
    nConfig.filename = args[2];
    nConfig.case_sensitive = (getenv("CASE_INSENSITIVE") == NULL) ? true : false;
    return nConfig;
}

void run(CONFIG nConfig) {
    FILE *f = fopen(nConfig.filename, "r"); 
    if (f == NULL) {
        fprintf(stderr, "Error opening file `%s`\n", nConfig.filename);
        return;
    }
    printf("With text:\n");
    LinkedList *results;
    if (nConfig.case_sensitive) {
        results = search(nConfig.query, f);
    } else {
        results = search_case_insensitive(nConfig.query, f);
    }
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
        if (line[strlen(line)-1] == '\n') {
            line[strlen(line)-1] = '\0';
        }
        if (strstr(line, query) != NULL) {
            push(&results, line);
        }
    }
    return results;
}

LinkedList * search_case_insensitive(char *query, FILE *f) {
    LinkedList *results = newList();
    char line[200];
    char *query_lower = toLower(query);
    while(fgets(line, sizeof(line), f)) {
        if (line[strlen(line)-1] == '\n') {
            line[strlen(line)-1] = '\0';
        }
        char *line_lower = toLower(line);
        if (strstr(line_lower, query_lower) != NULL) {
            push(&results, line);
        }
        free(line_lower);
    }
    free(query_lower);
    return results;
}

char * toLower(char *q) {
    char *q_low = malloc((strlen(q)+1)*sizeof(char));
    memset(q_low, '\0', sizeof(q_low));
    strncpy(q_low, q, strlen(q));
    for (int i = 0; i < strlen(q_low); i++) {
        if ((q_low[i] >= 65) && (q_low[i] <= 90)) {
            q_low[i] += 32;
        }
    }
    return q_low;
}