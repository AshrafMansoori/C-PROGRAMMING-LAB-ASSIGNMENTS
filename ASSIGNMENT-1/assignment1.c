#include <stdio.h>

#define MAX 100

int marks[MAX], n;

// Function to input marks
void inputMarks() {
    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter marks:\n");
    for(int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
}

// Function to display marks
void displayMarks() {
    if(n == 0) {
        printf("No records found!\n");
        return;
    }

    printf("\nStudent Marks:\n");
    for(int i = 0; i < n; i++) {
        printf("Student %d = %d\n", i + 1, marks[i]);
    }
}

// Function to find highest marks
void highestMarks() {
    int max = marks[0];

    for(int i = 1; i < n; i++) {
        if(marks[i] > max)
            max = marks[i];
    }

    printf("Highest Marks = %d\n", max);
}

// Function to find lowest marks
void lowestMarks() {
    int min = marks[0];

    for(int i = 1; i < n; i++) {
        if(marks[i] < min)
            min = marks[i];
    }

    printf("Lowest Marks = %d\n", min);
}

// Function to calculate total
void totalMarks() {
    int sum = 0;

    for(int i = 0; i < n; i++)
        sum += marks[i];

    printf("Total Marks = %d\n", sum);
}

// Function to calculate average
void averageMarks() {
    int sum = 0;

    for(int i = 0; i < n; i++)
        sum += marks[i];

    printf("Average Marks = %.2f\n", (float)sum / n);
}

// Function to search marks
void searchMarks() {
    int key, found = 0;

    printf("Enter marks to search: ");
    scanf("%d", &key);

    for(int i = 0; i < n; i++) {
        if(marks[i] == key) {
            printf("Marks found at Student %d\n", i + 1);
            found = 1;
        }
    }

    if(found == 0)
        printf("Marks not found!\n");
}

// Function to sort marks
void sortMarks() {
    int temp;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(marks[j] > marks[j + 1]) {
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    printf("Marks sorted successfully.\n");
}

int main() {

    int choice, result;
    n = 0;

    do {
        printf("\n========== Student Marks Analyzer ==========\n");
        printf("1. Enter Marks\n");
        printf("2. Display Marks\n");
        printf("3. Highest Marks\n");
        printf("4. Lowest Marks\n");
        printf("5. Total Marks\n");
        printf("6. Average Marks\n");
        printf("7. Search Marks\n");
        printf("8. Sort Marks\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        result = scanf("%d", &choice);
        
        // Clear buffer if scanf failed
        if(result != 1) {
            while(getchar() != '\n');
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch(choice) {

            case 1:
                inputMarks();
                break;

            case 2:
                displayMarks();
                break;

            case 3:
                highestMarks();
                break;

            case 4:
                lowestMarks();
                break;

            case 5:
                totalMarks();
                break;

            case 6:
                averageMarks();
                break;

            case 7:
                searchMarks();
                break;

            case 8:
                sortMarks();
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