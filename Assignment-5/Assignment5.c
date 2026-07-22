#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *marks;
    int sum = 0;
    float average;
    int highest, lowest;

    printf("=====================================\n");
    printf("   Dynamic Array Management System\n");
    printf("=====================================\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    marks = (int *)malloc(n * sizeof(int));

    if (marks == NULL) {
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    // Input marks
    printf("\nEnter marks of %d students:\n", n);

    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    // Initialize highest and lowest
    highest = lowest = marks[0];

    // Calculate statistics
    for (i = 0; i < n; i++) {
        sum += marks[i];

        if (marks[i] > highest)
            highest = marks[i];

        if (marks[i] < lowest)
            lowest = marks[i];
    }

    average = (float)sum / n;

    // Display marks
    printf("\n------ Student Marks ------\n");

    for (i = 0; i < n; i++) {
        printf("Student %d = %d\n", i + 1, marks[i]);
    }

    // Display statistics
    printf("\n------ Statistics ------\n");
    printf("Total Marks : %d\n", sum);
    printf("Average     : %.2f\n", average);
    printf("Highest     : %d\n", highest);
    printf("Lowest      : %d\n", lowest);

    // Free allocated memory
    free(marks);
    marks = NULL;

    printf("\nMemory released successfully.\n");

    return 0;
}