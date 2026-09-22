#include <stdio.h>

struct Product {
    char name[50];
    int quantity;
    float price;
};
void add_stock(struct Product *product, int quantity)
{
    product->quantity += quantity;
}
void remove_stock(struct Product *product, int quantity)
{
    if (quantity <= product->quantity)
    {
        product->quantity -= quantity;
    }
    else
    {
        printf("Error: not enough stock available.\n");
    }
}
void display_product(struct Product *product)
{
    printf("Product: %s\n", product->name);
    printf("Quantity: %d\n", product->quantity);
    printf("Price: %.0f\n", product->price);
}
int main()
{
    struct Product rice = {"Rice", 20, 15000};

    display_product(&rice);

    printf("\nAdding 10...\n");

    add_stock(&rice, 10);

    display_product(&rice);

    printf("\nRemoving 31...\n");

    remove_stock(&rice, 31);

    display_product(&rice);


    return 0;
}