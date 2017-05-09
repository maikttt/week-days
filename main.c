#include <stdio.h>
#include "week.h"

void main(int argc, char **argv)
{
    int date[3]; // date, month, year
    int week_day;

    printf("Date: ");
    scanf("%d", &date[0]);
    printf("Month: ");
    scanf("%d", &date[1]);
    printf("Year: ");
    scanf("%d", &date[2]);

    trans(date);
    week_day = calc_week_day(date[0], date[1], date[2]);

    printf("\n--------\n> %s\n", get_week_day(week_day));
}
