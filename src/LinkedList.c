#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedList.h"

LinkedList * newList() {
    LinkedList *head = NULL;
    return head;
}

void push(LinkedList **list, char *str) {
        LinkedList *head = malloc(sizeof(LinkedList));
        memset(head->data, '\0', strlen(str)+1);
        strncpy(head->data, str, strlen(str));
        head->next = *list;
        *list = head;
}

char * get(LinkedList *list) {
    if (list == NULL) {
        printf("list is empty\n");
        return NULL;
    }
    LinkedList *crnt = list;
    while(crnt->next != NULL) {
        crnt = crnt->next;
    }
    return crnt->data;
}

void printList(LinkedList *list) {
    LinkedList *crnt = list;
    while (crnt != NULL) {
        printf("%s\n", crnt->data);
        crnt = crnt->next;
    }
}

void LinkedListFree(LinkedList *list) {
    free(list);
}