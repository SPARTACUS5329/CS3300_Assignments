#!/bin/bash

function compare_outputs
{
    totalcount=0
    count=0

    # Check if the output directory exists
    if [[ ! -d "AssemblyCode" ]]; then
        echo "Error: AssemblyCode directory not found."
        return 1
    fi

    # Check if the reference directory exists
    if [[ ! -d "Input" ]]; then
        echo "Error: Input directory not found."
        return 1
    fi

    mkdir -p AssemblyOut Cout

    # Compare the output of the generated assembly files with the input's .out files
    for s_file in AssemblyCode/*.s; do

        # Get the base name of the S file (without path and extension)
        base_name=$(basename "$s_file" .s)

        # Check if the corresponding .out file exists
        if [[ ! -f "Cout/$base_name.out" ]]; then
            # Create .out using gcc
            # Disable compiler warnings
            gcc -o Cout/$base_name.out Input/$base_name.c 
            

            ./Cout/$base_name.out > Cout/$base_name.txt
        fi

        # Run gcc -m32 .s -o .out
        gcc -m32 "$s_file" -o "AssemblyOut/$base_name.out" &>/dev/null
        ./AssemblyOut/$base_name.out > AssemblyOut/$base_name.txt

        # Update totalcount
        totalcount=$((totalcount+1))

        # Compare the generated output with the reference output
        # No need to print the output of diff
        # diff -q "AssemblyOut/$base_name.txt" "Cout/$base_name.txt"
        diff "AssemblyOut/$base_name.txt" "Cout/$base_name.txt" &>/dev/null

        # Check if the files are identical
        # Print the first echo in green and the second in red
        if [[ $? -eq 0 ]]; then
            # echo "Testcase '$base_name' passed."
            echo -e "\e[32mTestcase '$base_name' passed.\e[0m"
            count=$((count+1))
        else
            # echo "Testcase '$base_name' failed."
            echo -e "\e[31mTestcase '$base_name' failed.\e[0m"
        fi
    done
    
    rm Cout/*.out AssemblyOut/*.out
    # Print the total number of testcases passed / total testcases
    echo "Passed $count/$totalcount testcases."
    
}

compare_outputs

# End of file