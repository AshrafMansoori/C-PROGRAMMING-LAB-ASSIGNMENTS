#include <stdio.h>
#include <string.h>

#define MAX 100

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Product products[MAX];
int count = 0;

// Add Product
void addProduct() {
    printf("\nEnter Product ID: ");
    scanf("%d", &products[count].id);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", products[count].name);

    printf("Enter Price: ");
    scanf("%f", &products[count].price);

    printf("Enter Quantity: ");
    scanf("%d", &products[count].quantity);

    count++;
    printf("\nProduct Added Successfully!\n");
}

// Display Products
void displayProducts() {
    if (count == 0) {
        printf("\nNo Products Available!\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f %-10d\n",
               products[i].id,
               products[i].name,
               products[i].price,
               products[i].quantity);
    }
}

// Search Product
void searchProduct() {
    int id;
    printf("\nEnter Product ID to Search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            printf("\nProduct Found!\n");
            printf("ID       : %d\n", products[i].id);
            printf("Name     : %s\n", products[i].name);
            printf("Price    : %.2f\n", products[i].price);
            printf("Quantity : %d\n", products[i].quantity);
            return;
        }
    }

    printf("\nProduct Not Found!\n");
}

// Update Product
void updateProduct() {
    int id;
    printf("\nEnter Product ID to Update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {

            printf("Enter New Price: ");
            scanf("%f", &products[i].price);

            printf("Enter New Quantity: ");
            scanf("%d", &products[i].quantity);

            printf("\nProduct Updated Successfully!\n");
            return;
        }
    }

    printf("\nProduct Not Found!\n");
}

// Sort Products by Price
void sortByPrice() {
    struct Product temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (products[i].price > products[j].price) {
                temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }

    printf("\nProducts Sorted by Price Successfully!\n");
}

// Calculate Inventory Value
void totalInventoryValue() {
    float total = 0;

    for (int i = 0; i < count; i++) {
        total += products[i].price * products[i].quantity;
    }

    printf("\nTotal Inventory Value = ₹%.2f\n", total);
}

int main() {

    int choice;

    do {
        printf("\n====================================");
        printf("\n Inventory Management System");
        printf("\n====================================");
        printf("\n1. Add Product");
        printf("\n2. Display Products");
        printf("\n3. Search Product");
        printf("\n4. Update Product");
        printf("\n5. Sort Products by Price");
        printf("\n6. Calculate Inventory Value");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            addProduct();
            break;

        case 2:
            displayProducts();
            break;

        case 3:
            searchProduct();
            break;

        case 4:
            updateProduct();
            break;

        case 5:
            sortByPrice();
            break;

        case 6:
            totalInventoryValue();
            break;

        case 7:
            printf("\nThank You!\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}