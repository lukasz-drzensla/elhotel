#ifndef JUMPTODATE_H
#define JUMPTODATE_H

#include <QDialog>
#include "viewcalendarupdater.h"
#include "header/globalConstants.h"
#include "header/dateTime.h"

namespace Ui {
class jumptodate;
}

class jumptodate : public QDialog
{
    Q_OBJECT

public:
    explicit jumptodate(QWidget *parent = nullptr, viewCalendarUpdater *_calendar = nullptr, dateTime *_first_day = nullptr);
    ~jumptodate();

private slots:
    void on_Jump_clicked();

private:
    Ui::jumptodate *ui;
    viewCalendarUpdater *calendar{};
    dateTime *first_day{};
};

#endif // JUMPTODATE_H
