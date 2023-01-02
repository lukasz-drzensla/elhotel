#include "addnewreservation.h"
#include "ui_addnewreservation.h"
#include <QMessageBox>

addnewreservation::addnewreservation(QWidget *parent, viewCalendarUpdater *_calendar, dateTime *_arrival, dateTime *_departure, dataBase *_db, int* _duration, Room *_room) :
    QDialog(parent),
    ui(new Ui::addnewreservation)
{
    calendar = _calendar;
    db=_db;
    duration=*_duration;
    room=_room;
    ui->setupUi(this);
    ui->arr_dateEdit->setDate(QDate(_arrival->getYear(), _arrival->getMonth(), _arrival->getDay()));
    ui->dep_dateEdit->setDate(QDate(_departure->getYear(), _departure->getMonth(), _departure->getDay()));
    ui->roomLabel->setText(QString::fromStdString(room->description));
    int price = (room->cost_rate)*duration;
    ui->spinPrice->setValue(price);
}

addnewreservation::~addnewreservation()
{
    delete ui;
}

void addnewreservation::on_recalc_button_clicked()
{
    dateTime new_arr (ui->arr_dateEdit->date().day(), ui->arr_dateEdit->date().month(), ui->arr_dateEdit->date().year());
    dateTime new_dep (ui->dep_dateEdit->date().day(), ui->dep_dateEdit->date().month(), ui->dep_dateEdit->date().year());
    duration = new_arr.getDifference(new_arr, new_dep);
    int price = (room->cost_rate)*duration;
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
    dateTime new_arr (ui->arr_dateEdit->date().day(), ui->arr_dateEdit->date().month(), ui->arr_dateEdit->date().year());
    dateTime new_dep (ui->dep_dateEdit->date().day(), ui->dep_dateEdit->date().month(), ui->dep_dateEdit->date().year());
    duration = new_arr.getDifference(new_arr, new_dep);
    if (duration < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Error: departure earlier than arrival");
        msgBox.exec();
        return;
    }
    if (duration==0)
    {
        QMessageBox msgBox;
        msgBox.setText("Error: cannot make a zero-nights reservation");
        msgBox.exec();
        return;
    }
    int first_index = new_arr.getDifference(dateTime (1,1,globalConstants::thisYear), new_arr);
    for (int j = 0; j <= duration; j++)
    {
        vector <Reservation> all = db->getAllReservationsAtDate(first_index+j);

        for (int i = 0; i < all.size(); i++)
        {
            if (all[i].getRoom().id == room->id)
            {
                //found reservation, throw error
                QMessageBox msgBox;
                msgBox.setText("Error: there is already a reservation made for this room for the specified time period");
                msgBox.exec();
                return;
            }
        }
    }

    Reservation reservation (globalConstants::next_index, *room, name, new_arr, new_dep, phone, cost, nip);
    db->autoAddReservation(reservation);
    calendar->updateReservations();
    db->save();
    close();
}


void addnewreservation::on_cancel_but_clicked()
{
    close();
}

