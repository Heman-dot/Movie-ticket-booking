#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "custom_types.c"

movie g_movies[3];

void init_data();
void book_ticket();
void clear_console();
void show_ticket();
int main()
{
  int choice;
  init_data();
  do
  {
    clear_console();
    printf("Welcome To Movie ticket Booking\n");
    printf("1-Ticket Booking\n2-Show Tickets\n3-Log out\n");
    printf("Enter you choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 3:
      clear_console();
      printf("Thank you!!!\n");
      break;
    case 1:
      book_ticket();
      break;
    case 2:
      printf("Ticket\n");
      break;
    default:
      printf("**Enter a number among the given numbers**\n");
    }
  } while (choice != 3);
  return 0;
}

void init_data()
{
  strcpy(g_movies[0].name, "Black Adam");
  strcpy(g_movies[0].lang, "English");
  strcpy(g_movies[0].shows[0].time, "7:30 am");
  strcpy(g_movies[0].shows[0].screen, "Screen 1");
  strcpy(g_movies[0].shows[1].time, "12:30 pm");
  strcpy(g_movies[0].shows[1].screen, "Screen 2");
  strcpy(g_movies[0].shows[2].time, "3:30 pm");
  strcpy(g_movies[0].shows[2].screen, "Screen 1");
  strcpy(g_movies[1].name, "Sita Ramam");
  strcpy(g_movies[1].lang, "Telugu");
  strcpy(g_movies[1].shows[0].time, "7:30 am");
  strcpy(g_movies[1].shows[0].screen, "Screen 2");
  strcpy(g_movies[1].shows[1].time, "12:30 pm");
  strcpy(g_movies[1].shows[1].screen, "Screen 1");
  strcpy(g_movies[1].shows[2].time, "5:30 pm");
  strcpy(g_movies[1].shows[2].screen, "Screen 1");
  strcpy(g_movies[2].name, "Varisu");
  strcpy(g_movies[2].lang, "Tamil");
  strcpy(g_movies[2].shows[0].time, "5:30 am");
  strcpy(g_movies[2].shows[0].screen, "Screen 1");
  strcpy(g_movies[2].shows[1].time, "10:30 am");
  strcpy(g_movies[2].shows[1].screen, "Screen 2");
  strcpy(g_movies[2].shows[2].time, "2:30 pm");
  strcpy(g_movies[2].shows[2].screen, "Screen 1");
}

void book_ticket()
{
  int m;
  int is_valid;
  int len = sizeof(g_movies) / sizeof(g_movies[0]);
  clear_console();
  do
  {
    printf("Movies:\n");

    int i;
    for (i = 0; i < 3; i++)
    {
      printf("%d-%s (%s)\n", i + 1, g_movies[i].name, g_movies[i].lang);
    }

    printf("Enter the movie number:");
    scanf("%d", &m);

    is_valid = (m > 0) && (m <= len);

    if (!is_valid)
    {
      printf("Enter a number among the given numbers\n");
    }
  } while (!is_valid);

  clear_console();
  movie m1 = g_movies[m - 1];
  printf("%s-Show timings\n", m1.name);
  for (int i = 0; i < 3; i++)
  {
    printf("%d-%s (%s)\n", i + 1, m1.shows[i].time, m1.shows[i].screen);
  }
  int s;
  printf("Enter the show timing:");
  scanf("%d", &s);
  clear_console();
  printf("%s-%s (%s)\n", m1.name, m1.shows[s - 1].time, m1.shows[s - 1].screen);
  int i, j;
  for (i = 0; i < 1; i++)
  {
    for (j = 1; j <= 100; j++)
    {
      if (j % 4 == 0)
        printf("*\t");
      else
        printf("%d\t", j);
      if (j % 10 == 0)
        printf("\n");
    }
  }
    printf("\t \t \t S   C   R   E   E   N\n");
  int nop;
 seat:
  printf("Enter the number of persons:");
  scanf("%d", &nop);
  if (nop > 100)
  {
    printf("only 100 seats are available\n");
    goto seat;
  }
  int sno[nop];
  for (i = 0; i < nop; i++)
  {
    int temp;
  a:
    printf("Enter the seat number for person %d:", i + 1);
    scanf("%d", &temp);
    if (temp % 4 == 0)
    {
      printf("Already Booked!\n");
      goto a;
    }
    for (int itr = i - 1; itr >= 0; itr--)
      if (sno[itr] == temp)
      {
        printf("Already selected!\n");
        goto a;
      }
    if (temp > 100)
    {
      printf("Enter seat number within the given limit\n");
      goto a;
    }
    sno[i] = temp;
  }
}

void show_ticket()
{
 
}

void clear_console()
{
  system("clear");
}