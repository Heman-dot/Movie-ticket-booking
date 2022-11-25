#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "custom_types.c"
 movie movies[5];
 void initdata()
 {
  strcpy(movies[0].name,"Black Adam");
  strcpy(movies[0].lang,"English");
  strcpy(movies[0].shows[0].time,"7:30 am");
  strcpy(movies[0].shows[0].screen,"Screen 1");
  strcpy(movies[0].shows[1].time,"12:30 pm");
  strcpy(movies[0].shows[1].screen,"Screen 2");
  strcpy(movies[0].shows[2].time,"3:30 pm");
  strcpy(movies[0].shows[2].screen,"Screen 1");
  strcpy(movies[1].name,"Black Panter");
  strcpy(movies[1].lang,"English");
  strcpy(movies[1].shows[0].time,"7:30 am");
  strcpy(movies[1].shows[0].screen,"Screen 2");
  strcpy(movies[1].shows[1].time,"12:30 pm");
  strcpy(movies[1].shows[1].screen,"Screen 1");
  strcpy(movies[1].shows[2].time,"5:30 pm");
  strcpy(movies[1].shows[2].screen,"Screen 1");
  strcpy(movies[2].name,"Varisu");
  strcpy(movies[2].lang,"Tamil");
  strcpy(movies[2].shows[0].time,"5:30 am");
  strcpy(movies[2].shows[0].screen,"Screen 1");
  strcpy(movies[2].shows[1].time,"10:30 am");
  strcpy(movies[2].shows[1].screen,"Screen 2");
  strcpy(movies[2].shows[2].time,"2:30 pm");
  strcpy(movies[2].shows[2].screen,"Screen 1");
  
 }

int main()
{
  int x; 
  initdata();
  do
  {
    printf("Welcome To Movie ticket Booking\n");
    printf("1-Ticket Booking\n2-Show Tickets\n3-Log out\n");
    printf("Enter you choice:");
    scanf("%d", &x);
    switch (x)
    {
    case 3:
      system("clear");
      printf("Thank you!!!\n");
      break;
    case 1:
      system("clear");
      printf("Movies:\n");
      int m,i;
    for(i=0;i<3;i++)
    {
      printf("%d-%s (%s)\n",i+1,movies[i].name,movies[i].lang);
    }
      printf("Enter the movie number:");
      scanf("%d", &m);
      if((m>=1)&&(m<=3))
      {
       system("clear");
       movie m1= movies[m-1];
       printf("%s-Show timings\n",movies[m-1].name);
       for(i=0;i<3;i++)
       {
        printf("%d-%s (%s)\n",i+1,m1.shows[i].time,m1.shows[i].screen);
       }
      } 
     else
       printf("Enter a number among the given numbers\n");
      break;
    case 2:
      printf("Ticket\n");
      break;
    default:
      printf("**Enter a number among the given numbers**\n");
    }
  } while ((x != 3));
  return 0;
}