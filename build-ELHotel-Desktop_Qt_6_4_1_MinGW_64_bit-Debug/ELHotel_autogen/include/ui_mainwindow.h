/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd;
    QAction *actionRemove;
    QAction *actionAdd_2;
    QAction *actionRemove_2;
    QAction *actionEdit;
    QAction *actionAdd_3;
    QAction *actionSayHello;
    QWidget *centralwidget;
    QTableWidget *reservationCalendar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuReservation;
    QMenu *menuGuest;
    QMenu *menuRoom;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName("actionAdd");
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName("actionRemove");
        actionAdd_2 = new QAction(MainWindow);
        actionAdd_2->setObjectName("actionAdd_2");
        actionRemove_2 = new QAction(MainWindow);
        actionRemove_2->setObjectName("actionRemove_2");
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName("actionEdit");
        actionAdd_3 = new QAction(MainWindow);
        actionAdd_3->setObjectName("actionAdd_3");
        actionSayHello = new QAction(MainWindow);
        actionSayHello->setObjectName("actionSayHello");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        reservationCalendar = new QTableWidget(centralwidget);
        if (reservationCalendar->columnCount() < 7)
            reservationCalendar->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (reservationCalendar->rowCount() < 3)
            reservationCalendar->setRowCount(3);
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        reservationCalendar->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        reservationCalendar->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        reservationCalendar->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QFont font1;
        font1.setItalic(true);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        reservationCalendar->setItem(0, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        reservationCalendar->setItem(0, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font1);
        reservationCalendar->setItem(0, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font1);
        reservationCalendar->setItem(0, 3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font1);
        reservationCalendar->setItem(0, 4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font1);
        reservationCalendar->setItem(0, 5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font1);
        reservationCalendar->setItem(0, 6, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        reservationCalendar->setItem(1, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        reservationCalendar->setItem(1, 1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        reservationCalendar->setItem(1, 2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        reservationCalendar->setItem(1, 3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        reservationCalendar->setItem(2, 1, __qtablewidgetitem21);
        reservationCalendar->setObjectName("reservationCalendar");
        reservationCalendar->setGeometry(QRect(0, 0, 791, 551));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuReservation = new QMenu(menubar);
        menuReservation->setObjectName("menuReservation");
        menuGuest = new QMenu(menubar);
        menuGuest->setObjectName("menuGuest");
        menuRoom = new QMenu(menubar);
        menuRoom->setObjectName("menuRoom");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuReservation->menuAction());
        menubar->addAction(menuGuest->menuAction());
        menubar->addAction(menuRoom->menuAction());
        menuReservation->addAction(actionAdd_2);
        menuReservation->addAction(actionRemove_2);
        menuReservation->addAction(actionEdit);
        menuGuest->addAction(actionAdd);
        menuGuest->addAction(actionRemove);
        menuGuest->addAction(actionSayHello);
        menuRoom->addAction(actionAdd_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        actionRemove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        actionAdd_2->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        actionRemove_2->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        actionEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        actionAdd_3->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        actionSayHello->setText(QCoreApplication::translate("MainWindow", "SayHello", nullptr));
        QTableWidgetItem *___qtablewidgetitem = reservationCalendar->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Monday", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = reservationCalendar->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Tuesday", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = reservationCalendar->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Wednesday", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = reservationCalendar->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Thursday", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = reservationCalendar->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Friday", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = reservationCalendar->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Saturday", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = reservationCalendar->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Sunday", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = reservationCalendar->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = reservationCalendar->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "ROOM 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = reservationCalendar->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "ROOM 2", nullptr));

        const bool __sortingEnabled = reservationCalendar->isSortingEnabled();
        reservationCalendar->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem10 = reservationCalendar->item(0, 0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "19.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = reservationCalendar->item(0, 1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "20.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = reservationCalendar->item(0, 2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "21.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = reservationCalendar->item(0, 3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "22.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = reservationCalendar->item(0, 4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "23.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = reservationCalendar->item(0, 5);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "24.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = reservationCalendar->item(0, 6);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "25.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = reservationCalendar->item(1, 0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "yee", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = reservationCalendar->item(1, 2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "yee", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = reservationCalendar->item(1, 3);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "yee", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = reservationCalendar->item(2, 1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "test", nullptr));
        reservationCalendar->setSortingEnabled(__sortingEnabled);

        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuReservation->setTitle(QCoreApplication::translate("MainWindow", "Reservation", nullptr));
        menuGuest->setTitle(QCoreApplication::translate("MainWindow", "Guest", nullptr));
        menuRoom->setTitle(QCoreApplication::translate("MainWindow", "Room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
