#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "custom_types.c"

movie g_movies[3];

void init_data();
void book_ticket();
void clear_console();

int main()
{
  int choice;
  init_data();
  do
  {
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
  strcpy(g_movies[1].name, "Black Panter");
  strcpy(g_movies[1].lang, "English");
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

    is_valid = (m > 0) && (m < len);

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
}

void clear_console()
{
  system("clear");
}
