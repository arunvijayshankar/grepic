#include <stdbool.h>

// struct to store config variables
typedef struct config {
    char *query;
    char *filename;
    bool case_sensitive;
} CONFIG;

CONFIG parse_config(int, char **);
void run(CONFIG);