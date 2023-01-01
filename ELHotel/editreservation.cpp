#include "editreservation.h"
#include "ui_editreservation.h"

editreservation::editreservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editreservation)
{
    ui->setupUi(this);
}

editreservation::~editreservation()
{
    delete ui;
}
