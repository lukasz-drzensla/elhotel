#include "searchbyname.h"
#include "ui_searchbyname.h"

searchByName::searchByName(QWidget *parent, dataBase *_db) :
    QDialog(parent),
    ui(new Ui::searchByName)
{
    db=_db;
    ui->setupUi(this);
}

searchByName::~searchByName()
{
    delete ui;
}

void searchByName::on_searchbtn_clicked()
{
    std::string result{};
    std::string name = ui->textEdit->toPlainText().toStdString();
    std::vector <Reservation> all = db->getAllReservationsByName(name);
    for (int i = 0; i < all.size(); i++)
    {
        result+=all[i].sayHello() +"\n\n";
    }
    ui->result_txt->setText(QString::fromStdString(result));
}

