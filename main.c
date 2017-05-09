#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char *week_days[] = {
    "Sunday", "Monday", "Tuesday",
    "Wednesday", "Thursday", "Friday", "Saturday"
};

int calc_week_day(int k, int m, int n);
void trans(int *date);

void main(int argc, char **argv) {
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

    printf("\n--------\n> %s\n", week_days[week_day]);
}
//--------------------------------------

int calc_week_day(int k, int m, int n)
{
    int c = trunc(n / 100);
    int y = n % 100;
    int d = k + trunc(2.6 * m - 0.2) - 2 * c +
        y + trunc(1.0 * c / 4) + trunc(1.0 * y / 4);
    return d % 7;
}

// Deplasam lunile, din
// ianuarie:1, februarie:2, martie:3, aprilie: 4,...
// in
// ianuarie:11, februarie:12, martie:1, aprilie:2,...
void trans(int *date)
{
    int dep = 2; // deplasam cu 2 luni

    date[1] = date[1] - 1;
    if (date[1] < dep) {
        // deplasam anul daca e necesar
        --date[2];
    }
    date[1] = (date[1] + 12 - dep) % 12 + 1;
}
