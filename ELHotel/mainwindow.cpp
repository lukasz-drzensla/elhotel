#include "mainwindow.h"
#include "./ui_mainwindow.h"

//Reservation system libraries

#include "header/globalConstants.h"
#include <fstream>
#include <vector>
#include "header/Room.h"
#include <QMessageBox>



std::string MainWindow::toSTD (QString qs)
{
    return qs.toStdString();
}

QString MainWindow::toQString (std::string ss)
{
    return QString::fromStdString(ss);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->reservationCalendar);
    ui->reservationCalendar->setEditTriggers(QAbstractItemView::NoEditTriggers);

    calUpd = new viewCalendarUpdater(&rooms_on_display, ui->reservationCalendar, &db, &days_of_week, &first_day);

    //initalize database
    db.init(globalConstants::thisYear); //init the database with current year
    db.load(true);

    //initialize room view
    calUpd->updateCalendar();

    //initialize days of week view
    dateTime dt (19,12,globalConstants::thisYear);
    first_day.set(dt);
    calUpd->displayDates(&first_day);

    //initialize reservations view
    calUpd->updateReservations();
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
    calUpd->displayDates(&first_day);
    calUpd->updateReservations();
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
    calUpd->displayDates(&first_day);
    calUpd->updateReservations();
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

    ANR = new addnewroom (this, ui->reservationCalendar, &db, &rooms_on_display, calUpd);
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
            calUpd->updateCalendar();
            calUpd->updateReservations();
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

//do not remove - QT creator goes crazy when this particular empty (!!) function is removed
void MainWindow::on_actionUpdate_triggered()
{

}


void MainWindow::on_actionRemove_2_triggered()
{

}



void MainWindow::on_actionAdd_2_triggered()
{
    int departure_index{};
    QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
    QModelIndex QMI = selection.at(0);
    int start_row = QMI.row();
    int start_column = QMI.column();
    int index = 0;
    int ID {};
    for (int k = 0; k < selection.size(); k++)
    {
        QMI = selection.at(k);
        int row = QMI.row();
        if (row != start_row)
        {
            break;
        }
        int column = QMI.column();
        departure_index = days_of_week[column];
        if (row > 0)
        {
            ID = rooms_on_display[--row];
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
                //found reservation, throw error
                QMessageBox msgBox;
                msgBox.setText("There is already a reservation made for this room for the specified time period");
                msgBox.exec();
                return;
            }
        }
    }
    //if no error
    dateTime dt{};
    int day = dt.guessDay(days_of_week[start_column]);
    int month = dt.guessMonth(days_of_week[start_column]);
    dateTime arrival (day, month, globalConstants::thisYear);
    day = dt.guessDay(departure_index);
    month = dt.guessMonth(departure_index);
    dateTime departure (day, month, globalConstants::thisYear);
    int duration = dt.getDifference(arrival, departure);
    if (duration < 1)
    {
        QMessageBox msgBox;
        msgBox.setText("Cannot make a zero-nigths reservation");
        msgBox.exec();
        return;
    }

    add_new_res_window = new addnewreservation(this, calUpd, &arrival, &departure, &db, &duration, &db.rooms[index]);
    add_new_res_window->exec();
}

