#include<string>
using namespace std;
#ifndef DATE_H
#define DATE_H


class Date
{
public:
    Date(int day,int month, int year);
    Date();
    Date(string );
    virtual ~Date();

    unsigned int Getday()
    {
        return day;
    }
    void Setday(unsigned int val)
    {
        day = val;
    }
    unsigned int Getmonth()
    {
        return month;
    }
    void Setmonth(int val)
    {
        month = val;
    }
    unsigned int Getyear(){return year;}
    void Setyear(int val){year = val;}
    string getDate()const;
    bool operator !()const;
protected:

private:
    int day;
    int month;
    int year;
};

#endif // DATE_H
