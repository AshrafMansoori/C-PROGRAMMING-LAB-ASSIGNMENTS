#include <stdio.h>
#include <stdlib.h>

int *arr = NULL;
int size = 0;

// Display Array
void display() {
    if (size == 0) {
        printf("\nArray is Empty!\n");
        return;
    }

    printf("\nArray Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insert Element
void insert() {
    int value;

    printf("\nEnter Element: ");
    scanf("%d", &value);

    arr = (int *)realloc(arr, (size + 1) * sizeof(int));

    arr[size] = value;
    size++;

    printf("Element Inserted Successfully!\n");
}

// Delete Element
void deleteElement() {
    if (size == 0) {
        printf("\nArray is Empty!\n");
        return;
    }

    int value, pos = -1;

    printf("\nEnter Element to Delete: ");
    scanf("%d", &value);

    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Element Not Found!\n");
        return;
    }

    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    arr = (int *)realloc(arr, size * sizeof(int));

    printf("Element Deleted Successfully!\n");
}

// Update Element
void update() {

    int oldValue, newValue;

    printf("\nEnter Old Value: ");
    scanf("%d", &oldValue);

    for (int i = 0; i < size; i++) {

        if (arr[i] == oldValue) {

            printf("Enter New Value: ");
            scanf("%d", &newValue);

            arr[i] = newValue;

            printf("Element Updated Successfully!\n");
            return;
        }
    }

    printf("Element Not Found!\n");
}

// Linear Search
void linearSearch() {

    int key;

    printf("\nEnter Element to Search: ");
    scanf("%d", &key);

    for (int i = 0; i < size; i++) {

        if (arr[i] == key) {
            printf("Found at Index %d using Linear Search\n", i);
            return;
        }
    }

    printf("Element Not Found!\n");
}

// Sort Array (Bubble Sort)
void sortArray() {

    int temp;

    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }

    printf("\nArray Sorted Successfully!\n");
}

// Binary Search
void binarySearch() {

    if (size == 0) {
        printf("\nArray is Empty!\n");
        return;
    }

    int key;

    printf("\nEnter Element to Search: ");
    scanf("%d", &key);

    int low = 0;
    int high = size - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid] == key) {

            printf("Found at Index %d using Binary Search\n", mid);
            return;

        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Element Not Found!\n");
}

int main() {

    int choice;

    do {

        printf("\n==================================");
        printf("\n Dynamic Array Operations");
        printf("\n==================================");

        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Update");
        printf("\n4. Display");
        printf("\n5. Linear Search");
        printf("\n6. Sort Array");
        printf("\n7. Binary Search");
        printf("\n8. Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            insert();
            break;

        case 2:
            deleteElement();
            break;

        case 3:
            update();
            break;

        case 4:
            display();
            break;

        case 5:
            linearSearch();
            break;

        case 6:
            sortArray();
            break;

        case 7:
            binarySearch();
            break;

        case 8:
            printf("\nMemory Released Successfully.\n");
            free(arr);
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 8);

    return 0;
}