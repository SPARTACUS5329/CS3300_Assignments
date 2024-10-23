#!/bin/bash

# Clean and build
make clean
make

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Create directory for produced outputs if it doesn't exist
mkdir -p produced_outputs

# Count the number of input files
num_tests=$(ls inputs/input*.txt | wc -l)

# Test case loop
for ((i=1; i<=num_tests; i++)); do
    # Run the executable with input<i>.txt and store the output in produced_outputs/output<i>.txt
    ./a.out < inputs/input$i.txt > produced_outputs/output$i.txt
    
    # Compare the produced output with the expected output ignoring newlines
    if diff -wB produced_outputs/output$i.txt outputs/output$i.txt > /dev/null; then
        echo -e "${GREEN}Testcase $i passed${NC}"
    else
        echo -e "${RED}Testcase $i failed${NC}"
    fi
done

# Clean up after tests
make clean
