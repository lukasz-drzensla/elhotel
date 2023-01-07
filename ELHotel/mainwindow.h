#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addnewroom.h"
#include "header/dataBase.h"
#include <vector>
#include "header/dateTime.h"
#include "header/Reservation.h"
#include "addnewreservation.h"
#include "viewcalendarupdater.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAdd_3_triggered();

    void on_actionSayHello_triggered();

    void on_actionTEST_triggered();

    void on_actioninfo_triggered();

    void on_actionRemove_3_triggered();

    void on_actionUpdate_triggered();

    void on_actionInfo_triggered();

    void on_actionRemove_2_triggered();

    void on_actionPrevious_week_triggered();

    void on_actionNext_week_triggered();

    void on_actionAdd_2_triggered();

    void on_actionEdit_triggered();

    void on_actionMark_as_arrived_triggered();

    void on_actionMark_as_departed_triggered();

    void on_actionMark_as_attention_required_triggered();

    void on_actionUnmark_triggered();

    void on_actionMark_as_arrived_but_not_paid_triggered();

    void on_actionMark_as_departed_but_not_paid_triggered();

    void on_actionMark_as_arrived_and_paid_triggered();

    void on_actionMark_as_departed_and_paid_triggered();

    void on_actionUnmark_2_triggered();

    void on_actionMark_as_arrived_and_not_paid_triggered();

    void on_actionMark_as_requires_attengion_triggered();

    void on_actionMark_as_departed_and_not_paid_triggered();

    void on_actionEnable_auto_marking_triggered();

    void on_actionMark_as_arrived_2_triggered();

    void on_actionMark_as_departed_2_triggered();

private:
    Ui::MainWindow *ui;
    addnewroom *ANR{};
    addnewreservation *add_new_res_window{};
    dataBase db{};
    std::vector <int> days_of_week{};
    std::vector <int> rooms_on_display{};
    dateTime first_day{};
    std::string toSTD (QString qs);
    QString toQString (std::string ss);
    viewCalendarUpdater *calUpd;
    void changeStatus(int stat);
    void changeStatusAuto(int stat);
    bool enableAutoMarking=true;
};
#endif // MAINWINDOW_H
