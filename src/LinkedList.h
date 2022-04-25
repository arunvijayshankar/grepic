#include <stdbool.h>

typedef struct node {
    char data[200];
    struct node *next;
} LinkedList;

LinkedList * newList();
void push(LinkedList **, char *);
char * get(LinkedList *);
void printList(LinkedList *);
void LinkedListFree(LinkedList *);
int length(LinkedList *);
bool LinkedListCmp(LinkedList *, LinkedList *);