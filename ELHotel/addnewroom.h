#ifndef ADDNEWROOM_H
#define ADDNEWROOM_H

#include <QDialog>
#include <QTableWidget>
#include "header/dataBase.h"
#include "header/Room.h"
#include "header/globalConstants.h"
#include <vector>
#include "viewcalendarupdater.h"

namespace Ui {
class addnewroom;
}

class addnewroom : public QDialog
{
    Q_OBJECT

public:
    explicit addnewroom(QWidget *parent = nullptr, QTableWidget* calendar = nullptr, dataBase* data = nullptr, std::vector <int> *rooms_on_display = nullptr, viewCalendarUpdater *_calUpd = nullptr);
    ~addnewroom();

private slots:
    void on_Add_clicked();

    void on_cancelBut_clicked();

private:
    Ui::addnewroom *ui;
    QTableWidget* cal;
    dataBase* db;
    viewCalendarUpdater *calUpd{};
};

#endif // ADDNEWROOM_H
