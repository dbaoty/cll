#!/bin/sh

if [ ! -d "out" ]; then
    echo "mkdir -p out"
    mkdir -p out
fi

echo "gcc -Wpedantic -Wall -Wextra -std=c99 -O2 -o out/main src/main.c && valgrind --leak-check=full --track-origins=yes --log-file=out/valgrind.txt -s out/main && cat out/valgrind.txt"

gcc -Wpedantic -Wall -Wextra -std=c99 -O2 -o out/main src/main.c && \
    valgrind --leak-check=full --track-origins=yes --log-file=out/valgrind.txt -s out/main && \
    cat out/valgrind.txt
