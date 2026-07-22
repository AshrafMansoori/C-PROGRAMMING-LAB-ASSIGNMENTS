#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
};

struct Patient patients[MAX];
int count = 0;

// Register Patient
void addPatient() {
    printf("\nEnter Patient ID: ");
    scanf("%d", &patients[count].id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patients[count].name);

    printf("Enter Age: ");
    scanf("%d", &patients[count].age);

    printf("Enter Gender: ");
    scanf("%s", patients[count].gender);

    printf("Enter Disease: ");
    scanf(" %[^\n]", patients[count].disease);

    count++;

    printf("\nPatient Registered Successfully!\n");
}

// Display Patients
void displayPatients() {

    if (count == 0) {
        printf("\nNo Patient Records Found!\n");
        return;
    }

    printf("\n-----------------------------------------------------------------------------------------\n");
    printf("%-10s %-20s %-10s %-10s %-20s\n",
           "ID", "Name", "Age", "Gender", "Disease");
    printf("-----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10d %-10s %-20s\n",
               patients[i].id,
               patients[i].name,
               patients[i].age,
               patients[i].gender,
               patients[i].disease);
    }
}

// Search Patient
void searchPatient() {

    int id;

    printf("\nEnter Patient ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {

        if (patients[i].id == id) {

            printf("\nPatient Found!\n");
            printf("ID       : %d\n", patients[i].id);
            printf("Name     : %s\n", patients[i].name);
            printf("Age      : %d\n", patients[i].age);
            printf("Gender   : %s\n", patients[i].gender);
            printf("Disease  : %s\n", patients[i].disease);

            return;
        }
    }

    printf("\nPatient Not Found!\n");
}

// Update Patient
void updatePatient() {

    int id;

    printf("\nEnter Patient ID to Update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {

        if (patients[i].id == id) {

            printf("Enter New Name: ");
            scanf(" %[^\n]", patients[i].name);

            printf("Enter New Age: ");
            scanf("%d", &patients[i].age);

            printf("Enter New Gender: ");
            scanf("%s", patients[i].gender);

            printf("Enter New Disease: ");
            scanf(" %[^\n]", patients[i].disease);

            printf("\nPatient Record Updated Successfully!\n");
            return;
        }
    }

    printf("\nPatient Not Found!\n");
}

// Delete Patient
void deletePatient() {

    int id;

    printf("\nEnter Patient ID to Delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {

        if (patients[i].id == id) {

            for (int j = i; j < count - 1; j++) {
                patients[j] = patients[j + 1];
            }

            count--;

            printf("\nPatient Record Deleted Successfully!\n");
            return;
        }
    }

    printf("\nPatient Not Found!\n");
}

int main() {

    int choice;

    do {

        printf("\n========================================");
        printf("\n Hospital Patient Management System");
        printf("\n========================================");

        printf("\n1. Register Patient");
        printf("\n2. Display All Patients");
        printf("\n3. Search Patient");
        printf("\n4. Update Patient");
        printf("\n5. Delete Patient");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                updatePatient();
                break;

            case 5:
                deletePatient();
                break;

            case 6:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}