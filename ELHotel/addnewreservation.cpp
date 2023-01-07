#include "addnewreservation.h"
#include "ui_addnewreservation.h"
#include <QMessageBox>

addnewreservation::addnewreservation(QWidget *parent, viewCalendarUpdater *_calendar, dateTime *_arrival, dateTime *_departure, dataBase *_db, int* _duration, Room *_room, bool *_enable) :
    QDialog(parent),
    ui(new Ui::addnewreservation)
{
    calendar = _calendar;
    db=_db;
    duration=*_duration;
    room=_room;
    enable=_enable;
    ui->setupUi(this);
    ui->arr_dateEdit->setDate(QDate(_arrival->getYear(), _arrival->getMonth(), _arrival->getDay()));
    ui->dep_dateEdit->setDate(QDate(_departure->getYear(), _departure->getMonth(), _departure->getDay()));
    ui->roomLabel->setText(QString::fromStdString(room->description));
    int price = (room->cost_rate)*duration;
    ui->spinPrice->setValue(price);
    ui->left_txt->setText(QString::fromStdString(std::to_string(price)));
    ui->max_people_label->setText(QString::fromStdString(std::to_string(room->max_people)));
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
    ui->left_txt->setText((QString::fromStdString(std::to_string(price-ui->spinPaid->value()))));
}


void addnewreservation::on_add_reservation_button_clicked()
{
    std::string name {};
    std::string phone {};
    std::string nip {};
    std::string comment{};
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

    int people = ui->spinPeople->value();
    if (ui->comment_txt->toPlainText().size()==0)
    {
        comment = "-";
    } else {
        qs = ui->comment_txt->toPlainText();
        comment=qs.toStdString();
    }
    if (people>room->max_people)
    {
        QMessageBox msgBox;
        msgBox.setText("Warning: the number of people exceeds rooms max number of people!");
        msgBox.exec();
    }
    int paid = ui->spinPaid->value();
    Reservation reservation (globalConstants::next_index, *room, name, new_arr, new_dep, phone, cost, nip, 0, people, comment, paid);
    db->autoAddReservation(reservation);
    calendar->updateReservations();
    db->save();
    close();
}


void addnewreservation::on_cancel_but_clicked()
{
    close();
}


void addnewreservation::on_spinPaid_valueChanged(int arg1)
{
    int left = ui->spinPrice->value()-arg1;
    ui->left_txt->setText(QString::fromStdString(std::to_string(left)));
}


void addnewreservation::on_spinPrice_valueChanged(int arg1)
{
    int left = arg1-ui->spinPaid->value();
    ui->left_txt->setText(QString::fromStdString(std::to_string(left)));
}

