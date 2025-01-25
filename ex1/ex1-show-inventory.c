/*
LAB EXAM 1
TASK 2.1

Author: Bartosz Kogut
Date: 31/10/2024

This program takes cml arguments and builds a struct called product, then it prints out all its characteristics.
Input: Product name, number of stock, price, whether discounted or not.
Output: same but organised
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

// Declared prototype function for getting input
void input(int agrc, char *argv[]);
void check_discount(Product product);

int main(int argc, char *argv[])
{
    // Get all the products from input
    input(argc, argv);

    // Iterate through the products and print them out
    for(int i = 0; i < pcount; i++)
    {
        printf("%s,", product[i].name);
        printf("%d,", product[i].stock);
        printf("%.2f,", product[i].price);

        // Check if the product is discounted
        check_discount(product[i]);
    }
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
void check_discount(Product product)
{
    if (product.discount == 1)
    {
        printf("Discounted\n");
    }
    else if (product.discount == 0)
    {
        printf("No Discount\n");
    }
}
