// MiniC program for finding all permutations of a string

#include<stdio.h>
char string_glob [6];

int swap(char string[], int i, int j)
{
    char dummy[2];
    dummy[1] = '\0';
    dummy[0] = string[i]; 
    string[i] = string[j];
    string[j] = dummy[0];

    return 0;
}

int permutRec(char string[], int ind)
{
    int i;
    i = ind;
    
    // Base Case
    if(ind == 4)
    {
        printf("%s\n", string);
    }
    else
    {
        while(i < 5)
        {
            // Swapping
            swap(string, ind, i);

            // First ind+1 characters fixed
            permutRec(string, ind + 1);

            // Backtrack
            swap(string, ind, i);

            //Increment
            i = i + 1;
        }
    }
    return 0;
}

int permut(char string[])
{
    permutRec(string, 0);

    return 0;
}
  
int main() 
{
    string_glob[0] = 'A';  string_glob[1] = 'B';
    string_glob[2] = 'C';  string_glob[3] = 'D';
    string_glob[4] = 'E';  string_glob[5] = '\0';
    
    permut(string_glob);

    return 0;
}
