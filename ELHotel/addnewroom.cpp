#include "addnewroom.h"
#include "ui_addnewroom.h"
#include <QMessageBox>

addnewroom::addnewroom(QWidget *parent, QTableWidget* calendar, dataBase* data, std::vector <int> *rooms_on_display, viewCalendarUpdater *_calUpd) :
    QDialog(parent),
    ui(new Ui::addnewroom)
{
    db=data;
    cal=calendar;
    calUpd = _calUpd;
    ui->setupUi(this);
    ui->ID_label->setText(QString::fromStdString(std::to_string(globalConstants::sharedVariables.next_room_index)));
    ui->spin_cost->setValue(globalConstants::sharedVariables.roomRate);
}

addnewroom::~addnewroom()
{
    delete ui;
}

void addnewroom::on_Add_clicked()
{
    QString qs=ui->room_des->toPlainText();
    Room r (globalConstants::sharedVariables.next_room_index, ui->spin_people->value(), qs.toStdString(), ui->spin_cost->value());
    db->rooms.push_back(r);
    //refresh calendar view
    calUpd->updateCalendar();
    calUpd->updateReservations();
    db->saveRooms();
    globalConstants::sharedVariables.next_room_index++;
    globalConstants::save();
    close();
}


void addnewroom::on_cancelBut_clicked()
{
    close();
}

