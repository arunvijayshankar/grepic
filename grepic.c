#include <stdio.h>

int main(int argc, char **argv) {
    char *query = argv[1];
    char *filename = argv[2];

    printf("Searching for %s\n", query);
    printf("In file %s\n", filename);
}