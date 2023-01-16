#include "mainwindow.h"
#include "./ui_mainwindow.h"

//Reservation system libraries

#include "header/globalConstants.h"
#include <fstream>
#include <vector>
#include "header/Room.h"
#include <QMessageBox>
#include <time.h>

int getTodayMonth()
{
    time_t t = time(NULL);
    struct tm *t_struct = localtime (&t);
    return t_struct->tm_mon;
}

int getTodayDay()
{
    time_t t = time(NULL);
    struct tm *t_struct = localtime (&t);
    return t_struct->tm_mday;
}

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
    db.init(globalConstants::sharedVariables.thisYear); //init the database with current year
    db.load(true);

    //initialize room view
    calUpd->updateCalendar();

    //initialize days of week view
    dateTime dt1 (getTodayDay(),getTodayMonth()+1,globalConstants::sharedVariables.thisYear);
    ui->statusbar->showMessage("Today is: " + QString::fromStdString(dt1.sayHello()));
    first_day.set(dt1);
    calUpd->displayDates(&first_day);

    //initialize reservations view
    calUpd->updateReservations();
}

void MainWindow::on_actionPrevious_week_triggered()
{
    //calculate which day of the year is the currently displayed first day, then move by one week prior and initialize dates display again
    dateTime dt (1, 1, globalConstants::sharedVariables.thisYear);
    int index = dt.getDifference(dt, first_day);
    index-=7;
    int day = dt.guessDay(index);
    int month = dt.guessMonth(index);
    dateTime prev_dt (day, month, globalConstants::sharedVariables.thisYear);
    first_day.set(prev_dt);
    calUpd->displayDates(&first_day);
    calUpd->updateReservations();
}

