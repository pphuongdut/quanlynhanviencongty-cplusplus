#include "Date.h"
Date::Date(int day, int month, int year)
    : day(day), month(month), year(year)
{
}
Date::~Date()
{
}
istream &operator>>(istream &i, Date &date)
{
  cout << "Nhap ngay:";
  i >> date.day;
  cout << "thang:";
  i >> date.month;
  cout << "nam:";
  i >> date.year;
  if (date.month <= 0 || date.month > 12)
    throw string("month");
  else
  {
    if (date.year % 400 == 0 || (date.year % 4 == 0 && date.year % 100 == 0))
    {
      if (date.month == 2)
      {
        if (date.day > 29 || date.day <= 0)
          throw string("month2");
      }
    }
    else
    {
      if (date.month == 2)
      {
        if (date.day > 28 || date.day <= 0)
          throw string("month2");
      }
      else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
      {
        if (date.day > 30 || date.day <= 0)
          throw string("date");
      }
      else
      {
        if (date.day > 31 || date.day <= 0)
          throw string("date");
      }
    }
  }
  return i;
}
ostream &operator<<(ostream &o, const Date &date)
{
  o << date.day << "/" << date.month << "/" << date.year;
  return o;
}

int Date::getDateNow()
{
  time_t baygio = time(0);
  tm *ltm = localtime(&baygio);
  return ltm->tm_mday;
}
int Date::getMonthNow()
{
  time_t baygio = time(0);
  tm *ltm = localtime(&baygio);
  return 1 + ltm->tm_mon;
}
int Date::getYearNow()
{
  time_t baygio = time(0);
  tm *ltm = localtime(&baygio);
  return 1900 + ltm->tm_year;
}
Date Date::getToday()
{
  return Date(this->getDateNow(), this->getMonthNow(), this->getYearNow());
}
const Date &Date::operator=(const Date & date){
  this->day = date.day;
  this->month =date.month;
  this->year = date.year;
  return *this;
}