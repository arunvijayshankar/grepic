#!/bin/bash
gcc -g -o ./target/grepic ./src/*.c
./target/grepic $1 $2