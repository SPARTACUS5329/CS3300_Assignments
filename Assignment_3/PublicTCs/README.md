### If you are using `.zip` submission format
1. First put your zip file in the directory named "Moodle_Submission".
2. Run `bash run.sh -z` (Which makes and generates all assembly output files from your submission)
3. Run `sudo bash run_docker.sh` (Which assumes docker is already installed and running in your machine).
4. After the docker is launched, run `bash test.sh` and check your outputs.

### If you are using just submission files without zipping
1. First put all your source code files in directory named "Roll_Number" in "Folder_Submission" directory.
2. Run `bash run.sh -d` (Which makes and generates all assembly output files from your submission)
3. Run `sudo bash run_docker.sh` (Which assumes docker is already installed and running in your machine).
4. After the docker is launched, run `bash test.sh` and check your outputs.

### Note:
1. If you change a file locally, it will not be reflected in an already built docker container. You will have to re-run `bash run_docker`.
2. If a file is changed in docker, it will not be reflected in your local machine as well.
3. Ref_Output directory is only for reference, it is not used for any testing.
4. We will test using `bash run.sh -z` without any flags using the zip submission. So, make sure it runs properly.