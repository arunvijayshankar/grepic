#include <stdio.h>
#include "string.h"
#include "grepiclib.h"

int main(int argc, char **argv) { // cmd line args count and strings stored in argc and **argv
    // function to parse cmd line args
    struct config nConfig = parse_config(argc, argv);

    // init str buffer to hold strings in text file
    printf("Searching for `%s`\n", nConfig.query);
    printf("In file `%s`\n", nConfig.filename);
    run(nConfig);
}
