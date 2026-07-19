#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str[100];

// Function to input string
void inputString() {
    printf("Enter a string: ");
    getchar(); // Clear input buffer
    fgets(str, sizeof(str), stdin);

    // Remove newline character
    str[strcspn(str, "\n")] = '\0';
}

// Function to find length
void findLength() {
    printf("Length of string = %lu\n", strlen(str));
}

// Function to reverse string
void reverseString() {
    int len = strlen(str);

    printf("Reversed String: ");

    for(int i = len - 1; i >= 0; i--)
        printf("%c", str[i]);

    printf("\n");
}

// Function to check palindrome
void palindrome() {
    int len = strlen(str);
    int flag = 1;

    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("String is Palindrome.\n");
    else
        printf("String is Not Palindrome.\n");
}

// Function to count vowels
void countVowels() {
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);

        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            count++;
    }

    printf("Number of Vowels = %d\n", count);
}

// Function to count digits
void countDigits() {
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if(isdigit(str[i]))
            count++;
    }

    printf("Number of Digits = %d\n", count);
}

// Function to count spaces
void countSpaces() {
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ')
            count++;
    }

    printf("Number of Spaces = %d\n", count);
}

// Function to display character frequency
void charFrequency() {
    int freq[256] = {0};

    for(int i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;

    printf("\nCharacter Frequency:\n");

    for(int i = 0; i < 256; i++) {
        if(freq[i] != 0)
            printf("%c = %d\n", i, freq[i]);
    }
}

int main() {

    int choice;
    str[0] = '\0';

    do {

        printf("\n========== String Utility Toolkit ==========\n");
        printf("1. Enter String\n");
        printf("2. Find Length\n");
        printf("3. Reverse String\n");
        printf("4. Check Palindrome\n");
        printf("5. Count Vowels\n");
        printf("6. Count Digits\n");
        printf("7. Count Spaces\n");
        printf("8. Character Frequency\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                inputString();
                break;

            case 2:
                findLength();
                break;

            case 3:
                reverseString();
                break;

            case 4:
                palindrome();
                break;

            case 5:
                countVowels();
                break;

            case 6:
                countDigits();
                break;

            case 7:
                countSpaces();
                break;

            case 8:
                charFrequency();
                break;

            case 9:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 9);

    return 0;
}