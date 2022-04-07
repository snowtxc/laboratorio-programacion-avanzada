#ifndef DTFECHAHORA_HEADER
#define DTFECHAHORA_HEADER

#include<iostream>

class DtFechaHora{
    private:
       int day;
       int month;
       int year;
       int hour;
       int minute;
    public:
      DtFechaHora(int day, int month, int year, int hour, int minute);
      int getDay();
      void setDay(int);
      int getMonth();
      void setMonth(int);
      int getYear();
      void setYear(int);
      int getHour();
      void setHour(int);
      int getMinute();
      void setMinute(int);
};

#endif
