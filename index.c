#include <stdio.h>

int main()
{
    int x;
    while(x)
    {
        printf(" Welcome To Movie ticket Booking\n");
        printf("1-Ticket Booking\n2-Show Tickets\n3-Log out\n");
        printf("Enter you choice:");
        scanf("%d",&x);
        if(x==3)
        {
            printf("Thank you!!!Cum again!!haaa");
            break;
        }
        if((x<1)||(x>3))
        {
            printf("Enter a number among the given numbers\n");
            continue;
        }
        
    }
    return 0;
}