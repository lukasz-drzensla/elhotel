#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addnewroom.h"
#include "header/dataBase.h"
#include <vector>
#include "header/dateTime.h"
#include "header/Reservation.h"

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

private:
    Ui::MainWindow *ui;
    addnewroom *ANR;
    dataBase db{};
    std::vector <int> days_of_week{};
    std::vector <int> rooms_on_display{};
    void updateCalendar();
};
#endif // MAINWINDOW_H
