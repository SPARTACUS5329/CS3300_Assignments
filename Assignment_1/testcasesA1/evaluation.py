import os
import subprocess
import filecmp
import sys
# Directories
cur_dir_path = os.path.dirname(os.path.realpath(__file__))
input_files_dir = cur_dir_path+'/inputs'
expected_output_dir = cur_dir_path+'/outputs'
output_dir = cur_dir_path+'/userOutput'

# Ensure output directory exists
os.makedirs(output_dir, exist_ok=True)

# Function to compare output files
def compare_files(output_file, expected_file):
    if filecmp.cmp(output_file, expected_file, shallow=False):
        return 1
    else:
        return 0
    
subprocess.run(['make'])
matched_files_count = 0

# Run the a.exe/a.out executable with each input file
for input_file in os.listdir(input_files_dir):
    input_path = os.path.join(input_files_dir, input_file)
    output_file = os.path.join(output_dir, f"output{input_file[5:-4]}.txt")

    with open(input_path, 'r') as inp, open(output_file, 'w') as outp:
        try:
            subprocess.run(['./a.exe'], stdin=inp, stdout=outp)
        except:
            try:
                subprocess.run(['./a.out'], stdin=inp, stdout=outp)
            except:
                print("a.out or a.exe both file not found.")
                print("Number of testcases passed:0")
                sys.exit()
    # Compare the generated output with the expected output
    expected_output_file = os.path.join(expected_output_dir, f"output{input_file[5:-4]}.txt")
    matched = compare_files(output_file, expected_output_file)
    matched_files_count += matched

# Write the result to a .result file
result_file = os.path.join(output_dir, f"result.txt")
with open(result_file, 'w') as res_file:
    res_file.write(f"Matched files: {matched_files_count}\n")

print("Number of testcases passed:",matched_files_count)


