#include "addnewroom.h"
#include "ui_addnewroom.h"
#include <QMessageBox>

addnewroom::addnewroom(QWidget *parent, QTableWidget* calendar, dataBase* data, std::vector <int> *rooms_on_display) :
    QDialog(parent),
    ui(new Ui::addnewroom)
{
    db=data;
    cal=calendar;
    r_o_d = rooms_on_display;
    ui->setupUi(this);
    ui->ID_label->setText(QString::fromStdString(std::to_string(globalConstants::next_room_index)));
    ui->spin_cost->setValue(globalConstants::roomRate);
}

addnewroom::~addnewroom()
{
    delete ui;
}

void addnewroom::on_Add_clicked()
{
    QString qs=ui->room_des->toPlainText();
    Room r (globalConstants::next_room_index, ui->spin_people->value(), qs.toStdString(), ui->spin_cost->value());
    db->rooms.push_back(r);
    //refresh calendar view
    r_o_d->clear();
    cal->setRowCount(1);
    for (int i = 0; i < db->rooms.size(); i++)
    {
        cal->insertRow(cal->rowCount());
        QString des = QString::fromStdString(db->rooms[i].description);
        cal->setVerticalHeaderItem(cal->rowCount()-1, new QTableWidgetItem(des));
        r_o_d->push_back(db->rooms[i].id);
    }
    db->saveRooms();
    globalConstants::next_room_index++;
    globalConstants::save();
    close();
}


void addnewroom::on_cancelBut_clicked()
{
    close();
}

