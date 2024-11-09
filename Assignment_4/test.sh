#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

make

for tac_input in ./input_tac/*; do
    filename=$(basename "$tac_input")

    query_input="./input_query/$filename"
    expected_output="../testcases/output/$filename"
    generated_output="./$filename"

    ./a.out "$tac_input" "$query_input"

    if diff -w "$generated_output" "$expected_output" > /dev/null; then
        echo -e "${GREEN}SUCCESS${NC}: Test $filename"
    else
        echo -e "${RED}FAILED${NC}: Test $filename"
        diff -w "$generated_output" "$expected_output"
    fi
done
