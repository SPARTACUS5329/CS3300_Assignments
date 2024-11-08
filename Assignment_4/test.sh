#!/bin/bash

mkdir -p ./testcases/generated_output
make

for tac_input in ./testcases/input_tac/*; do
    filename=$(basename "$tac_input")

    query_input="./testcases/input_query/$filename"
    expected_output="./testcases/output/$filename"
    generated_output="./testcases/generated_output/$filename"

    ./a.out "$tac_input" "$query_input" > "$generated_output"

    if cmp -s "$generated_output" "$expected_output"; then
        echo "Test $filename: PASSED"
    else
        echo "Test $filename: FAILED"
        cmp "$generated_output" "$expected_output"
    fi
done
