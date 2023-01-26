#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "custom_types.c"

movie g_movies[10];
int movie_size = 0;

ticket g_ticket[10];
int ticket_count = 0;

/* Function Declaration */
void init_data();
void book_ticket();
void clear_console();
void show_ticket();
void display_welcome_screen();

int main()
{
  clear_console();
  init_data();
  display_welcome_screen();
  return 0;
}

void display_welcome_screen()
{
  int choice;
  printf("\t \t \tWelcome To SRM Cinemas\n\n");
  do
  {
  start:
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
      printf("\t \t \tTickets Booked Successfully\n");
      goto start;
      break;
    case 2:
      show_ticket();
      break;
    default:
      printf("**Enter a number among the given numbers**\n");
    }
  } while (choice != 3);
}

// void init_data()
// {
// strcpy(g_movies[0].name, "Black Adam");
// strcpy(g_movies[0].lang, "English");
// strcpy(g_movies[0].shows[0].time, "7:30 am");
// strcpy(g_movies[0].shows[0].screen, "Screen 1");
// strcpy(g_movies[0].shows[1].time, "12:30 pm");
// strcpy(g_movies[0].shows[1].screen, "Screen 2");
// strcpy(g_movies[0].shows[2].time, "3:30 pm");
// strcpy(g_movies[0].shows[2].screen, "Screen 1");
// strcpy(g_movies[1].name, "Sita Ramam");
// strcpy(g_movies[1].lang, "Telugu");
// strcpy(g_movies[1].shows[0].time, "7:30 am");
// strcpy(g_movies[1].shows[0].screen, "Screen 2");
// strcpy(g_movies[1].shows[1].time, "12:30 pm");
// strcpy(g_movies[1].shows[1].screen, "Screen 1");
// strcpy(g_movies[1].shows[2].time, "5:30 pm");
// strcpy(g_movies[1].shows[2].screen, "Screen 1");
// strcpy(g_movies[2].name, "Varisu");
// strcpy(g_movies[2].lang, "Tamil");
// strcpy(g_movies[2].shows[0].time, "5:30 am");
// strcpy(g_movies[2].shows[0].screen, "Screen 1");
// strcpy(g_movies[2].shows[1].time, "10:30 am");
// strcpy(g_movies[2].shows[1].screen, "Screen 2");
// strcpy(g_movies[2].shows[2].time, "2:30 pm");
// strcpy(g_movies[2].shows[2].screen, "Screen 1");
// }

void init_data()
{
  FILE *fp = fopen("movies.txt", "r+");
  int read_start = 0;
  int show_start = 0;
  char buffer[1024] = "";
  int buffer_index = 0;
  int movie_index = 0;
  int choice = 0;
  int show_size = 0;
  for (char ch = fgetc(fp); !feof(fp); ch = fgetc(fp))
  {

    switch (ch)
    {
    case '$':
      switch (choice)
      {
      case 0:
        strcpy(g_movies[movie_size].name, buffer);
        break;

      case 1:
        strcpy(g_movies[movie_size].lang, buffer);
        break;

      case 2:
        strcpy(g_movies[movie_size].shows[show_size].time, buffer);
        break;

      case 3:
        strcpy(g_movies[movie_size].shows[show_size].screen, buffer);
        g_movies[movie_size].show_count = show_size + 1;
        show_size = 0;
        break;
      }
      choice += 1;
      choice %= 4;
      strncpy(buffer, "", strlen(buffer));
      buffer_index = 0;
      break;

    case '&':
      strcpy(g_movies[movie_size].shows[show_size].screen, buffer);
      show_size++;
      choice -= 1;
      strncpy(buffer, "", strlen(buffer));
      buffer_index = 0;
      break;

    default:
      buffer[buffer_index++] = ch;
      break;
    }
  }
  movie_size++;
}

