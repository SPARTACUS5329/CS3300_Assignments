#!/bin/bash

# Create outputs directory if it doesn't exist
mkdir -p ./outputs

# Check if PublicTCs/Input directory exists
if [ ! -d "./PublicTCs/Input" ]; then
    echo "Error: ./PublicTCs/Input directory not found"
    exit 1
fi

# Counter for processed files
processed=0
failed=0

# Go through each file in the Input directory
for input_file in ./PublicTCs/Input/*; do
    # Skip if not a file
    if [ ! -f "$input_file" ]; then
        continue
    fi
    
    # Get just the filename without path
    filename=$(basename "$input_file")
    echo "Processing $filename..."
    
    # Compile the file
    if gcc "$input_file"; then
        # If compilation successful, run and redirect output
        ./a.out > "./outputs/${filename}.txt"
        if [ $? -eq 0 ]; then
            echo "Successfully processed $filename"
            ((processed++))
        else
            echo "Error: Runtime error for $filename"
            ((failed++))
        fi
    else
        echo "Error: Compilation failed for $filename"
        ((failed++))
    fi
    
    # Clean up the executable
    rm -f ./a.out
done

# Print summary
echo "----------------------------------------"
echo "Processing complete!"
echo "Successfully processed files: $processed"
echo "Failed files: $failed"
echo "Outputs saved in ./outputs/ directory"
