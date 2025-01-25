/*
Author: Ayden Jahola
Description: This program reads a list of items in the cart and calculates the final price, considering promotions.
Input: List of items in the shopping cart
Output: The final price of the cart
Date: 02/11/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the structure for items in the cart
struct Items
{
  char name[50];
  unsigned int amount;
  float price;
  unsigned int promotion; // Promotion flag (0 for no promotion, 1 for promotion)
};

// Function prototype
int calculateDiscount(struct Items cart[], int items_num);

// Main function
int main(int argc, char *argv[])
{
  // Declare variables
  int i = 0;
  struct Items cart[50];

  // Read values from the command line
  for (i = 0; i < (argc - 1) / 4; i++)
  {
    // Parse and store item details
    strcpy(cart[i].name, argv[i * 4 + 1]);
    cart[i].amount = atoi(argv[i * 4 + 2]);
    cart[i].price = atof(argv[i * 4 + 3]);
    cart[i].promotion = atoi(argv[i * 4 + 4]);
  }

  // Calculate and print the final price of the items
  calculateDiscount(cart, (argc - 1) / 4);

  return 0;
}

// Function to calculate the total final amount of items in the cart
int calculateDiscount(struct Items cart[], int items_num)
{
  // Declare variables
  int i = 0;
  float total_price = 0;
  float total_price_promotion = 0;

  // Calculate the total price of items without promotion
  for (i = 0; i < items_num; i++)
  {
    if (cart[i].promotion == 0)
    {
      total_price += cart[i].amount * cart[i].price;
    }
  }

  // Calculate the total price of items with promotion
  for (i = 0; i < items_num; i++)
  {
    if (cart[i].promotion == 1)
    {
      // Apply the promotion: buy 2, get 1 free
      total_price_promotion += (cart[i].amount * cart[i].price) - (cart[i].amount / 3 * cart[i].price);
    }
  }

  // Calculate the final price of the items
  total_price = total_price + total_price_promotion;

  // Print the final price of all items
  printf("%.2f\n", total_price);

  return 0;
}
