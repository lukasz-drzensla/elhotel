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
#include <QtWidgets/QToolBar>
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
    QAction *actionTEST;
    QAction *actionTEST20;
    QAction *actionRemove_3;
    QAction *actioninfo;
    QAction *actionUpdate;
    QAction *actionNext_week;
    QAction *actionPrevious_week;
    QAction *actionInfo;
    QWidget *centralwidget;
    QTableWidget *reservationCalendar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuReservation;
    QMenu *menuGuest;
    QMenu *menuRoom;
    QMenu *menuView;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1460, 600);
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
        actionTEST = new QAction(MainWindow);
        actionTEST->setObjectName("actionTEST");
        actionTEST20 = new QAction(MainWindow);
        actionTEST20->setObjectName("actionTEST20");
        actionRemove_3 = new QAction(MainWindow);
        actionRemove_3->setObjectName("actionRemove_3");
        actioninfo = new QAction(MainWindow);
        actioninfo->setObjectName("actioninfo");
        actionUpdate = new QAction(MainWindow);
        actionUpdate->setObjectName("actionUpdate");
        actionNext_week = new QAction(MainWindow);
        actionNext_week->setObjectName("actionNext_week");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNext_week->setIcon(icon);
        actionPrevious_week = new QAction(MainWindow);
        actionPrevious_week->setObjectName("actionPrevious_week");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/resources/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrevious_week->setIcon(icon1);
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName("actionInfo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        reservationCalendar = new QTableWidget(centralwidget);
        if (reservationCalendar->columnCount() < 14)
            reservationCalendar->setColumnCount(14);
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
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        reservationCalendar->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        if (reservationCalendar->rowCount() < 1)
            reservationCalendar->setRowCount(1);
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font);
        reservationCalendar->setVerticalHeaderItem(0, __qtablewidgetitem14);
        QFont font1;
        font1.setItalic(true);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font1);
        reservationCalendar->setItem(0, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font1);
        reservationCalendar->setItem(0, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font1);
        reservationCalendar->setItem(0, 2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font1);
        reservationCalendar->setItem(0, 3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font1);
        reservationCalendar->setItem(0, 4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font1);
        reservationCalendar->setItem(0, 5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font1);
        reservationCalendar->setItem(0, 6, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        reservationCalendar->setItem(0, 7, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        reservationCalendar->setItem(0, 8, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        reservationCalendar->setItem(0, 9, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        reservationCalendar->setItem(0, 10, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        reservationCalendar->setItem(0, 11, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        reservationCalendar->setItem(0, 12, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        reservationCalendar->setItem(0, 13, __qtablewidgetitem28);
        reservationCalendar->setObjectName("reservationCalendar");
        reservationCalendar->setGeometry(QRect(0, 0, 1441, 521));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1460, 21));
        menubar->setNativeMenuBar(true);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuReservation = new QMenu(menubar);
        menuReservation->setObjectName("menuReservation");
        menuGuest = new QMenu(menubar);
        menuGuest->setObjectName("menuGuest");
        menuRoom = new QMenu(menubar);
        menuRoom->setObjectName("menuRoom");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuReservation->menuAction());
        menubar->addAction(menuGuest->menuAction());
        menubar->addAction(menuRoom->menuAction());
        menuReservation->addAction(actionAdd_2);
        menuReservation->addAction(actionRemove_2);
        menuReservation->addAction(actionEdit);
        menuReservation->addSeparator();
        menuReservation->addAction(actionInfo);
        menuGuest->addAction(actionAdd);
        menuGuest->addAction(actionRemove);
        menuRoom->addAction(actionAdd_3);
        menuRoom->addAction(actionRemove_3);
        menuRoom->addSeparator();
        menuRoom->addAction(actioninfo);
        menuView->addAction(actionNext_week);
        menuView->addAction(actionPrevious_week);
        toolBar->addAction(actionPrevious_week);
        toolBar->addAction(actionNext_week);

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
        actionTEST->setText(QCoreApplication::translate("MainWindow", "TEST", nullptr));
        actionTEST20->setText(QCoreApplication::translate("MainWindow", "TEST20", nullptr));
        actionRemove_3->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        actioninfo->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
#if QT_CONFIG(tooltip)
        actioninfo->setToolTip(QCoreApplication::translate("MainWindow", "Information about a room", nullptr));
#endif // QT_CONFIG(tooltip)
        actionUpdate->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        actionNext_week->setText(QCoreApplication::translate("MainWindow", "Next week", nullptr));
        actionPrevious_week->setText(QCoreApplication::translate("MainWindow", "Previous week", nullptr));
        actionInfo->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
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
        QTableWidgetItem *___qtablewidgetitem7 = reservationCalendar->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Monday", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = reservationCalendar->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Tuesday", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = reservationCalendar->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Wednesday", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = reservationCalendar->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Thursday", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = reservationCalendar->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Friday", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = reservationCalendar->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Saturday", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = reservationCalendar->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Sunday", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = reservationCalendar->verticalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));

        const bool __sortingEnabled = reservationCalendar->isSortingEnabled();
        reservationCalendar->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem15 = reservationCalendar->item(0, 0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "19.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = reservationCalendar->item(0, 1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "20.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = reservationCalendar->item(0, 2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "21.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = reservationCalendar->item(0, 3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "22.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = reservationCalendar->item(0, 4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "23.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = reservationCalendar->item(0, 5);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "24.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = reservationCalendar->item(0, 6);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "25.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = reservationCalendar->item(0, 7);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "26.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = reservationCalendar->item(0, 8);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "27.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = reservationCalendar->item(0, 9);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "28.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = reservationCalendar->item(0, 10);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "29.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = reservationCalendar->item(0, 11);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "30.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = reservationCalendar->item(0, 12);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "31.12", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = reservationCalendar->item(0, 13);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "1.1", nullptr));
        reservationCalendar->setSortingEnabled(__sortingEnabled);

        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuReservation->setTitle(QCoreApplication::translate("MainWindow", "Reservation", nullptr));
        menuGuest->setTitle(QCoreApplication::translate("MainWindow", "Guest", nullptr));
        menuRoom->setTitle(QCoreApplication::translate("MainWindow", "Room", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
