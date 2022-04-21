// struct to store config variables
struct config {
    char *query;
    char *filename;
};

struct config parse_config(int, char **);
void run(struct config);