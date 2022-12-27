#include "addnewreservation.h"
#include "ui_addnewreservation.h"

addnewreservation::addnewreservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewreservation)
{
    ui->setupUi(this);
}

addnewreservation::~addnewreservation()
{
    delete ui;
}
