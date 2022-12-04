#include "Date.h"
#include <sstream>

Date::Date()
{
    //ctor
}
Date::Date(string date)
{
    try
    {
        if(date!="")
        {
            string data;
            stringstream s(date);
            getline(s,data,'-');
            year=stoi(data);
            getline(s,data,'-');
            month=stoi(data);
            getline(s,data,'-');
            day=stoi(data);
        }else{
            day=0;
            month=0;
            year=0;
        }
    }
    catch(char* e)
    {
        day=0;
        month=0;
        year=0;
    }
}
Date::Date(int day, int month, int year)
{
    this->day=day;
    this->month=month;
    this->year=year;
}
Date::~Date()
{
    //dtor
}
string Date::getDate()const
{
    return to_string(year/1000)+to_string((year/100)%10)+to_string((year/10)%10)+to_string(year%10)+'-'
           + to_string(month/10)+to_string(month%10)+'-'+to_string(day/10)+to_string(day%10);
}
bool Date::operator !()const
{
    if(day==0 && month==0 && year==0)
        return false;
    return true;
};