void book_ticket()
{
  clear_console();
  int movie_choice;
  int is_valid;
  int seat_arr[100] = {0};

  do
  {
    printf("Movies:\n");

    int i;
    for (i = 0; i < movie_size; i++)
    {
      printf("%d-%s (%s)\n", i + 1, g_movies[i].name, g_movies[i].lang);
    }
    printf("%d-Main Menu\n", (movie_size + 1));
    printf("Enter your choice:");
    scanf("%d", &movie_choice);

    is_valid = (movie_choice > 0) && (movie_choice <= movie_size + 1);

    if (!is_valid)
    {
      printf("Enter a number among the given numbers\n");
    }
    if (movie_choice == (movie_size + 1))
      display_welcome_screen();
  } while (!is_valid);
show:
  clear_console();
  movie m1 = g_movies[movie_choice - 1];
  printf("%s - Show timings\n", m1.name);
  for (int i = 0; i < m1.show_count; i++)
  {
    printf("%d - %s (%s)\n", i + 1, m1.shows[i].time, m1.shows[i].screen);
  }
  printf("%d - Back\n", m1.show_count + 1);
  int s;
  printf("Enter your choice:");
  scanf("%d", &s);
  if (s == m1.show_count + 1)
    book_ticket();
  show m_show = m1.shows[s - 1];
  clear_console();
  printf("%s-%s (%s)\n", m1.name, m_show.time, m_show.screen);
  int i, j;
  for (int itr = 0; itr < ticket_count; itr++)
  {
    ticket temp_ticket = g_ticket[itr];
    if ((strcmp(temp_ticket.t_movie.name, m1.name) == 0) && (strcmp(temp_ticket.t_show.time, m_show.time) == 0))
    {
      for (int itr_2 = 0; itr_2 < temp_ticket.nos; itr_2++)
      {

        seat_arr[temp_ticket.seats[itr_2] - 1] = 1;
      }
    }
  }
  for (j = 0; j < 100; j++)
  {
    if (seat_arr[j] != 0)
      printf("*\t");
    else
      printf("%d\t", j + 1);
    if ((j + 1) % 10 == 0)
      printf("\n");
  }
  printf("\t \t \t S   C   R   E   E   N\n");
  printf("Press 0  to go to back\n");
seat:
  int nop;
  printf("Enter the number of persons:");
  scanf("%d", &nop);
  if (nop == 0)
    goto show;
  if (nop > 10)
  {
    printf("Only 10 tickets can be booked at a time\n");
    goto seat;
  }
  if (nop < 0)
  {
    printf("Enter a valid number\n");
    goto seat;
  }
  int seat_no[nop];
  for (i = 0; i < nop; i++)
  {
  a:
    int temp;
    printf("Enter the seat number for person %d:", i + 1);
    scanf("%d", &temp);

    if (temp > 100 || temp < 1)
    {
      printf("Enter seat number within the given limit\n");
      goto a;
    }
    if (seat_arr[temp - 1] != 0)
    {
      printf("Already Booked!\n");
      goto a;
    }
    for (int itr = i - 1; itr >= 0; itr--)
      if (seat_no[itr] == temp)
      {
        printf("Already selected!\n");
        goto a;
      }

    seat_no[i] = temp;
  }
  ticket temp_tick;

  for (int itr = 0; itr < nop; itr++)
  {
    temp_tick.seats[itr] = seat_no[itr];
  }
  temp_tick.t_movie = m1;
  temp_tick.t_show = m_show;
  temp_tick.nos = nop;

  g_ticket[ticket_count++] = temp_tick;
}

void show_ticket()
{
  clear_console();
  int x;
  if (ticket_count == 0)
    printf("No tickets Booked!\n");
  else
  {
    printf("\t \t \tLast Booked ticket\n");
    printf("%s (%s) - ", g_ticket[ticket_count - 1].t_movie.name, g_ticket[ticket_count - 1].t_movie.lang);
    printf("%s (%s)\n", g_ticket[ticket_count - 1].t_show.time, g_ticket[ticket_count - 1].t_show.screen);
    printf("Seats:\n");
    for (int itr = 0; itr < g_ticket[ticket_count - 1].nos; itr++)
    {
      printf("%d ", g_ticket[ticket_count - 1].seats[itr]);
    }
    printf("\n");
  }
  printf("0-back\n");
  printf("1-book tickets\n");
  printf("2-Show all tickets");
  scanf("%d", &x);
  if (x == 0)
    main();
  else if (x == 1)
    book_ticket();
  else if (x == 2)
  {
    clear_console();
    for (int itr = 0; itr < ticket_count; itr++)
    {
      ticket m_ticket = g_ticket[itr];
      printf("%s (%s) - ", m_ticket.t_movie.name, m_ticket.t_movie.lang);
      printf("%s (%s)\n", m_ticket.t_show.time, m_ticket.t_show.screen);
      printf("Seats:\n");
      for (int itr_2 = 0; itr_2 < m_ticket.nos; itr_2++)
      {
        printf("%d ", m_ticket.seats[itr_2]);
      }
      printf("\n\n");
    }
  }
}

void clear_console()
{
  system("clear");
}