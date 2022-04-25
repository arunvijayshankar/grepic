#include <stdio.h>
#include "string.h"
#include "../src/grepiclib.h"
#include "../src/LinkedList.h"

LinkedList * search(char *, FILE *);
LinkedList * search_case_insensitive(char *, FILE *);

void case_sensitive() {
    char *query = "duct";

    FILE *f = fopen("text1.txt", "r"); 
    if (f == NULL) {
        printf("Error opening file `%s`\n", "text1.txt");
        return;
    }

    LinkedList *expected = newList();
    push(&expected, "safe, fast, productive.");
    LinkedList *results = search(query, f);

    if (!LinkedListCmp(expected, results)) {
        printf("Test case_sensitive failed\n");
        printf("Expected:\n");
        printList(expected);
        printf("results:\n");
        printList(results);

    } else {
        printf("found `%s` in:\n", query);
        printList(results);
    }
    LinkedListFree(expected);
    LinkedListFree(results);
}

void case_insensitive() {
    char *query = "rUsT";

    FILE *f = fopen("text2.txt", "r"); 
    if (f == NULL) {
        printf("Error opening file `%s`\n", "text2.txt");
        return;
    }

    LinkedList *expected = newList();
    push(&expected, "Rust");
    push(&expected, "Trust me.");
    LinkedList *results = search_case_insensitive(query, f);

    if (!LinkedListCmp(expected, results)) {
        printf("Test case_insensitive failed\n");
        printf("Expected:\n");
        printList(expected);
        printf("results:\n");
        printList(results);

    } else {
        printf("found `%s` in:\n", query);
        printList(results);
    }
    LinkedListFree(expected);
    LinkedListFree(results);
}

int main() {
    case_sensitive();
    case_insensitive();
}