#ifndef ADDNEWRESERVATION_H
#define ADDNEWRESERVATION_H

#include <QDialog>
#include "viewcalendarupdater.h"
#include "header/dateTime.h"
#include "header/Reservation.h"
#include "header/dataBase.h"
#include "header/Room.h"
#include "header/globalConstants.h"

namespace Ui {
class addnewreservation;
}

class addnewreservation : public QDialog
{
    Q_OBJECT

public:
    explicit addnewreservation(QWidget *parent = nullptr, viewCalendarUpdater *_calendar = nullptr, dateTime *_arrival = nullptr, dateTime *_departure = nullptr, dataBase *_db = nullptr, int *_duration = nullptr, Room *_room = nullptr);
    ~addnewreservation();

private slots:
    void on_recalc_button_clicked();

    void on_add_reservation_button_clicked();

    void on_cancel_but_clicked();

private:
    Ui::addnewreservation *ui;
    viewCalendarUpdater *calendar{};
    dateTime *arrival{};
    dateTime *departure{};
    int *duration{};
    dataBase *db;
    Room *room{};
};

#endif // ADDNEWRESERVATION_H
