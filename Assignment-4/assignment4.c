#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int roll;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

// Function Prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main()
{
    int choice;

    do
    {
        printf("\n=====================================\n");
        printf(" STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("=====================================\n");

        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

// Add Student
void addStudent()
{
    if(count == MAX)
    {
        printf("\nDatabase Full!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;

    printf("\nStudent Added Successfully!\n");
}

// Display Students
void displayStudents()
{
    if(count == 0)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n-------------------------------------------------\n");
    printf("%-10s %-20s %-10s\n", "Roll", "Name", "Marks");
    printf("-------------------------------------------------\n");

    for(int i=0; i<count; i++)
    {
        printf("%-10d %-20s %-10.2f\n",
               students[i].roll,
               students[i].name,
               students[i].marks);
    }
}

// Search Student
void searchStudent()
{
    int roll;
    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    for(int i=0; i<count; i++)
    {
        if(students[i].roll == roll)
        {
            printf("\nStudent Found\n");
            printf("Roll  : %d\n", students[i].roll);
            printf("Name  : %s\n", students[i].name);
            printf("Marks : %.2f\n", students[i].marks);
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

// Update Student
void updateStudent()
{
    int roll;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    for(int i=0; i<count; i++)
    {
        if(students[i].roll == roll)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("\nRecord Updated Successfully!\n");
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

// Delete Student
void deleteStudent()
{
    int roll;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for(int i=0; i<count; i++)
    {
        if(students[i].roll == roll)
        {
            for(int j=i; j<count-1; j++)
            {
                students[j] = students[j+1];
            }

            count--;

            printf("\nRecord Deleted Successfully!\n");
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}