#include<stdio.h>
#include<stdlib.h>
void menu();
void order();
void bill();
char *item[4] ={"Pizza","Burger","Fries","Drink"};
int price[] ={15,10,5,3};
int n,srno[5];
void main(){
    menu();
}
void menu(){
    char tab[10];
    printf("Press 0 for Menu \n");
    scanf("%s",tab);
        printf("\tMENU\n");
        printf("SRNo\tITEM : PRICE\n");
        for(int i=0;i<4;i++){
            printf("%d\t%s : %d\n",i+1,item[i],price[i]);
        }
        printf("\n");
        printf("Enter the Number of Item to Order");
        scanf("%d",&n);
        printf("Enter the SRNo to Place the Order\n");
        for(int i=0;i<n;i++){
            scanf("%d",&srno[i]);
        }
        printf("\n");
        order();
}
void order(){
    int tab;
    printf("Item In The Cart :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%s : %d\n",i+1,item[srno[i]-1],price[srno[i]-1]);
    }
    printf("\n");
    printf("Press 1 To Checkout Or 2 To Reorder  \n");
    scanf("%d",&tab);
    if(tab == 1){
        bill();
    }
    else{
        menu();
    }
}
void bill(){
    int subTotal=0,t;
    float tax=0.0,total=0.0;
    for(int i=0;i<n;i++)
    {
        subTotal =subTotal + price[srno[i]-1];
    } 
    tax=subTotal*0.05;
    total= tax + subTotal;
    printf("Press 2 To Generate Bill \n");
    scanf("%d",&t);
    if(t == 2){
     printf("SRNo\tITEM : PRICE\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%s : %d\n",i+1,item[srno[i]-1],price[srno[i]-1]);
    }
    printf("----------------------------\n");
    printf("Amount  :\n");
    printf("SubTotal : %d\n",subTotal);
    printf("Taxes : %.2f\n",tax);
    printf("Total : %.2f\n",total);
    }  
}
