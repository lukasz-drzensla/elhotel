#pragma once
#ifndef VIEWCALENDARUPDATER_H
#define VIEWCALENDARUPDATER_H

#include "header/dataBase.h"
#include "header/dateTime.h"
#include <vector>
#include <QTableWidget>
#include "header/globalConstants.h"

class viewCalendarUpdater
{
public:
    viewCalendarUpdater();
    viewCalendarUpdater(vector <int> *_rooms_on_display, QTableWidget *_calendar, dataBase *_db, vector <int> *_days_of_week, dateTime *_first_day);
    void displayDates(dateTime *f_day);
    void updateCalendar();
    void updateReservations();
private:
    vector <int> *rooms_on_display{};
    QTableWidget *calendar{};
    dataBase *db{};
    vector <int> *days_of_week{};
    dateTime *first_day;
    std::string toSTD(QString qs);
    QString toQString (std::string ss);
};

#endif // VIEWCALENDARUPDATER_H
