#include<stdio.h>
#include<string.h>
int count,i=0,o=0;
struct menu
{
    char food[30];
    int price;
    int qty;
}m[10];
struct customerdetails
{
    char name[30];
    long phoneno;
    int custno;
    int bill;
}c[100];
void input()//menu entries
{
    int i=0;
    printf("Food Item\tPrice\tQuantity\n");
    for(i=0;i<10;i++)
    {
        scanf("%s%d%d",m[i].food,&m[i].price,&m[i].qty);
    }
}
void display()
{

        int i=0;
        printf("Food Number\tFood Item\tPrice\tQuantity\n");
        for(i=0;i<10;i++)
        {
            if(m[i].qty==0)
                printf("%d\t%s\t %d \tout of stock\n",i,m[i].food,m[i].price,m[i].qty);
            else
                printf("%d\t%s\t %d \t%d\n",i,m[i].food,m[i].price,m[i].qty);
        }

}
int order()
{
    int f,q,it,i,amt=0;
    printf("How many items you want to order\n");
    scanf("%d",&it);
    for(i=0;i<it;i++)
    {
        printf("Enter the food no. \n");
        scanf("%d",&f);
        if(m[f].qty==0)
           {
            printf("This item is unavailable. Order Something else\n");
            i--;
           }
           else
            {
                printf("Enter the quantity \n");
                scanf("%d",&q);
                if(m[f].qty>=q)
                {
                editmenu(f,q);
                amt=bill(f,q,amt);
                }
                else
                {
                    printf("Your demand has exceeded our supply.Please order again\n");
                    i--;
                }
            }
    }
    return amt;
}
void editmenu(int f1,int q1)
{
    m[f1].qty=m[f1].qty-q1;
}
int bill(int f2,int q2,int amt)
{
    amt=amt+m[f2].price*q2;
    return amt;
}
void custdetails()
{
     printf("Enter your name\n");
     scanf("%s",c[count-1].name);
     printf("Enter your phone  no. \n");
     scanf("%d",&c[count-1].phoneno);

}
void dailystats()
{
    if(count==0)
        printf("No Stats available for today\n");
    else
    {
        printf("The daily count of customers is\n");
        printf("%d \n",count);
        printf("The customer details are\n");
        printf("Name\tPhone No.\tCustomer No.\tBill \n");
        for(i=0;i<count;i++)
        {
            printf("%s \t%d \t%d \t%d",c[i].name,c[i].phoneno,c[i].custno,c[i].bill);
            printf("\n");
        }
    }
}
void totbill()
{
    int sum=0;
    for(i=0;i<count;i++)
    {
        sum=sum+c[i].bill;
    }
    if(sum==0)
        printf("Coffers are empty\n");
    else
        printf("Total money earned is %d\n",sum);
}
int main()
{
    printf("Hello and Welcome to BELLA ITALIA\n");
    printf("\n");
    while(1)
    {
    printf("Press 1 if you are a Manager\n");
    printf("Press 2 if you are a Customer\n");
    printf("Press 3 to exit\n");
    printf("Enter your choice\n");
    int ch;
    scanf("%d",&ch);
    if(ch==3)
        {
            printf("Thank you for Visiting\n");
            break;
        }
    switch(ch)
    {
        case 1:
        printf("Enter 1 to view the Daily Statistics\n");
        printf("Enter 2 to view the Daily Earnings\n");
        printf("Press 3 to Enter the menu for the day\n");
        printf("enter your choice\n");
        int ch1;
        scanf("%d",&ch1);
        switch(ch1)
        {
        case 1:
            dailystats();
            break;
        case 2:
            totbill();
            break;
        case 3:
            input();
            break;
        }
        break;
        case 2:
            if(m[0].price==0)
            {
                printf("The menu has  not been put up. Sorry for the inconvenience\n");
                break;
            }
            else
            {
                count++;
                c[count-1].custno=count;
                printf("Please enter your details\n");
                custdetails();
                int d=1;
                while(d<=3)
                {
                    if(d==1)
                    {
                        printf("The menu is\n");
                        display();
                    }
                    if(d==2)
                    {
                        printf("Please place your order\n");
                        o=order();
                    }
                    if(d==3)
                    {
                        printf("Your bill is\n");
                        printf("%d ",o);
                        printf("\n");
                        c[count-1].bill=o;
                    }
                    d++;
                }
            }
            break;
        }
    }
    return 0;
}
