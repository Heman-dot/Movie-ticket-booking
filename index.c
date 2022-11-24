#include <stdio.h>

int main()
{
    int x;
    do{
        printf("Welcome To Movie ticket Booking\n");
        printf("1-Ticket Booking\n2-Show Tickets\n3-Log out\n");
        printf("Enter you choice:");
        scanf("%d",&x);
        switch(x)
        {
            case 3:
              printf("Thank you!!!\n");
              break;
            case 1:
              printf("Movies\n ");
              break;
            case 2:
              printf("Ticket\n");
              break;
            default:
            printf("Enter a number among the given numbers\n");
        }
    }while((x!=3)&&(x!=2)&&(x!=1));
    return 0;
}