/********************************************************************************
** Form generated from reading UI file 'addnewroom.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWROOM_H
#define UI_ADDNEWROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_addnewroom
{
public:
    QPushButton *Add;
    QPushButton *cancelBut;
    QLabel *label;
    QLabel *ID_label;
    QLabel *label_2;
    QTextEdit *room_des;
    QLabel *label_3;
    QSpinBox *spin_people;
    QLabel *label_4;
    QSpinBox *spin_cost;

    void setupUi(QDialog *addnewroom)
    {
        if (addnewroom->objectName().isEmpty())
            addnewroom->setObjectName("addnewroom");
        addnewroom->resize(320, 240);
        Add = new QPushButton(addnewroom);
        Add->setObjectName("Add");
        Add->setGeometry(QRect(140, 210, 80, 24));
        cancelBut = new QPushButton(addnewroom);
        cancelBut->setObjectName("cancelBut");
        cancelBut->setGeometry(QRect(230, 210, 80, 24));
        label = new QLabel(addnewroom);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 49, 16));
        ID_label = new QLabel(addnewroom);
        ID_label->setObjectName("ID_label");
        ID_label->setGeometry(QRect(30, 10, 49, 16));
        label_2 = new QLabel(addnewroom);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 30, 101, 16));
        room_des = new QTextEdit(addnewroom);
        room_des->setObjectName("room_des");
        room_des->setGeometry(QRect(10, 50, 231, 31));
        label_3 = new QLabel(addnewroom);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 71, 16));
        spin_people = new QSpinBox(addnewroom);
        spin_people->setObjectName("spin_people");
        spin_people->setGeometry(QRect(10, 110, 42, 25));
        label_4 = new QLabel(addnewroom);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 140, 141, 16));
        spin_cost = new QSpinBox(addnewroom);
        spin_cost->setObjectName("spin_cost");
        spin_cost->setGeometry(QRect(10, 160, 131, 25));
        spin_cost->setMaximum(2147483647);

        retranslateUi(addnewroom);

        QMetaObject::connectSlotsByName(addnewroom);
    } // setupUi

    void retranslateUi(QDialog *addnewroom)
    {
        addnewroom->setWindowTitle(QCoreApplication::translate("addnewroom", "Add new room", nullptr));
        Add->setText(QCoreApplication::translate("addnewroom", "Add", nullptr));
        cancelBut->setText(QCoreApplication::translate("addnewroom", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("addnewroom", "ID:", nullptr));
        ID_label->setText(QCoreApplication::translate("addnewroom", "0", nullptr));
        label_2->setText(QCoreApplication::translate("addnewroom", "Room description:", nullptr));
        label_3->setText(QCoreApplication::translate("addnewroom", "Max people:", nullptr));
        label_4->setText(QCoreApplication::translate("addnewroom", "Cost rate (price per night):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addnewroom: public Ui_addnewroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWROOM_H
