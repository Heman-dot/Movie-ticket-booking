#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "custom_types.c"

movie g_movies[10];
int movie_size = 3;
int showcount =  3;
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
  clear_console();
  int choice;
  printf("\t\t\t\tWelcome To SRM Cinemas\n\n");
  do
  {
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
      show_ticket();
      break;
    default:
      printf("**Enter a number among the given numbers**\n");
    }
  } while (choice != 3);
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

/*void init_data()
{
  FILE *fp = fopen("movies.txt", "r+");
  char buffer[1024] = "";
  int buffer_index = 0;
  int choice = 0;
  int show_size = 0;
  movie_size=0;
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
        movie_size++;
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
}*/

int get_movie()
{
  clear_console();

  int movie_choice;
  int is_valid;

  do
  {
    printf("Movies:%d\n",movie_size);
    for (int itr = 0; itr < movie_size; itr++)
    {
      printf("%d-%s (%s)\n", itr + 1, g_movies[itr].name, g_movies[itr].lang);
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

  return movie_choice - 1;
}

int get_show(movie chosen_movie)
{
  clear_console();

  int is_valid, choice;

  do
  {
    printf("%s - Show timings\n", chosen_movie.name);
    for (int itr = 0; itr < showcount; itr++)
    {
      printf("%d - %s (%s)\n", itr + 1, chosen_movie.shows[itr].time, chosen_movie.shows[itr].screen);
    }
    printf("%d - Back\n", showcount + 1);

    printf("Enter your choice:");
    scanf("%d", &choice);

    is_valid = (choice > 0) && (choice <= movie_size + 1);

    if (choice == showcount + 1)
      book_ticket();

  } while (!is_valid);

  return choice - 1;
}

void show_seat_layout(movie chosen_movie, show m_show, int seat_arr[])
{
  clear_console();
  printf("%s-%s (%s)\n", chosen_movie.name, m_show.time, m_show.screen);
  for (int itr = 0; itr < ticket_count; itr++)
  {
    ticket temp_ticket = g_ticket[itr];
    if ((strcmp(temp_ticket.t_movie.name, chosen_movie.name) == 0) && (strcmp(temp_ticket.t_show.time, m_show.time) == 0))
    {
      for (int itr_2 = 0; itr_2 < temp_ticket.nos; itr_2++)
      {
        seat_arr[temp_ticket.seats[itr_2] - 1] = 1;
      }
    }
  }

  for (int itr = 0; itr < 100; itr++)
  {
    if (seat_arr[itr] != 0)
      printf("*\t");
    else
      printf("%d\t", itr + 1);

    if ((itr + 1) % 10 == 0)
      printf("\n");
  }
  printf("\n\t\t\tS   C   R   E   E   N\n");
  printf("Press 0 to cancel booking\n");
}

int get_no_of_tickets()
{
  int nop, is_valid;
  do
  {
    is_valid = 1;

    printf("Enter the number of persons:");
    scanf("%d", &nop);
    if (nop == 0)
    {
      clear_console();
      printf("\t \t \tTicking Booking cancelled!\n\n");
      return -1;
    }
    if (nop > 10)
    {
      printf("Only 10 tickets can be booked at a time\n");
      is_valid = 0;
    }
    else if (nop < 0)
    {
      printf("Enter a valid number\n");
      is_valid = 0;
    }

  } while (!is_valid);

  return nop;
}

void get_seats(int nos, int seat_arr[], int seat_no[])
{
  int is_valid, temp;

  for (int itr = 0; itr < nos; itr++)
  {
    do
    {
      is_valid = 1;

      printf("Enter the seat number for person %d:", itr + 1);
      scanf("%d", &temp);

      if (temp > 100 || temp < 1)
      {
        printf("Enter seat number within the given limit\n");
        is_valid = 0;
      }
      if (seat_arr[temp - 1] != 0)
      {
        printf("Already Booked!\n");
        is_valid = 0;
      }
      for (int itr_2 = itr - 1; itr_2 >= 0; itr_2--)
        if (seat_no[itr_2] == temp)
        {
          printf("Already selected!\n");
          is_valid = 0;
        }
    } while (!is_valid);

    seat_no[itr] = temp;
  }

  return;
}

void book_ticket()
{
  int seat_arr[100] = {0};

  int m_movie = get_movie();
  if (m_movie == -1)
    return;

  movie chosen_movie = g_movies[m_movie];

  int m_show = get_show(chosen_movie);
  if (m_show == -1)
    return;

  show chosen_show = chosen_movie.shows[m_show];

  show_seat_layout(chosen_movie, chosen_show, seat_arr);

  int nos = get_no_of_tickets();

  if (nos == -1)
    return;

  int seats[nos];

  get_seats(nos, seat_arr, seats);

  ticket temp_tick;

  for (int itr = 0; itr < nos; itr++)
  {
    temp_tick.seats[itr] = seats[itr];
  }
  temp_tick.t_movie = chosen_movie;
  temp_tick.t_show = chosen_show;
  temp_tick.nos = nos;

  g_ticket[ticket_count++] = temp_tick;
  clear_console();
  printf("Ticket booked successfully!\n");
}

void show_ticket()
{
  clear_console();
  int x;
  if (ticket_count == 0)
  {
    printf("No tickets Booked!\n");
    printf("Press 0 to go back");
    scanf("%d",&x);
    if(x==0)
     display_welcome_screen();
  }
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
    printf("\n\n");
  
  printf("1-Show all tickets\n");
  printf("2-Go back\n");
  scanf("%d", &x);
  if (x == 2)
    display_welcome_screen();
  else if (x == 1)
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
}

void clear_console()
{
  system("clear");
}