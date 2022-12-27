#include "addnewreservation.h"
#include "ui_addnewreservation.h"
#include <QMessageBox>

addnewreservation::addnewreservation(QWidget *parent, viewCalendarUpdater *_calendar, dateTime *_arrival, dateTime *_departure, dataBase *_db, int* _duration, Room *_room) :
    QDialog(parent),
    ui(new Ui::addnewreservation)
{
    calendar = _calendar;
    arrival = _arrival;
    departure = _departure;
    db=_db;
    duration=_duration;
    room=_room;
    ui->setupUi(this);

    ui->arr_dateEdit->setDate(QDate(arrival->getYear(), arrival->getMonth(), arrival->getDay()));
    ui->dep_dateEdit->setDate(QDate(departure->getYear(), departure->getMonth(), departure->getDay()));
    ui->roomLabel->setText(QString::fromStdString(room->description));
    int price = (room->cost_rate)*(*duration);
    ui->spinPrice->setValue(price);
}

addnewreservation::~addnewreservation()
{
    delete ui;
}

void addnewreservation::on_recalc_button_clicked()
{
    int price = (room->cost_rate)*(*duration);
    ui->spinPrice->setValue(price);
}


void addnewreservation::on_add_reservation_button_clicked()
{
    std::string name {};
    std::string phone {};
    std::string nip {};
    QString qs{};
    if (ui->name_txt->toPlainText().size()==0)
    {
        name="Name";
    } else {
        qs = ui->name_txt->toPlainText();
        name = qs.toStdString();
    }
    int cost =ui->spinPrice->value();
    if (ui->phone_txt->toPlainText().size()==0)
    {
        phone="123-456-789";
    } else {
        qs = ui->phone_txt->toPlainText();
        phone=qs.toStdString();
    }
    if (ui->nip_txt->toPlainText().size()==0)
    {
        nip="0";
    } else {
        qs = ui->nip_txt->toPlainText();
        nip=qs.toStdString();
    }
    Reservation reservation (globalConstants::next_index, *room, name, *arrival, *departure, phone, cost, nip);
    db->autoAddReservation(reservation);
    calendar->updateReservations();
    globalConstants::save();
    db->save();
    close();
}


void addnewreservation::on_cancel_but_clicked()
{
    close();
}

