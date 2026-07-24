#include <stdio.h>
#include <limits.h>

#define MAX 100

void display(int arr[], int n) {
    printf("\nArray: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void largestSmallest(int arr[], int n) {
    int largest = INT_MIN, secondLargest = INT_MIN;
    int smallest = INT_MAX, secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++) {

        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }

        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    printf("\nLargest          : %d", largest);
    printf("\nSecond Largest   : %d", secondLargest);
    printf("\nSmallest         : %d", smallest);
    printf("\nSecond Smallest  : %d\n", secondSmallest);
}

void reverse(int arr[], int n) {
    int temp;

    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    printf("\nArray Reversed Successfully!\n");
}

void removeDuplicates(int arr[], int *n) {

    for (int i = 0; i < *n; i++) {

        for (int j = i + 1; j < *n;) {

            if (arr[i] == arr[j]) {

                for (int k = j; k < *n - 1; k++)
                    arr[k] = arr[k + 1];

                (*n)--;

            } else {
                j++;
            }
        }
    }

    printf("\nDuplicates Removed Successfully!\n");
}

void frequency(int arr[], int n) {

    int visited[MAX] = {0};

    printf("\nElement Frequency\n");

    for (int i = 0; i < n; i++) {

        if (visited[i])
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {

            if (arr[i] == arr[j]) {

                count++;
                visited[j] = 1;

            }
        }

        printf("%d -> %d\n", arr[i], count);
    }
}

void linearSearch(int arr[], int n) {

    int key;

    printf("\nEnter Element to Search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {

        if (arr[i] == key) {

            printf("Element Found at Index %d\n", i);
            return;
        }
    }

    printf("Element Not Found!\n");
}

void bubbleSort(int arr[], int n) {

    int temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }

    printf("\nArray Sorted Successfully!\n");
}

int main() {

    int arr[MAX], n, choice;

    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    printf("Enter Elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {

        printf("\n=================================");
        printf("\n LeetCode Array Challenge");
        printf("\n=================================");

        printf("\n1. Display Array");
        printf("\n2. Largest & Second Largest");
        printf("\n3. Smallest & Second Smallest");
        printf("\n4. Reverse Array");
        printf("\n5. Remove Duplicates");
        printf("\n6. Count Frequency");
        printf("\n7. Linear Search");
        printf("\n8. Sort Array");
        printf("\n9. Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                display(arr, n);
                break;

            case 2:
            case 3:
                largestSmallest(arr, n);
                break;

            case 4:
                reverse(arr, n);
                break;

            case 5:
                removeDuplicates(arr, &n);
                break;

            case 6:
                frequency(arr, n);
                break;

            case 7:
                linearSearch(arr, n);
                break;

            case 8:
                bubbleSort(arr, n);
                break;

            case 9:
                printf("\nProgram Ended.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 9);

    return 0;
}