#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[50];
    int stock;
    float price;
} Product;

void addProduct(Product **products, int *size, int *count);
void buyProduct(Product *products, int count);
void searchProduct(Product *products, int count);
void viewProducts(Product *products, int count);
void receiveOrder(Product *products, int count);
void checkStock(Product *products, int count);
void shipProduct(Product *products, int count);

int main()
{
    Product *products = NULL;
    int size = 0;
    int count = 0;

    int choice;

    while(1)
    {
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Buy Product\n");
        printf("3. Search Product\n");
        printf("4. View Products\n");
        printf("5. Receive Order\n");
        printf("6. Check Product Stock\n");
        printf("7. Ship Product\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            addProduct(&products, &size, &count);
            break;
        case 2:
            buyProduct(products, count);
            break;
        case 3:
            searchProduct(products, count);
            break;
        case 4:
            viewProducts(products, count);
            break;
        case 5:
            receiveOrder(products, count);
            break;
        case 6:
            checkStock(products, count);
            break;
        case 7:
            shipProduct(products, count);
            break;
        case 8:
            free(products);
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addProduct(Product **products, int *size, int *count)
{
    if (*count == *size)
    {
        *size += 5;
        *products = realloc(*products, (*size) * sizeof(Product));
        if (*products == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }

    printf("Enter product ID: ");
    scanf("%d", &((*products)[*count].id));
    printf("Enter product name: ");
    scanf("%s", (*products)[*count].name);
    printf("Enter stock quantity: ");
    scanf("%d", &((*products)[*count].stock));
    printf("Price: ");
    scanf("%f", &(*products)[*count].price);

    (*count)++;
    printf("Product added successfully!\n");
}

void buyProduct(Product *products, int count)
{
    int id, quantity;
    printf("Enter product ID to buy: ");
    scanf("%d", &id);
    printf("Enter quantity to buy: ");
    scanf("%d", &quantity);

    for (int i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            if (products[i].stock >= quantity)
            {
                products[i].stock -= quantity;
                printf("Product bought successfully!\n");
                return;
            }
            else
            {
                printf("Not enough stock available.\n");
                return;
            }
        }
    }
    printf("Product not found.\n");
}

void searchProduct(Product *products, int count)
{
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
           printf("Product found: ID=%d, Name=%s, Stock=%d, Price=%.2f\n", products[i].id, products[i].name, products[i].stock, products[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

void viewProducts(Product *products, int count)
{
    printf("All products:\n");
    for (int i = 0; i < count; i++)
    {
        printf("ID=%d, Name=%s, Stock=%d, price=%0.2f\n", products[i].id, products[i].name, products[i].stock,products[i].price);
    }
}

void receiveOrder(Product *products, int count)
{
    int id, quantity;
    printf("Enter product ID to restock: ");
    scanf("%d", &id);
    printf("Enter quantity to add: ");
    scanf("%d", &quantity);

    for (int i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            products[i].stock += quantity;
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void checkStock(Product *products, int count)
{
    int id;
    printf("Enter product ID to check stock: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            printf("Current stock for ID %d is %d\n", id, products[i].stock);
            return;
        }
    }
    printf("Product not found.\n");
}

void shipProduct(Product *products, int count)
{
    int id, quantity;
    printf("Enter product ID to ship: ");
    scanf("%d", &id);
    printf("Enter quantity to ship: ");
    scanf("%d", &quantity);
;
    for (int i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            if (products[i].stock >= quantity)
            {
                products[i].stock -= quantity;
                printf("Product shipped successfully!\n");
                return;
            }
            else
            {
                printf("Not enough stock to ship.\n");
                return;
            }
        }
    }
    printf("Product not found.\n");
}
