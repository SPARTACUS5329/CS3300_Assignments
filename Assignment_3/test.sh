#!/bin/bash

# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Create a function to run tests for a single file
run_test() {
    local input_file=$1
    
    # Make sure we start clean
    make clean
    rm -f a.out myout gccout myout.txt gccout.txt
    
    # Step 1: Run make
    make > /dev/null 2>&1
    
    if [ ! -f "a.out" ]; then
        echo -e "${RED}Failed $input_file - make failed${NC}"
        return
    fi
    
    # Step 2: Run the assembly program with input
    ./a.out < "$input_file" 2>/dev/null
    
    # Step 3: Compile the assembly output
    gcc -m32 a.s -o myout 2>/dev/null
    if [ $? -ne 0 ]; then
        echo -e "${RED}Failed $input_file - assembly compilation failed${NC}"
        return
    fi
    
    # Step 4: Run the compiled assembly program
    ./myout > myout.txt 2>/dev/null
    
    # Step 5: Compile the original C file
    gcc "$input_file" -o gccout 2>/dev/null
    if [ $? -ne 0 ]; then
        echo -e "${RED}Failed $input_file - gcc compilation failed${NC}"
        return
    fi
    
    # Step 6: Run the compiled C program
    ./gccout > gccout.txt 2>/dev/null
    
    # Step 7: Compare outputs
    if diff -q myout.txt gccout.txt >/dev/null; then
        echo -e "${GREEN}Passed $input_file${NC}"
    else
        echo -e "${RED}Failed $input_file${NC}"
    fi
    
    # Clean up
    rm -f a.out myout gccout myout.txt gccout.txt
}

# Main script
echo "Starting tests..."

# Check if directory exists
if [ ! -d "./PublicTCs/Input" ]; then
    echo "Error: Directory ./PublicTCs/Input not found!"
    exit 1
fi

# Process each file in the directory
for input_file in ./PublicTCs/Input/*; do
    if [ -f "$input_file" ]; then
        run_test "$input_file"
    fi
done

echo "Testing complete."
