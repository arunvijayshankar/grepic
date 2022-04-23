#!/bin/bash
gcc -g -o ./tests/tests ./tests/tests.c ./src/grepiclib.c ./src/LinkedList.c
./tests/tests