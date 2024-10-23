#!/bin/bash

# Function to normalize file content
normalize_file() {
  local file="$1"
  # Remove all whitespace characters including spaces, tabs, and newlines
  tr -d '[:space:]' < "$file"
}

# Function to compare two normalized files
compare() {
  local file1="$1"
  local file2="$2"

  # Normalize both files
  local norm_file1=$(normalize_file "$file1")
  local norm_file2=$(normalize_file "$file2")


  # Compare the normalized contents
  if [ "$norm_file1" = "$norm_file2" ]; then
    return 0  # Files match
  else
    return 1  # Files do not match
  fi
}

# Function to check if last line contains the word "zero"
contains_string() {
  local file="$1"
  local s="$2"
  tail -n 1 "$file" | grep -q -m 1 "$s"
}



# Function to compare files after removing alphabetic lines
compare_files() {
  local file="$1"
  local expected_file="$2"

  # Create temporary files for comparison
  local temp_output=$(mktemp)
  local temp_expected=$(mktemp)

  # Remove lines with alphabets and write to temporary files
  grep -v '[a-zA-Z]' "$file" > "$temp_output"
  grep -v '[a-zA-Z]' "$expected_file" > "$temp_expected"


  # Compare the cleaned files
  if compare "$temp_output" "$temp_expected"; then
    return 0  # Files match
  else
    return 1  # Files do not match
  fi
}



evaluate(){
  # Process each file in the output directory for divide by zero
  output_dir="$1"
  expected_dir="$2"
  s="$3"
  for file in "$output_dir"/*.txt; do
    filename=$(basename "$file")
    expected_file="$expected_dir/$filename"

    # Check if the file exists in the expected directory
    if [ -f "$expected_file" ]; then
      # Check the last line for the word "zero"
      if contains_string "$file" "$s"; then
        # Compare the files after removing alphabetic lines
        if compare_files "$file" "$expected_file"; then
          # Increment marks if conditions are met
          ((marks++))
        fi
      fi
    else
      echo "Expected file $expected_file not found."
    fi
  done
}


cd sub
for zip_file in *.zip; do
  marks=0
  unzip "$zip_file" 
  cd "${zip_file%.zip}" || exit

  input_dirs=("../../input/correct" "../../input/zero" "../../input/syntax" "../../input/undef")
  output_dirs=("actual_output/correct" "actual_output/zero" "actual_output/syntax" "actual_output/undef")

  mkdir -p "actual_output"
  for output_dir in "${output_dirs[@]}"; do
    mkdir -p "$output_dir"
  done

  make
  chmod +x l3

  for i in "${!input_dirs[@]}"; do
    input_dir="${input_dirs[$i]}"
    output_dir="${output_dirs[$i]}"
    for file in "$input_dir"/*.txt; do
      filename=$(basename "$file")
      output_file="$output_dir/$filename"
      ./l3 < "$file" > "$output_file" 2>err.txt ; cat err.txt >> "$output_file"
    done
  done

  evaluate "actual_output/correct" "../../output/correct" "."
  evaluate "actual_output/zero" "../../output/zero" "zero"
  evaluate "actual_output/syntax" "../../output/syntax" "syntax"
  evaluate "actual_output/undef" "../../output/undef" "udvar"

  cd ..

  echo "${zip_file%.zip} $marks" >> ../marks.txt

done


