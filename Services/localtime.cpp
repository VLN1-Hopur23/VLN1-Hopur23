#include "localtime.h"

LocalTime::LocalTime()
{

}

int LocalTime::getYearToDay() const
{
    time_t rawtime;

    struct tm * timeinfo;

    time (&rawtime);

    timeinfo = localtime (&rawtime);

    // Get the only the year in integer form from localtime
    std::string str = asctime(timeinfo);

    int LastSpace = str.find_last_of(" ")+1;

    int StrEnd = str.size();

    std:: string StringYearToDay = str.substr( LastSpace,StrEnd);

    int YearToDay = std::stoi (StringYearToDay);

    return YearToDay;
}
