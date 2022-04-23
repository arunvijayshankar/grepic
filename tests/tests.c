#include <stdio.h>
#include "string.h"
#include "../src/grepiclib.h"

void one_result() {
    char *query = "duct";
    char *contents[] = {"Rust", "safe, fast, productive.", "Pick three."};

    if (!strcmp("safe, fast, productive.", search(query, contents, 3)) == 0) {
        printf("Test one_result failed. search did not return `safe, fast, productive.`\n");
    } else {
        printf("found `%s` in `%s`\n", query, search(query, contents, 3));
    }
}

int main() {
    one_result();
}