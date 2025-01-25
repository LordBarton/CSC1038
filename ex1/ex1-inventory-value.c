/*
LAB EXAM 1
TASK 2.2

Author: Bartosz Kogut
Date: 31/10/2024

This program takes cml arguments and builds a struct called product, then it
calculates the total value of the whole stock, applying discounts where appropriate.
Output: total value of the stock
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Declared the Product struct
typedef struct Product Product;

struct Product
{
    char name[20];
    int stock;
    float price;
    int discount;
};

// Allow up to 100 products
Product product[100];

// Declare globally the number of products so I can access it in all my functions.
int pcount = 0;

// Declared prototype functions
void input(int agrc, char *argv[]);
int check_discount(Product product);
float total_value(Product product[], int pcount);

int main(int argc, char *argv[])
{
    // Get all the products from input
    input(argc, argv);

    // Iterate through the products and print them out
    printf("%.2f\n", total_value(product, pcount));
    return 0;
}

void input(int argc, char *argv[])
{
    int index = 1;

    // A product has 4 characteristics, so use that to calculate the number of them
    pcount = (argc - 1) / 4;

    // Populate the structs
    for(int i = 0; i < pcount; i++)
    {
        strcpy(product[i].name, argv[index]);
        product[i].stock = atoi(argv[index + 1]);
        product[i].price = atof(argv[index + 2]);
        product[i].discount = atoi(argv[index + 3]);

        index += 4;
    }
}

// Check if the product is dicounted or not by its boolean value
int check_discount(Product product)
{
    if (product.discount == 1)
    {
        return 1;
    }
    else if (product.discount == 0)
    {
        return 0;
    }
}

// Function for calculating the total value
float total_value(Product product[], int pcount)
{
    // Store total value here
    float total = 0;

    // Iterate through all the products
    for (int i = 0; i < pcount; i++)
    {
        // Check if a discount applies, if yes add it
        if (check_discount(product[i]) == 1)
        {
            // The total is product price with discount times its stock
            total += product[i].stock * (product[i].price * 0.9);
        }
        else if (check_discount(product[i]) == 0)
        {
            total += product[i].stock * product[i].price;
        }
    }

    // Return the whole value
    return total;
}
