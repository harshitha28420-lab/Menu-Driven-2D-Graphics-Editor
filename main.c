#include <stdio.h>

// Function Prototypes
void input(char *str);
void concatenate_strings(char *str1, char *str2);
void display(char *str);

int main() {
    // Define buffers large enough to hold the strings
    char s1[100], s2[50]; 

    printf("Enter the first string:\n");
    input(s1);

    printf("Enter the second string:\n");
    input(s2);

    /*concatenate strings*/
    concatenate_strings(s1, s2);

    /*display the concatenated string*/
    display(s1);

    return 0;
}

void input(char *str) {
    // Using fgets to safely read strings including spaces
    // The trailing newline character is removed for cleaner output
    fgets(str, 100, stdin);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

void concatenate_strings(char *str1, char *str2) {
    int i = 0, j = 0;

    // 1. Traverse to the end of the first string
    while (str1[i] != '\0') {
        i++;
    }

    // 2. Append the second string to the first string
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }

    // 3. Add null terminator at the end
    str1[i] = '\0';
}

void display(char *str) {
    // Corrected printf to include the string argument
    printf("Concatenated Result: %s\n", str);
}