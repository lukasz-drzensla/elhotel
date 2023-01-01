#ifndef EDITRESERVATION_H
#define EDITRESERVATION_H

#include <QDialog>

namespace Ui {
class editreservation;
}

class editreservation : public QDialog
{
    Q_OBJECT

public:
    explicit editreservation(QWidget *parent = nullptr);
    ~editreservation();

private:
    Ui::editreservation *ui;
};

#endif // EDITRESERVATION_H
