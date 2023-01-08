#include "editreservation.h"
#include "ui_editreservation.h"
#include <QMessageBox>

editreservation::editreservation(QWidget *parent, viewCalendarUpdater *_calendar, Reservation *_reservation, dataBase *_db, int index, bool _enabled) :
    QDialog(parent),
    ui(new Ui::editreservation)
{
    calendar = _calendar;
    db=_db;
    reservation=_reservation;
    ui->setupUi(this);
    ui->arr_dateEdit->setDate(QDate(_reservation->getArrival().getYear(), _reservation->getArrival().getMonth(), _reservation->getArrival().getDay()));
    ui->dep_dateEdit->setDate(QDate(_reservation->getDeparture().getYear(), _reservation->getDeparture().getMonth(), _reservation->getDeparture().getDay()));
    ui->roomLabel->setText(QString::fromStdString(_reservation->getRoom().description));
    int price = _reservation->getCost();
    ui->spinPrice->setValue(price);
    ui->left_txt->setText(QString::fromStdString(std::to_string(price)));
    ui->max_people_label->setText(QString::fromStdString(std::to_string(_reservation->getRoom().max_people)));
    ui->name_txt->setText(QString::fromStdString(_reservation->getName()));
    ui->spinPaid->setValue(_reservation->getPaid());
    ui->phone_txt->setText(QString::fromStdString(_reservation->getPhone()));
    ui->nip_txt->setText(QString::fromStdString(_reservation->getNIP()));
    ui->comment_txt->setText(QString::fromStdString(_reservation->getComment()));
    enabled=_enabled;
}

editreservation::~editreservation()
{
    delete ui;
}

void editreservation::on_recalc_button_clicked()
{
    dateTime new_arr (ui->arr_dateEdit->date().day(), ui->arr_dateEdit->date().month(), ui->arr_dateEdit->date().year());
    dateTime new_dep (ui->dep_dateEdit->date().day(), ui->dep_dateEdit->date().month(), ui->dep_dateEdit->date().year());
    duration = new_arr.getDifference(new_arr, new_dep);
    int price = (reservation->getRoom().cost_rate)*duration;
    ui->spinPrice->setValue(price);
    ui->left_txt->setText((QString::fromStdString(std::to_string(price-ui->spinPaid->value()))));
}


void editreservation::on_cancel_but_clicked()
{
    close();
}


void editreservation::on_add_reservation_button_clicked()
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
            if (all[i].getRoom().id == reservation->getRoom().id)
            {
                if (all[i].getID()!= reservation->getID())
                {
                    //found reservation, throw error
                    QMessageBox msgBox;
                    msgBox.setText("Error: there is already a reservation made for this room for the specified time period");
                    msgBox.exec();
                    return;
                }
            }
        }
    }

    int res_id = reservation->getID();
    int stat = reservation->getStatus();
    int people = ui->spinPeople->value();
    if (ui->comment_txt->toPlainText().size()==0)
    {
        comment = "-";
    } else {
        qs = ui->comment_txt->toPlainText();
        comment=qs.toStdString();
    }
    if (people>reservation->getRoom().max_people)
    {
        QMessageBox msgBox;
        msgBox.setText("Warning: the number of people exceeds rooms max number of people!");
        msgBox.exec();
    }
    int paid = ui->spinPaid->value();

    if (enabled)
    {
        if (stat==1||stat==4)
        {
            if (cost-paid==0)
            {
                stat=1;
            }else {
                stat=4;
            }
        } else if (stat==2||stat==5)
        {
            if (cost-paid==0)
            {
                stat=2;
            }else {
                stat=5;
            }
        }
    }

    Reservation res (res_id, reservation->getRoom(), name, new_arr, new_dep, phone, cost, nip, stat, people, comment, paid);
    int DBID = db->getDBIDByResID(res_id);
    if (DBID<0)
    {
        db->Reservations.even[-DBID].set(res);
    } else {
        db->Reservations.odd[DBID].set(res);
    }

    db->save();
    db->Reservations.even.clear();
    db->Reservations.odd.clear();
    db->init(globalConstants::thisYear);
    db->load();
    calendar->updateReservations();
    close();
}


void editreservation::on_spinPaid_valueChanged(int arg1)
{
    int left = ui->spinPrice->value()-arg1;
    ui->left_txt->setText(QString::fromStdString(std::to_string(left)));
}


void editreservation::on_spinPrice_valueChanged(int arg1)
{
    int left = arg1-ui->spinPaid->value();
    ui->left_txt->setText(QString::fromStdString(std::to_string(left)));
}

