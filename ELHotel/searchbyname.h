#ifndef SEARCHBYNAME_H
#define SEARCHBYNAME_H

#include <QDialog>
#include "header/Reservation.h"
#include "header/dataBase.h"
#include <string>
#include <vector>

namespace Ui {
class searchByName;
}

class searchByName : public QDialog
{
    Q_OBJECT

public:
    explicit searchByName(QWidget *parent = nullptr, dataBase *_db = nullptr, int _sel = 0);
    ~searchByName();

private slots:
    void on_searchbtn_clicked();

private:
    Ui::searchByName *ui;
    dataBase *db{};
    int sel{};
};

#endif // SEARCHBYNAME_H
