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

int length(LinkedList *list) {
    LinkedList *crnt = list;
    int len = 0;
    while (crnt != NULL) {
        len++;
        crnt = crnt->next;
    }
    return len;
}

bool LinkedListCmp(LinkedList *list1, LinkedList *list2) {
    if ( length(list1) != length(list2) ) {
        printf("Lengths are different. list1: %d, list2: %d\n", length(list1), length(list2));
        return false;
    }
    LinkedList *crnt1 = list1;
    LinkedList *crnt2 = list2;
    while (crnt1 != NULL) {
        if (strcmp(crnt1->data, crnt2->data) != 0) {
            return false;
        }
        crnt1 = crnt1->next;
        crnt2 = crnt2->next;
    }
    return true;
}