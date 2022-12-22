#include "mainwindow.h"
#include "./ui_mainwindow.h"

//Reservation system libraries
#include "header/Reservation.h"
#include "header/dateTime.h"
#include "header/globalConstants.h"
#include <fstream>
#include <vector>
#include "header/dataBase.h"
#include "header/Room.h"
#include <QMessageBox>

dataBase db;

std::string toSTD (QString qs)
{
    return qs.toStdString();
}

QString toQString (std::string ss)
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


    db.init(globalConstants::thisYear); //init the database with current year

    Reservation guest(globalConstants::next_index, db.rooms[0], "Janusz Pawlacz", dateTime(9, 12, 2022), dateTime(13, 12, 2022), "666-666-666", 0);
    db.autoAddReservation(guest);
    Reservation guest2(globalConstants::next_index, db.rooms[1], "Janusz Nosacz", dateTime(9, 12, 2022), dateTime(12, 12, 2022), "666-666-666", 0);
    db.autoAddReservation(guest2);
    Reservation guest3(globalConstants::next_index, db.rooms[1], "Janusz Janusz", dateTime(9, 12, 2022), dateTime(12, 12, 2022), "666-666-666", 0);
    guest = guest3;


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAdd_3_triggered()
{
    ui->reservationCalendar->insertRow(ui->reservationCalendar->rowCount());
    ui->reservationCalendar->setVerticalHeaderItem(ui->reservationCalendar->rowCount()-1, new QTableWidgetItem("New Room"));
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

