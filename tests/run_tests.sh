#!/bin/bash
gcc -g -o ./tests/bin/tests ./tests/tests.c ./src/grepiclib.c ./src/LinkedList.c
./tests/tests