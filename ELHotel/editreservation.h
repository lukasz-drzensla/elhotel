#ifndef EDITRESERVATION_H
#define EDITRESERVATION_H

#include <QDialog>
#include "viewcalendarupdater.h"
#include "header/dateTime.h"
#include "header/Reservation.h"
#include "header/dataBase.h"
#include "header/Room.h"
#include "header/globalConstants.h"

namespace Ui {
class editreservation;
}

class editreservation : public QDialog
{
    Q_OBJECT

public:
    explicit editreservation(QWidget *parent = nullptr, viewCalendarUpdater *_calendar = nullptr, Reservation *_reservation = nullptr, dataBase *_db = nullptr, int _index = 0, bool _enabled=true);
    ~editreservation();

private slots:
    void on_recalc_button_clicked();

    void on_cancel_but_clicked();

    void on_add_reservation_button_clicked();

    void on_spinPaid_valueChanged(int arg1);

    void on_spinPrice_valueChanged(int arg1);

private:
    Ui::editreservation *ui;
    viewCalendarUpdater *calendar{};
    int duration{};
    dataBase *db;
    Reservation *reservation {};
    bool enabled{};
};

#endif // EDITRESERVATION_H
