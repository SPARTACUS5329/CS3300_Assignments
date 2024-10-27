#!/bin/bash
# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Create outputs directory if it doesn't exist
mkdir -p ./outputs

# Create a function to run tests for a single file
run_test() {
    local input_file=$1
    local filename=$(basename "$input_file")
    local expected_output="./outputs/${filename}.txt"
    
    # Make sure we start clean
    make clean
    rm -f a.out myout gccout myout.txt gccout.txt
    
    # Step 1: Run make
    make > /dev/null 2>&1
    
    if [ ! -f "a.out" ]; then
        echo -e "${RED}Failed $filename - make failed${NC}"
        return 1
    fi
    
    # Step 2: Run the assembly program with input
    ./a.out < "$input_file" 2>/dev/null
    
    # Step 3: Compile the assembly output
    gcc -m32 a.s -o myout 2>/dev/null
    if [ $? -ne 0 ]; then
        echo -e "${RED}Failed $filename - assembly compilation failed${NC}"
        return 1
    fi
    
    # Step 4: Run the compiled assembly program
    ./myout > myout.txt 2>/dev/null
    
    # Step 5: Check if expected output exists
    if [ ! -f "$expected_output" ]; then
        echo -e "${RED}Failed $filename - no expected output file found${NC}"
        return 1
    }
    
    # Step 6: Compare outputs with expected output in outputs directory
    if cmp -s myout.txt "$expected_output"; then
        echo -e "${GREEN}Passed $filename${NC}"
    else
        echo -e "${RED}Failed $filename - output mismatch${NC}"
    fi
    
    # Clean up
    rm -f a.out myout gccout myout.txt gccout.txt
}

# Main script
echo "Starting tests..."

# Check if directories exist
if [ ! -d "./PublicTCs/Input" ]; then
    echo -e "${RED}Error: Directory ./PublicTCs/Input not found!${NC}"
    exit 1
fi

if [ ! -d "./outputs" ]; then
    echo -e "${RED}Error: Directory ./outputs not found!${NC}"
    exit 1
fi

# Track statistics
total=0
passed=0
failed=0

# Process each file in the directory
for input_file in ./PublicTCs/Input/*; do
    if [ -f "$input_file" ]; then
        ((total++))
        if run_test "$input_file"; then
            ((passed++))
        else
            ((failed++))
        fi
    fi
done

# Print summary
echo -e "\nTesting complete."
echo -e "Total tests: $total"
echo -e "${GREEN}Passed: $passed${NC}"
echo -e "${RED}Failed: $failed${NC}"
