#include "viewcalendarupdater.h"

std::string viewCalendarUpdater::toSTD (QString qs)
{
    return qs.toStdString();
}

QString viewCalendarUpdater::toQString (std::string ss)
{
    return QString::fromStdString(ss);
}

viewCalendarUpdater::viewCalendarUpdater(){}

viewCalendarUpdater::viewCalendarUpdater(vector <int> *_rooms_on_display, QTableWidget *_calendar, dataBase *_db, vector <int> *_days_of_week, dateTime *_first_day)
{
    rooms_on_display=_rooms_on_display;
    calendar=_calendar;
    db = _db;
    days_of_week=_days_of_week;
    first_day=_first_day;
}

void viewCalendarUpdater::displayDates(dateTime *f_day)
{
    days_of_week->clear();
    int day_index = f_day->getDifference(dateTime(1, 1, globalConstants::sharedVariables.thisYear), *f_day);
    for (int i = 0; i < 14; i++)
    {
        days_of_week->push_back(day_index+i);
        QTableWidgetItem *date_item = new QTableWidgetItem;
        date_item->setText(toQString(std::to_string(f_day->guessDay(day_index+i))+"."+std::to_string(f_day->guessMonth(day_index+i))));
        calendar->setItem(0, i, date_item);
    }
}

void viewCalendarUpdater::updateCalendar()
{
    rooms_on_display->clear();
    calendar->setRowCount(1);
    for (int i = 0; i < db->rooms.size(); i++)
    {
        calendar->insertRow(calendar->rowCount());
        QString des = toQString(db->rooms[i].description);
        calendar->setVerticalHeaderItem(calendar->rowCount()-1, new QTableWidgetItem(des));
        rooms_on_display->push_back(db->rooms[i].id);
    }
}

void viewCalendarUpdater::updateReservations()
{
    updateCalendar();
    for (int i = 0; i<14; i++)
    {
        vector <Reservation> all = db->getAllReservationsAtDate(days_of_week->at(i));
        for (int j = 0; j < all.size(); j++)
        {
            int room_id = all[j].getRoom().id;
            for (int n = 0; n < rooms_on_display->size(); n++)
            {
                if (rooms_on_display->at(n) == room_id)
                {
                    QTableWidgetItem *reservation_item = new QTableWidgetItem;
                    reservation_item->setText(toQString(all[j].getName()));
                    switch (all[j].getStatus())
                    {
                    case 1:{
                        reservation_item->setBackground(QColor(87,243,117));
                        break;
                    }
                    case 2:{
                        reservation_item->setBackground(QColor(180,180,180));
                        break;
                    }
                    case 3:{
                        reservation_item->setBackground(QColor(255,128,128));
                        break;
                    }
                    case 4:{
                        reservation_item->setBackground(QColor(252,216,102));
                        break;
                    }
                    case 5:{
                        reservation_item->setBackground(QColor(223,34,34));
                        break;
                    }
                    }
                    calendar->setItem(n+1, i, reservation_item);
                }
            }
        }
    }
}
