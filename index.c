#include <stdio.h>
#include <stdlib.h>

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
            system("clear");
              printf("Thank you!!!\n");
              break;
            case 1:
              system("clear");
              printf("Movies:\n");
              int m;
              a:printf("1-Black Adam\n2-Black Panther\n3-Ant Man\n");
              printf("Enter the movie number:");
              scanf("%d",&m);
              switch(m)
              {
                case 1:
                system("clear");
                  printf("Black Adam show timings\n1-[10:30 am]\n2-[4:30 pm]\n3-[7:30 pm]");
                  break;
                default:
                  printf("**Enter a number among the given numbers**\n");
                  goto a;
              }
              break;
            case 2:
              printf("Ticket\n");
              break;
            default:
            printf("**Enter a number among the given numbers**\n");
        }
    }while((x!=3)&&(x!=2)&&(x!=1));
    return 0;
}