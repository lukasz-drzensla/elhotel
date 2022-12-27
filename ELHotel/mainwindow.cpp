#include "mainwindow.h"
#include "./ui_mainwindow.h"

//Reservation system libraries

#include "header/globalConstants.h"
#include <fstream>
#include <vector>
#include "header/Room.h"
#include <QMessageBox>



std::string toSTD (QString qs)
{
    return qs.toStdString();
}

QString toQString (std::string ss)
{
    return QString::fromStdString(ss);
}

void MainWindow::updateCalendar()
{
    rooms_on_display.clear();
    ui->reservationCalendar->setRowCount(1);
    for (int i = 0; i < db.rooms.size(); i++)
    {
        ui->reservationCalendar->insertRow(ui->reservationCalendar->rowCount());
        QString des = toQString(db.rooms[i].description);
        ui->reservationCalendar->setVerticalHeaderItem(ui->reservationCalendar->rowCount()-1, new QTableWidgetItem(des));
        rooms_on_display.push_back(db.rooms[i].id);
    }
}

void MainWindow::updateReservations()
{
    updateCalendar();
    for (int i = 0; i<14; i++)
    {
        vector <Reservation> all = db.getAllReservationsAtDate(days_of_week[i]);
        for (int j = 0; j < all.size(); j++)
        {
            int room_id = all[j].getRoom().id;
            for (int n = 0; n < rooms_on_display.size(); n++)
            {
                if (rooms_on_display[n] == room_id)
                {
                    QTableWidgetItem *reservation_item = new QTableWidgetItem;
                    reservation_item->setText(toQString(all[j].getName()));
                    ui->reservationCalendar->setItem(n+1, i, reservation_item);
                }
            }
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->reservationCalendar);
    ui->reservationCalendar->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //initalize database
    db.init(globalConstants::thisYear); //init the database with current year
    db.load(true);

    //initialize room view
    updateCalendar();

    //initialize days of week view
    dateTime dt (19,12,globalConstants::thisYear);
    first_day.set(dt);
    displayDates(first_day);

    //initialize reservations view
    updateReservations();
}

void MainWindow::displayDates(dateTime first_day)
{
    days_of_week.clear();
    int day_index = first_day.getDifference(dateTime(1, 1, globalConstants::thisYear), first_day);
    for (int i = 0; i < 14; i++)
    {
        days_of_week.push_back(day_index+i);
        QTableWidgetItem *date_item = new QTableWidgetItem;
        date_item->setText(toQString(std::to_string(first_day.guessDay(day_index+i))+"."+std::to_string(first_day.guessMonth(day_index+i))));
        ui->reservationCalendar->setItem(0, i, date_item);
    }
}



void MainWindow::on_actionPrevious_week_triggered()
{
    dateTime dt (1, 1, globalConstants::thisYear);
    int index = dt.getDifference(dt, first_day);
    index-=7;
    int day = dt.guessDay(index);
    int month = dt.guessMonth(index);
    dateTime prev_dt (day, month, globalConstants::thisYear);
    first_day.set(prev_dt);
    displayDates(first_day);
    updateReservations();
}

void MainWindow::on_actionNext_week_triggered()
{
    dateTime dt (1, 1, globalConstants::thisYear);
    int index = dt.getDifference(dt, first_day);
    index+=7;
    int day = dt.guessDay(index);
    int month = dt.guessMonth(index);
    dateTime next_dt (day, month, globalConstants::thisYear);
    first_day.set(next_dt);
    displayDates(first_day);
    updateReservations();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void test()
{
    QMessageBox msgBox;
    msgBox.setText("TEST");
    msgBox.exec();
}

void MainWindow::on_actionAdd_3_triggered()
{
    //Room->Add Button

    ANR = new addnewroom (this, ui->reservationCalendar, &db, &rooms_on_display);
    ANR->show();

    //QMessageBox msgBox;
    //msgBox.setText(toQString(std::to_string(x)));
    //msgBox.exec();
}

void MainWindow::on_actionSayHello_triggered()
{
    dateTime dt(12, 12, 2022);
    vector <Reservation> all = db.getAllReservationsAtDate(dt);

    for (int i = 0; i < all.size(); i++)
    {
        QMessageBox msgBox;
        msgBox.setText(toQString(all[i].sayHello()));
        msgBox.exec();

    }
}


void MainWindow::on_actionTEST_triggered()
{

}


void MainWindow::on_actioninfo_triggered()
{
    QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
    QModelIndex QMI = selection.at(0);
    int row = QMI.row();
    if (row > 0)
    {
        int ID = rooms_on_display[--row];
        int index = 0;
        for (int i = 0; i < db.rooms.size(); i++)
        {
            if (db.rooms[i].id == ID)
            {
                index = i;
                break;
            }
        }
        QMessageBox msgBox;
        msgBox.setText("Room ID: " + toQString(std::to_string(db.rooms[index].id)) + ", Description: " + toQString(db.rooms[index].description) + ", Max people: " + toQString(std::to_string(db.rooms[index].max_people)) + ", Cost rate (price per night): " + toQString(std::to_string(db.rooms[index].cost_rate)));
        msgBox.exec();
    }
}


void MainWindow::on_actionRemove_3_triggered()
{
    try {
        QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
        QModelIndex QMI = selection.at(0);
        int row = QMI.row();
        if (row > 0)
        {
            int ID = rooms_on_display[--row];
            int index = 0;
            for (int i = 0; i < db.rooms.size(); i++)
            {
                if (db.rooms[i].id == ID)
                {
                    index = i;
                    break;
                }
            }
            db.rooms.erase(db.rooms.begin() + index);
            db.saveRooms();
            updateCalendar();
            QMessageBox msgBox;
            msgBox.setText("Removed");
            msgBox.exec();
        } else {
            QMessageBox msgBox;
            msgBox.setText("No room selected");
            msgBox.exec();
        }
    } catch (...)
    {
        QMessageBox msgBox;
        msgBox.setText("Unexpected error");
        msgBox.exec();
    }
}

void MainWindow::on_actionInfo_triggered()
{
    QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
    QModelIndex QMI = selection.at(0);
    int row = QMI.row();
    int column = QMI.column();
    int index = 0;
    if (row > 0)
    {
        int ID = rooms_on_display[--row];
        for (int i = 0; i < db.rooms.size(); i++)
        {
            if (db.rooms[i].id == ID)
            {
                index = i;
                break;
            }
        }
    } else {
        return;
    }
    vector <Reservation> all = db.getAllReservationsAtDate(days_of_week[column]);

    for (int i = 0; i < all.size(); i++)
    {
        if (all[i].getRoom().id == index)
        {
            QMessageBox msgBox;
            msgBox.setText(toQString(all[i].sayHello()));
            msgBox.exec();
            return;
        }
    }
}

void MainWindow::on_actionUpdate_triggered()
{

}


void MainWindow::on_actionRemove_2_triggered()
{

}



void MainWindow::on_actionAdd_2_triggered()
{
    addnewreservation res_wind;
    res_wind.exec();
}

