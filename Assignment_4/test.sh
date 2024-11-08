#!/bin/bash

# Define color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

mkdir -p ./testcases/generated_output
make

for tac_input in ./testcases/input_tac/*; do
    filename=$(basename "$tac_input")

    query_input="./testcases/input_query/$filename"
    expected_output="./testcases/output/$filename"
    generated_output="./testcases/generated_output/$filename"

    ./a.out "$tac_input" "$query_input" > "$generated_output"

    # Use diff -w to ignore whitespace differences
    if diff -w "$generated_output" "$expected_output" > /dev/null; then
        echo -e "Test $filename: ${GREEN}PASSED${NC}"
    else
        echo -e "Test $filename: ${RED}FAILED${NC}"
        # Display the differences
        diff -w "$generated_output" "$expected_output"
    fi
done
