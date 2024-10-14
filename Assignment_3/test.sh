#!/bin/bash

clear
flex a3.l
bison -d a3.y
gcc lex.yy.c a3.tab.c

# Directory containing test cases
testcase_dir="../Assignment_2/testcases/Testcases/"

# Color codes for green and red
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Loop through all files in the test case directory
for testcase in "$testcase_dir"/*; do
    # Get the base name of the test case file (without path)
    basename=$(basename "$testcase")

    # Create a temporary file with #include<stdio.h> added at the top
    tmpfile=$(mktemp)
    echo "#include<stdio.h>" > "$tmpfile"
    cat "$testcase" >> "$tmpfile"

    # Skip the first line of the modified file and save to prev.txt
    tail -n +2 "$tmpfile" | ../Assignment_2/a.out > prev.txt

    # Run the program on the modified file and save output to new.txt
    ./a.out < "$tmpfile" > new.txt

    # Compare the two outputs
    cmp prev.txt new.txt
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Testcase $basename passed.${NC}"
    else
        echo -e "${RED}Testcase $basename failed.${NC}"
    fi

    # Remove the temporary file
    rm "$tmpfile"

done
