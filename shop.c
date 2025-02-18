#include<stdio.h>
#include<stdlib.h>

void menu();
void order();
void bill();

char *item[4] = {"Shirt", "Pants", "Shoes"};
int price[] = {15, 20, 30};
int n, srno[5], quantity[5];

void main() {
    menu();
}

void menu() {
    char tab[10];
    printf("Press 0 for Menu \n");
    scanf("%s", tab);
    
    printf("\tMENU\n");
    printf("SRNo\tITEM : PRICE\n");
    for(int i = 0; i < 3; i++) {
        printf("%d\t%s : %d\n", i + 1, item[i], price[i]);
    }
    printf("\n");
    
    printf("Enter the Number of Items to Order: ");
    scanf("%d", &n);
    printf("Enter the SRNo to Place the Order (followed by quantity for each item)\n");
    for(int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &srno[i], &quantity[i]); // Read SRNo and quantity
    }
    printf("\n");
    
    order();
}

void order() {
    int tab;
    printf("Items in the Cart:\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%s : %d x %d = %d\n", i + 1, item[srno[i] - 1], price[srno[i] - 1], quantity[i], price[srno[i] - 1] * quantity[i]);
    }
    printf("\n");
    printf("Press 1 To Checkout Or 2 To Reorder\n");
    scanf("%d", &tab);
    
    if(tab == 1) {
        bill();
    } else {
        menu();
    }
}

void bill() {
    int subTotal = 0, t;
    float tax = 0.0, total = 0.0;
    
    for(int i = 0; i < n; i++) {
        subTotal += price[srno[i] - 1] * quantity[i]; // Calculate subtotal considering quantity
    }
    
    tax = subTotal * 0.05;
    total = tax + subTotal;
    
    printf("Press 2 To Generate Bill \n");
    scanf("%d", &t);
    
    if(t == 2) {
        printf("SRNo\tITEM : PRICE\n");
        for(int i = 0; i < n; i++) {
            printf("%d\t%s : %d x %d = %d\n", i + 1, item[srno[i] - 1], price[srno[i] - 1], quantity[i], price[srno[i] - 1] * quantity[i]);
        }
        printf("----------------------------\n");    
        printf("Amount  :\n");
        printf("SubTotal : %d\n", subTotal);
        printf("Taxes : %.2f\n", tax);
        printf("Total : %.2f\n", total);
    }  
}