void MainWindow::on_actionNext_week_triggered()
{
    //calculate which day of the year is the currently displayed first day, then move by one week forward and initialize dates display again
    dateTime dt (1, 1, globalConstants::sharedVariables.thisYear);
    int isLeap = dt.isLeap();
    int max=365;
    //if the year is leap then change the number of days
    if (isLeap)
        max=366;
    //if showing the next week would result in showing further in the next year, do not allow
    if (days_of_week[13]<max-5)
    {
        int index = dt.getDifference(dt, first_day);
        index+=7;
        int day = dt.guessDay(index);
        int month = dt.guessMonth(index);
        dateTime next_dt (day, month, globalConstants::sharedVariables.thisYear);
        first_day.set(next_dt);
        calUpd->displayDates(&first_day);
        calUpd->updateReservations();
    } else {
        QMessageBox msgBox;
        msgBox.setText("End of the year");
        msgBox.exec();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void test()
{

}

void MainWindow::on_actionAdd_3_triggered()
{
    //Room->Add Button
    ANR = new addnewroom (this, ui->reservationCalendar, &db, &rooms_on_display, calUpd);
    ANR->show();
}

void MainWindow::on_actionSayHello_triggered()
{}


void MainWindow::on_actionTEST_triggered()
{

}


void MainWindow::on_actioninfo_triggered()
{
    //get selected cells
    QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
    if (selection.empty())
    {
        return;
    }
    //get first selected cell index
    QModelIndex QMI = selection.at(0);
    int row = QMI.row();
    //check if a cell is not a date
    if (row > 0)
    {
        int ID = rooms_on_display[--row];
        int index = 0;
        //search for a room with being given the ID of the selected room
        for (int i = 0; i < db.rooms.size(); i++)
        {
            if (db.rooms[i].id == ID)
            {
                index = i;
                break;
            }
        }
        //display the result
        QMessageBox msgBox;
        msgBox.setText("Room ID: " + toQString(std::to_string(db.rooms[index].id)) + ", Description: " + toQString(db.rooms[index].description) + ", Max people: " + toQString(std::to_string(db.rooms[index].max_people)) + ", Cost rate (price per night): " + toQString(std::to_string(db.rooms[index].cost_rate)));
        msgBox.exec();
    }
}


void MainWindow::on_actionRemove_3_triggered()
{
    QMessageBox::StandardButton user_action_confirmation = QMessageBox::question(this, "Remove a room", "Are you sure you want to remove the selected room?", QMessageBox::Yes|QMessageBox::No);
      if (user_action_confirmation == QMessageBox::Yes) {
        //proceed
      } else {
        return;
      }
    try {
        //get selected cells
        QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
        if (selection.empty())
        {
            return;
        }
        //get first selected cell
        QModelIndex QMI = selection.at(0);
        int row = QMI.row();
        if (row > 0)
        {
            //find ID of the room
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
            //db.rooms.erase(db.rooms.begin()+index); //for a reason which remains unknown to me it always deletes the last element
            //remove a room
            vector <Room> temp{};
            for (int i = 0; i < db.rooms.size(); i++)
            {
                if (i!=index)
                    temp.push_back(db.rooms[i]);
            }
            db.rooms.clear();
            db.rooms=temp;

            //save and reinitialize
            db.saveRooms();
            calUpd->updateCalendar();
            calUpd->updateReservations();
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
    //get selection
    QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
    if (selection.empty())
    {
        return;
    }
    //get first selected cell
    QModelIndex QMI = selection.at(0);
    int row = QMI.row();
    int column = QMI.column();
    int ID{};
    //check if the selected cell is not a date display, get room ID
    if (row > 0)
    {
        ID = rooms_on_display[--row];
    } else {
        return;
    }
    //get all the reservations for the specified date
    vector <Reservation> all = db.getAllReservationsAtDate(days_of_week[column]);
    //find the one with the given room ID
    for (int i = 0; i < all.size(); i++)
    {
        if (all[i].getRoom().id == ID)
        {
            //show results
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
    //get selection
    QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
    if (selection.empty())
    {
        return;
    }
    //get the first selected cell
    QModelIndex QMI = selection.at(0);
    int row = QMI.row();
    int column = QMI.column();
    int ID{};
    int res_id{};
    //get room ID
    if (row > 0)
    {
        ID = rooms_on_display[--row];
    } else {
        return;
    }
    //get all the reservations for the specified date
    vector <Reservation> all = db.getAllReservationsAtDate(days_of_week[column]);

    //if room ID matches the room ID in the reservation, head to removing - but first ask the user again whether they really wish to remove it or not
    for (int i = 0; i < all.size(); i++)
    {
        if (all[i].getRoom().id == ID)
        {
            QMessageBox::StandardButton user_action_confirmation = QMessageBox::question(this, "Remove a reservation", "Are you sure you want to remove: " + toQString(all[i].sayHello()), QMessageBox::Yes|QMessageBox::No);
              if (user_action_confirmation == QMessageBox::Yes) {
                //proceed
              } else {
                return;
              }
            res_id = all[i].getID();
            break;
        }
    }
    //remove the reservation
    vector <Reservation> temp{};
    if (res_id%2==0)
    {
        for (int i = 0; i < db.Reservations.even.size(); i++)
        {
            if (db.Reservations.even[i].getID() != res_id)
            {
                temp.push_back(db.Reservations.even[i]);
            }
        }
        db.Reservations.even.clear();
        db.Reservations.even = temp;
    } else {
        for (int i = 0; i < db.Reservations.odd.size(); i++)
        {
            if (db.Reservations.odd[i].getID() != res_id)
            {
                temp.push_back(db.Reservations.odd[i]);
            }
        }
        db.Reservations.odd.clear();
        db.Reservations.odd = temp;
    }

    //save the database and reinitialize display
    db.save();
    calUpd->updateCalendar();
    calUpd->updateReservations();
}



void MainWindow::on_actionAdd_2_triggered()
{
    //first check if the time period does not collide with any other reservations
    int departure_index{};
    QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
    if (selection.empty())
    {
        return;
    }
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
            if (all[i].getRoom().id == ID)
            {
                //found reservation, throw error
                QMessageBox msgBox;
                msgBox.setText("There is already a reservation made for this room for the specified time period");
                msgBox.exec();
                return;
            }
        }
    }
    //if no error and no collision detected, initialize some defaults for the new reservation
    dateTime dt{};
    int day = dt.guessDay(days_of_week[start_column]);
    int month = dt.guessMonth(days_of_week[start_column]);
    dateTime arrival (day, month, globalConstants::sharedVariables.thisYear);
    day = dt.guessDay(departure_index);
    month = dt.guessMonth(departure_index);
    dateTime departure (day, month, globalConstants::sharedVariables.thisYear);
    int duration = dt.getDifference(arrival, departure);
    if (duration < 1)
    {
        QMessageBox msgBox;
        msgBox.setText("Cannot make a zero-nigths reservation");
        msgBox.exec();
        return;
    }
    //if everything is fine proceed to the add reservation dialog
    add_new_res_window = new addnewreservation(this, calUpd, &arrival, &departure, &db, &duration, &db.rooms[index], &enableAutoMarking);
    add_new_res_window->exec();
}


void MainWindow::on_actionEdit_triggered()
{
    //get selection
    QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
    if (selection.empty())
    {
        return;
    }
    //get first selected cell
    QModelIndex QMI = selection.at(0);
    int row = QMI.row();
    int column = QMI.column();
    int ID{};
    int res_id{};
    int index_in_all{};
    //get room ID
    if (row > 0)
    {
        ID = rooms_on_display[--row];
    } else {
        return;
    }
    //get all the reservations at the specified date
    vector <Reservation> all = db.getAllReservationsAtDate(days_of_week[column]);

    for (int i = 0; i < all.size(); i++)
    {
        if (all[i].getRoom().id == ID)
        {
            res_id = all[i].getID();
            index_in_all=i;
            break;
        }
    }
    //get the index at which the reservation is stored in the database
    int index = db.getDBIDByResID(res_id);
    //create a temp value (de facto not a temp) - needed because editreservation requires a pointer and it is not possible to a temporary variable
    Reservation temp_res = all[index_in_all];

    //call edit dialog
    edit_res_window = new editreservation (this, calUpd, &temp_res, &db, index);
    edit_res_window->exec();

    calUpd->updateCalendar();
    calUpd->updateReservations();
}

void MainWindow::changeStatus(int stat)
{
    //get selected cell
    QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
    if (selection.empty())
    {
        return;
    }
    QModelIndex QMI = selection.at(0);
    int row = QMI.row();
    int column = QMI.column();
    int ID{};
    if (row > 0)
    {
        ID = rooms_on_display[--row];
    } else {
        return;
    }
    vector <Reservation> all = db.getAllReservationsAtDate(days_of_week[column]);

    //find the reservation with matching room ID, when found - change status to the provided
    for (int j = 0; j < all.size(); j++)
    {
        if (all[j].getRoom().id == ID)
        {
            int id=db.getDBIDByResID(all[j].getID());
            if (id<0)
            {
                db.Reservations.even[-id].setStatus(stat);
                db.save();
                calUpd->updateCalendar();
                calUpd->updateReservations();
                break;
            } else {
                db.Reservations.odd[id].setStatus(stat);
                db.save();
                calUpd->updateCalendar();
                calUpd->updateReservations();
                break;
            }
            return;
        }
    }
}

//this function automatically calculates whether the guest should pay more or not being given only the information whether they arrived or left
void MainWindow::changeStatusAuto(int stat)
{
    QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
    if (selection.empty())
    {
        return;
    }
    QModelIndex QMI = selection.at(0);
    int row = QMI.row();
    int column = QMI.column();
    int ID{};
    if (row > 0)
    {
        ID = rooms_on_display[--row];
    } else {
        return;
    }
    vector <Reservation> all = db.getAllReservationsAtDate(days_of_week[column]);

    for (int j = 0; j < all.size(); j++)
    {
        if (all[j].getRoom().id == ID)
        {
            int id=db.getDBIDByResID(all[j].getID());
            if (id<0)
            {
                int cost = db.Reservations.even[-id].getCost();
                int paid = db.Reservations.even[-id].getPaid();
                if (stat==1)
                {
                    if (cost-paid==0)
                    {
                        db.Reservations.even[-id].setStatus(1);
                    } else {
                        db.Reservations.even[-id].setStatus(4);
                    }
                } else if (stat==2)
                {
                    if (cost-paid==0)
                    {
                        db.Reservations.even[-id].setStatus(2);
                    } else {
                        db.Reservations.even[-id].setStatus(5);
                    }
                }
                db.save();
                calUpd->updateCalendar();
                calUpd->updateReservations();
                break;
            } else {
                int cost = db.Reservations.odd[id].getCost();
                int paid = db.Reservations.odd[id].getPaid();
                if (stat==1)
                {
                    if (cost-paid==0)
                    {
                        db.Reservations.odd[id].setStatus(1);
                    } else {
                        db.Reservations.odd[id].setStatus(4);
                    }
                } else if (stat==2)
                {
                    if (cost-paid==0)
                    {
                        db.Reservations.odd[id].setStatus(2);
                    } else {
                        db.Reservations.odd[id].setStatus(5);
                    }
                }
                db.save();
                calUpd->updateCalendar();
                calUpd->updateReservations();
                break;
            }
            return;
        }
    }
}

void MainWindow::on_actionMark_as_arrived_and_paid_triggered()
{
    if (!enableAutoMarking)
    {
        changeStatus(1);
    } else {
        QMessageBox msgBox;
        msgBox.setText("Auto - marking is enabled. Disable it or use the automatic functions");
        msgBox.exec();
    }
}


void MainWindow::on_actionMark_as_departed_and_paid_triggered()
{
    if (!enableAutoMarking)
    {
        changeStatus(2);
    } else {
        QMessageBox msgBox;
        msgBox.setText("Auto - marking is enabled. Disable it or use the automatic functions");
        msgBox.exec();
    }
}


void MainWindow::on_actionUnmark_2_triggered()
{
    changeStatus(0);
}


void MainWindow::on_actionMark_as_arrived_and_not_paid_triggered()
{
    if (!enableAutoMarking)
    {
        changeStatus(4);
    } else {
        QMessageBox msgBox;
        msgBox.setText("Auto - marking is enabled. Disable it or use the automatic functions");
        msgBox.exec();
    }
}


void MainWindow::on_actionMark_as_requires_attengion_triggered()
{
    changeStatus(3);
}


void MainWindow::on_actionMark_as_departed_and_not_paid_triggered()
{

    if (!enableAutoMarking)
    {
        changeStatus(5);
    } else {
        QMessageBox msgBox;
        msgBox.setText("Auto - marking is enabled. Disable it or use the automatic functions");
        msgBox.exec();
    }
}


void MainWindow::on_actionEnable_auto_marking_triggered()
{
    if (enableAutoMarking)
    {
        enableAutoMarking=false;
        ui->actionEnable_auto_marking->setText("Enable auto - marking");
        return;
    } else {
        enableAutoMarking=true;
        ui->actionEnable_auto_marking->setText("Disable auto - marking");
        return;
    }
}


void MainWindow::on_actionMark_as_arrived_2_triggered()
{
    if (enableAutoMarking)
    {
        changeStatusAuto(1);
    } else {
        QMessageBox msgBox;
        msgBox.setText("Auto - marking is disabled. Enable it or use the manual functions");
        msgBox.exec();
    }
}


void MainWindow::on_actionMark_as_departed_2_triggered()
{
    if (enableAutoMarking)
    {
        changeStatusAuto(2);
    } else {
        QMessageBox msgBox;
        msgBox.setText("Auto - marking is disabled. Enable it or use the manual functions");
        msgBox.exec();
    }
}

void MainWindow::on_actionReturn_to_today_triggered()
{
    dateTime dt (getTodayDay(),getTodayMonth(),globalConstants::sharedVariables.thisYear);
    first_day.set(dt);
    calUpd->displayDates(&first_day);
    calUpd->updateReservations();
}



//empty but does not work without this

void MainWindow::on_actionMark_as_arrived_triggered()
{
}


void MainWindow::on_actionMark_as_departed_triggered()
{
}


void MainWindow::on_actionMark_as_attention_required_triggered()
{
}


void MainWindow::on_actionUnmark_triggered()
{
}


void MainWindow::on_actionMark_as_arrived_but_not_paid_triggered()
{
}


void MainWindow::on_actionMark_as_departed_but_not_paid_triggered()
{
}






void MainWindow::on_actionJump_to_a_date_triggered()
{
    jump = new jumptodate(this, calUpd, &first_day);
    jump->exec();
}


void MainWindow::on_actionSearch_by_name_triggered()
{
    searchByName sbn (this, &db);
    sbn.exec();
}


void MainWindow::on_reservationCalendar_itemDoubleClicked(QTableWidgetItem *item)
{
    QModelIndexList selection = ui->reservationCalendar->selectionModel()->selectedIndexes();
    if (selection.empty())
    {
        return;
    }
    QModelIndex QMI = selection.at(0);
    int row = QMI.row();
    int column = QMI.column();
    int ID{};
    int res_id{};
    int index_in_all{};
    if (row > 0)
    {
        ID = rooms_on_display[--row];
    } else {
        return;
    }
    vector <Reservation> all = db.getAllReservationsAtDate(days_of_week[column]);

    for (int i = 0; i < all.size(); i++)
    {
        if (all[i].getRoom().id == ID)
        {
            res_id = all[i].getID();
            index_in_all=i;
            break;
        }
    }

    int index = db.getDBIDByResID(res_id);
    Reservation temp_res = all[index_in_all];

    edit_res_window = new editreservation (this, calUpd, &temp_res, &db, index);
    edit_res_window->exec();

    //db.save();
    calUpd->updateCalendar();
    calUpd->updateReservations();
}


void MainWindow::on_actionSearch_by_phone_triggered()
{
    searchByName sbn (this, &db, 1);
    sbn.exec();
}

