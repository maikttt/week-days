#include <string.h>
#include <math.h>
#include "week.h"

const char *week_days[] = {
    "Sunday", "Monday", "Tuesday",
    "Wednesday", "Thursday", "Friday", "Saturday"
};

int calc_week_day(int k, int m, int n)
{
    int c = trunc(n / 100);
    int y = n % 100;
    int d = k + trunc(2.6 * m - 0.2) - 2 * c +
        y + trunc(1.0 * c / 4) + trunc(1.0 * y / 4);
    return d % 7;
}

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

const char *get_week_day(int index)
{
    return week_days[index % 7];
}
