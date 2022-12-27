#ifndef ADDNEWRESERVATION_H
#define ADDNEWRESERVATION_H

#include <QDialog>

namespace Ui {
class addnewreservation;
}

class addnewreservation : public QDialog
{
    Q_OBJECT

public:
    explicit addnewreservation(QWidget *parent = nullptr);
    ~addnewreservation();

private:
    Ui::addnewreservation *ui;
};

#endif // ADDNEWRESERVATION_H
