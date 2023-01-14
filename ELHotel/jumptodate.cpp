#include "jumptodate.h"
#include "ui_jumptodate.h"

jumptodate::jumptodate(QWidget *parent, viewCalendarUpdater *_calendar, dateTime *_first_day) :
    QDialog(parent),
    ui(new Ui::jumptodate)
{
    calendar = _calendar;
    first_day = _first_day;
    ui->setupUi(this);
}

jumptodate::~jumptodate()
{
    delete ui;
}

void jumptodate::on_Jump_clicked()
{
    int day = ui->dateEdit->date().day();
    int month = ui->dateEdit->date().month();
    dateTime dt (day, month, globalConstants::sharedVariables.thisYear);
    first_day->set(dt);
    calendar->displayDates(&dt);
    calendar->updateReservations();
    close();
}

