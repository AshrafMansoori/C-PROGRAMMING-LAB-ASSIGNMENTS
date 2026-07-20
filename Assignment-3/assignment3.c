#include <stdio.h>

// Function to swap two numbers using pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int num = 100;
    int *ptr = &num;

    printf("=====================================\n");
    printf("      POINTER PLAYGROUND PROGRAM\n");
    printf("=====================================\n\n");

    // Display memory address
    printf("1. MEMORY ADDRESS\n");
    printf("---------------------------\n");
    printf("Value of num        : %d\n", num);
    printf("Address of num      : %p\n", (void *)&num);
    printf("Pointer ptr stores  : %p\n", (void *)ptr);

    // Dereferencing Pointer
    printf("\n2. DEREFERENCING POINTER\n");
    printf("---------------------------\n");
    printf("Value using *ptr : %d\n", *ptr);

    // Swap using pointers
    printf("\n3. SWAPPING TWO NUMBERS\n");
    printf("---------------------------\n");

    int a = 10, b = 20;

    printf("Before Swap\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    swap(&a, &b);

    printf("After Swap\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // Array Traversal
    printf("\n4. ARRAY TRAVERSAL USING POINTERS\n");
    printf("---------------------------\n");

    int arr[] = {5, 10, 15, 20, 25};
    int *p = arr;

    printf("Array Elements:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(p + i));
    }

    // Pointer Arithmetic
    printf("\n\n5. POINTER ARITHMETIC\n");
    printf("---------------------------\n");

    printf("Address = %p Value = %d\n", (void *)p, *p);

    p++;

    printf("After p++\n");
    printf("Address = %p Value = %d\n", (void *)p, *p);

    p++;

    printf("After another p++\n");
    printf("Address = %p Value = %d\n", (void *)p, *p);

    printf("\n=====================================\n");
    printf("Program Completed Successfully.\n");
    printf("=====================================\n");

    return 0;
}