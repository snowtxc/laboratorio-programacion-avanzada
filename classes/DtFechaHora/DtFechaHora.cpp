
#include <iostream>
#include "DtFechaHora.h";

using namespace std;

DtFechaHora::DtFechaHora(int day , int month , int year, int hour, int minute){
    if(day > 30 || day < 1){
        throw invalid_argument("Dia es invalido");
    }
    if(month > 12 || month < 1){
        throw invalid_argument("Mes es invalido");
    }
    if (year < 1900){
        throw invalid_argument("Año invalido");
    }
    if (hour < 0 || hour > 23){
        throw invalid_argument("Hora invalida");
    }
    if (minute < 0 || minute > 59){
        throw invalid_argument("Minuto invalido");
    }
    this->day =  day;
    this->month = month;
    this->year = year;
    this->hour = hour;
    this->minute = minute;
}



int DtFechaHora::getDay(){
    return this->day;
}

void DtFechaHora::setDay(int day){
    if (day > 30 || day < 1){
        throw invalid_argument("Dia es invalido");
    }
    this->day = day;
}

int DtFechaHora::getMonth()
{
    return this->month;
}

void DtFechaHora::setMonth(int month){
    if (month > 12 || month < 1)
    {
        throw invalid_argument("Mes es invalido");
    }
    this->month = month;
}

int DtFechaHora::getYear(){
    return this->year;
}

void DtFechaHora::setYear(int year)
{
    if (year < 1900){
        throw invalid_argument("Año invalido");
    }
    this->year = year;

}

int DtFechaHora::getHour()
{
    return this->hour;
}

void DtFechaHora::setHour(int hour)
{
    if (hour < 0 || hour > 23)
    {
        throw invalid_argument("Hora invalida");
    }
    this->hour = hour;
}

int DtFechaHora::getMinute()
{
    return this->minute;
}

void DtFechaHora::setMinute(int minute)
{
    if (minute < 0 || minute > 59)
    {
        throw invalid_argument("Hora invalida");
    }
    this->minute = minute;
}
