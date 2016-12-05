#ifndef LOCALTIME_H
#define LOCALTIME_H

#include <string>
#include <stdio.h>      /* puts, printf */
#include <time.h>       /* time_t, struct tm, time, localtime */

class LocalTime
{
public:

    LocalTime();

    int getYearToDay() const;
};

#endif // LOCALTIME_H
