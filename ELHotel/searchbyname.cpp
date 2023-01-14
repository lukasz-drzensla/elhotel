#include "searchbyname.h"
#include "ui_searchbyname.h"

searchByName::searchByName(QWidget *parent, dataBase *_db, int _sel) :
    QDialog(parent),
    ui(new Ui::searchByName)
{
    db=_db;
    ui->setupUi(this);
    sel = _sel;
    switch (_sel)
    {
    case 0:
    {
        ui->var_txt->setText("Name: ");
        break;
    }
    case 1:
    {
        ui->var_txt->setText("Phone: ");
        break;
    }
    }
}

searchByName::~searchByName()
{
    delete ui;
}

void searchByName::on_searchbtn_clicked()
{
    std::string result{};


    std::string name = ui->textEdit->toPlainText().toStdString();
    std::vector <Reservation> all;

    switch (sel)
    {
    case 0:
    {
        all = db->getAllReservationsByName(name);
        break;
    }
    case 1:
    {
        all = db->getAllReservationsByPhone(name);
        break;
    }
    }

    for (int i = 0; i < all.size(); i++)
    {
        result+=all[i].sayHello() +"\n\n";
    }
    ui->result_txt->setText(QString::fromStdString(result));
}

