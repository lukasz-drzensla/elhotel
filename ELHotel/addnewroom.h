#ifndef ADDNEWROOM_H
#define ADDNEWROOM_H

#include <QDialog>
#include <QTableWidget>
#include "header/dataBase.h"
#include "header/Room.h"
#include "header/globalConstants.h"
#include <vector>

namespace Ui {
class addnewroom;
}

class addnewroom : public QDialog
{
    Q_OBJECT

public:
    explicit addnewroom(QWidget *parent = nullptr, QTableWidget* calendar = nullptr, dataBase* data = nullptr, std::vector <int> *rooms_on_display = nullptr);
    ~addnewroom();

private slots:
    void on_Add_clicked();

    void on_cancelBut_clicked();

private:
    Ui::addnewroom *ui;
    QTableWidget* cal;
    dataBase* db;
    vector <int> *r_o_d;
};

#endif // ADDNEWROOM_H
