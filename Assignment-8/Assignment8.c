#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float tax;
    float grossSalary;
    float netSalary;
};

struct Employee emp[MAX];
int count = 0;

// Add Employee
void addEmployee() {

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp[count].id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp[count].name);

    printf("Enter Basic Salary: ");
    scanf("%f", &emp[count].basicSalary);

    // Salary Calculations
    emp[count].hra = emp[count].basicSalary * 0.20;
    emp[count].da = emp[count].basicSalary * 0.10;

    emp[count].grossSalary =
        emp[count].basicSalary + emp[count].hra + emp[count].da;

    // Tax Calculation
    if (emp[count].grossSalary <= 50000)
        emp[count].tax = emp[count].grossSalary * 0.05;
    else if (emp[count].grossSalary <= 100000)
        emp[count].tax = emp[count].grossSalary * 0.10;
    else
        emp[count].tax = emp[count].grossSalary * 0.15;

    emp[count].netSalary =
        emp[count].grossSalary - emp[count].tax;

    count++;

    printf("\nEmployee Added Successfully!\n");
}

// Display Employees
void displayEmployees() {

    if (count == 0) {
        printf("\nNo Employee Records Found!\n");
        return;
    }

    printf("\n=============================================================================================================\n");
    printf("%-5s %-20s %-10s %-10s %-10s %-10s %-12s %-12s\n",
           "ID","Name","Basic","HRA","DA","Tax","Gross","Net");
    printf("=============================================================================================================\n");

    for(int i=0;i<count;i++){

        printf("%-5d %-20s %-10.2f %-10.2f %-10.2f %-10.2f %-12.2f %-12.2f\n",
               emp[i].id,
               emp[i].name,
               emp[i].basicSalary,
               emp[i].hra,
               emp[i].da,
               emp[i].tax,
               emp[i].grossSalary,
               emp[i].netSalary);
    }
}

// Sort by Net Salary
void sortSalary(){

    struct Employee temp;

    for(int i=0;i<count-1;i++){
        for(int j=i+1;j<count;j++){

            if(emp[i].netSalary > emp[j].netSalary){

                temp=emp[i];
                emp[i]=emp[j];
                emp[j]=temp;

            }
        }
    }

    printf("\nEmployees Sorted by Net Salary Successfully!\n");
}

// Search Employee
void searchEmployee(){

    int id;

    printf("\nEnter Employee ID: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++){

        if(emp[i].id==id){

            printf("\nEmployee Found\n");
            printf("ID          : %d\n",emp[i].id);
            printf("Name        : %s\n",emp[i].name);
            printf("Basic Salary: %.2f\n",emp[i].basicSalary);
            printf("Gross Salary: %.2f\n",emp[i].grossSalary);
            printf("Net Salary  : %.2f\n",emp[i].netSalary);

            return;
        }

    }

    printf("\nEmployee Not Found!\n");

}

int main(){

    int choice;

    do{

        printf("\n======================================");
        printf("\n Employee Payroll System");
        printf("\n======================================");

        printf("\n1. Add Employee");
        printf("\n2. Display Salary Report");
        printf("\n3. Search Employee");
        printf("\n4. Sort by Net Salary");
        printf("\n5. Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                sortSalary();
                break;

            case 5:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    }while(choice!=5);

    return 0;
}