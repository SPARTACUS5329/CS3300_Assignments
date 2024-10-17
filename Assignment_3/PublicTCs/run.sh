#!/bin/bash

# Function to run makefile in a directory and copy a.out outside
function build_and_get_parser
{
    
    # Check if directory is passed as an argument
    if [[ -z "$1" ]]; then
        echo "Error: No directory specified."
        return 1
    fi

    TARGET_DIR="$1"
    
    # Check if the target directory exists
    if [[ ! -d "$TARGET_DIR" ]]; then
        echo "Error: Directory '$TARGET_DIR' does not exist."
        return -1
    fi

    # Store Old directory
    ORIGINAL_DIR=$(pwd)

    echo "$ORIGINAL_DIR"

    # Change to the target directory
    cd "$TARGET_DIR" || { echo "Error: Failed to change to directory '$TARGET_DIR'."; return 1; }

    # Run makefile
    if ! make; then
        echo "Error: Makefile failed."
        exit 1
    fi

    # Check if a.out exists
    if [[ ! -f "a.out" ]]; then
        echo "Error: a.out not found after running Makefile."
        exit -1
    fi

    cp ./a.out "$ORIGINAL_DIR"

    # Check if tac exists
    if [[  -f "tac" ]]; then
        cp ./tac "$ORIGINAL_DIR"
    fi
   

    # Copy a.out to the parent folder where the script resides

    # Clean up the generated files
    rm -f a.out *.tab.c *.tab.h lex.yy.c 
    
    if [[ -f "tac" ]]; then
        rm tac
    fi

    # Come back to original directory
    cd $ORIGINAL_DIR
}

# Function to check if all files in a directory are allowed
function check_if_all_files_valid
{
    # Check if directory is passed as an argument
    if [[ -z "$1" ]]; then
        echo "Error: No directory specified."
        return 1
    fi

    TARGET_DIR="$1"
    
    # Check if the target directory exists
    if [[ ! -d "$TARGET_DIR" ]]; then
        echo "Error: Directory '$TARGET_DIR' does not exist."
        return 1
    fi

    # Set of allowed file names (tac.l, tac.y, Makefile)
    allowed_files=("tac.l" "tac.y" "Makefile" "makefile" "GNUmakefile" "a3.l" "a3.y") 

    # Get list of files in the directory
    for file_path in "$TARGET_DIR"/*; do
        # Extract the filename from the path
        file=$(basename "$file_path")

        # Check if the filename is in the allowed set
        if [[ ! " ${allowed_files[*]} " =~ " ${file} " ]]; then
            echo "Invalid file: $file present"
            echo "Allowed files -> ("a3.l","a3.y","tac.l","tac.y","Makefile","makefile","GNUmakefile")"
            exit 1
        fi
    done

    echo "All files in $TARGET_DIR are allowed."
    return 0
}

# Validate and extract parser from moodle
function get_parser_from_moodle_submission
{
    cd Moodle_Submission

    # Find the zip file in the specified directory
    ZIP_FILE=$(find . -maxdepth 1 -name "*.zip" -print -quit)

    # Check if a zip file was found
    if [[ -z "$ZIP_FILE" ]]; then
        echo "Error: No zip file found in directory '$TARGET_DIR'."
        return 1
    fi

    echo "Found zip file: $ZIP_FILE"

    # Unzip the contents
    unzip -q "$ZIP_FILE" -d .

    # Check if __MACOSX directory is present
    if [[ -d "__MACOSX" ]]; then
        rm -rf __MACOSX
    fi

    # Get the base name of the zip file
    BASENAME=$(basename "$ZIP_FILE")

    # Remove the .zip extension using parameter expansion
    NAME="${BASENAME%.zip}"

    check_if_all_files_valid $NAME

    cd ..
}

# Generate .s files
function generate_assembly
{
    # Compile all .c files in the input directory to .s files
    for c_file in Input/*.c; do
        
        # Check if there are no .c files in the directory
        if [[ ! -e "$c_file" ]]; then
            echo "No .c files found in '$INPUT_DIR'."
            exit 0
        fi

        mkdir -p AssemblyCode

        # Get the base name of the C file (without path and extension)
        base_name=$(basename "$c_file" .c)

        OUTNAME=AssemblyCode/$base_name.s

        # Check if tac is present
        # ./tac < inp.c > tac.txt
        # ./a.out < tac.txt > out.s
        if [[ -f "tac" ]]; then
            ./tac < $c_file > tac.txt
            ./a.out < tac.txt > "$OUTNAME"
        else
            ./a.out < $c_file > "$OUTNAME"
        fi
        # Check if the assembly file was created successfully
        if [[ $? -eq 0 ]]; then
            # echo "Generated assembly file: $SCRIPT_DIR/$base_name.s"
            :
        else
            echo "Failed to generate assembly file for '$c_file'."
        fi
    done
    rm -f tac.txt

    echo "All .s files generated successfully."
}

# Check if the flag passed is -z or -d using `bash run.sh -z` or `bash run.sh -d`
if [[ "$1" == "-z" ]]; then
    # Validate and extract parser from moodle
    get_parser_from_moodle_submission

    NAME=$(find ./Moodle_Submission -mindepth 1 -maxdepth 1 -type d -print -quit)

    build_and_get_parser $NAME

elif [[ "$1" == "-d" ]]; then
    # There will be only one directory present in ./Folder_Submission
    # Get that folder relative directory in NAME
    NAME=$(find ./Folder_Submission -mindepth 1 -maxdepth 1 -type d -print -quit)

    check_if_all_files_valid $NAME
    
    build_and_get_parser $NAME
else
    echo "Invalid flag. Use 
    -z: to validate and extract parser from moodle submission 
    -d: to use directory of source files directly without zip."
    exit 1
fi

generate_assembly

exit 0

# End of file