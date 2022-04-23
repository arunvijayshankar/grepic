// struct to store config variables
typedef struct config {
    char *query;
    char *filename;
} CONFIG;

CONFIG parse_config(int, char **);
void run(CONFIG);