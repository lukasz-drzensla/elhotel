/********************************************************************************
** Form generated from reading UI file 'addnewreservation.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWRESERVATION_H
#define UI_ADDNEWRESERVATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_addnewreservation
{
public:
    QLabel *label;
    QLabel *label_2;
    QDateEdit *arr_dateEdit;
    QDateEdit *dep_dateEdit;
    QTextEdit *name_txt;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinPrice;
    QPushButton *recalc_button;
    QLabel *label_6;
    QTextEdit *nip_txt;
    QLabel *label_7;
    QTextEdit *phone_txt;
    QPushButton *add_reservation_button;
    QPushButton *cancel_but;
    QLabel *roomLabel;

    void setupUi(QDialog *addnewreservation)
    {
        if (addnewreservation->objectName().isEmpty())
            addnewreservation->setObjectName("addnewreservation");
        addnewreservation->resize(326, 432);
        label = new QLabel(addnewreservation);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 70, 71, 16));
        label_2 = new QLabel(addnewreservation);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 120, 91, 16));
        arr_dateEdit = new QDateEdit(addnewreservation);
        arr_dateEdit->setObjectName("arr_dateEdit");
        arr_dateEdit->setGeometry(QRect(20, 90, 110, 25));
        arr_dateEdit->setDateTime(QDateTime(QDate(2021, 12, 31), QTime(18, 0, 0)));
        dep_dateEdit = new QDateEdit(addnewreservation);
        dep_dateEdit->setObjectName("dep_dateEdit");
        dep_dateEdit->setGeometry(QRect(20, 140, 110, 25));
        dep_dateEdit->setDateTime(QDateTime(QDate(2022, 1, 1), QTime(18, 0, 0)));
        name_txt = new QTextEdit(addnewreservation);
        name_txt->setObjectName("name_txt");
        name_txt->setGeometry(QRect(20, 30, 281, 31));
        label_3 = new QLabel(addnewreservation);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 10, 49, 16));
        label_4 = new QLabel(addnewreservation);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 170, 49, 16));
        label_5 = new QLabel(addnewreservation);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 220, 49, 16));
        spinPrice = new QSpinBox(addnewreservation);
        spinPrice->setObjectName("spinPrice");
        spinPrice->setGeometry(QRect(20, 240, 191, 25));
        spinPrice->setMaximum(2147483647);
        recalc_button = new QPushButton(addnewreservation);
        recalc_button->setObjectName("recalc_button");
        recalc_button->setGeometry(QRect(220, 240, 80, 24));
        label_6 = new QLabel(addnewreservation);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 330, 49, 16));
        nip_txt = new QTextEdit(addnewreservation);
        nip_txt->setObjectName("nip_txt");
        nip_txt->setGeometry(QRect(20, 350, 281, 31));
        nip_txt->setAcceptRichText(false);
        label_7 = new QLabel(addnewreservation);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 270, 91, 16));
        phone_txt = new QTextEdit(addnewreservation);
        phone_txt->setObjectName("phone_txt");
        phone_txt->setGeometry(QRect(20, 290, 281, 31));
        add_reservation_button = new QPushButton(addnewreservation);
        add_reservation_button->setObjectName("add_reservation_button");
        add_reservation_button->setGeometry(QRect(130, 400, 80, 24));
        cancel_but = new QPushButton(addnewreservation);
        cancel_but->setObjectName("cancel_but");
        cancel_but->setGeometry(QRect(220, 400, 80, 24));
        roomLabel = new QLabel(addnewreservation);
        roomLabel->setObjectName("roomLabel");
        roomLabel->setGeometry(QRect(20, 200, 49, 16));

        retranslateUi(addnewreservation);

        QMetaObject::connectSlotsByName(addnewreservation);
    } // setupUi

    void retranslateUi(QDialog *addnewreservation)
    {
        addnewreservation->setWindowTitle(QCoreApplication::translate("addnewreservation", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addnewreservation", "Arrival date:", nullptr));
        label_2->setText(QCoreApplication::translate("addnewreservation", "Departure date:", nullptr));
        name_txt->setPlaceholderText(QCoreApplication::translate("addnewreservation", "Name Surname", nullptr));
        label_3->setText(QCoreApplication::translate("addnewreservation", "Name:", nullptr));
        label_4->setText(QCoreApplication::translate("addnewreservation", "Room:", nullptr));
        label_5->setText(QCoreApplication::translate("addnewreservation", "Price:", nullptr));
        recalc_button->setText(QCoreApplication::translate("addnewreservation", "Recalculate", nullptr));
        label_6->setText(QCoreApplication::translate("addnewreservation", "NIP:", nullptr));
        nip_txt->setPlaceholderText(QCoreApplication::translate("addnewreservation", "0", nullptr));
        label_7->setText(QCoreApplication::translate("addnewreservation", "Phone number:", nullptr));
        phone_txt->setPlaceholderText(QCoreApplication::translate("addnewreservation", "123-456-789", nullptr));
        add_reservation_button->setText(QCoreApplication::translate("addnewreservation", "Add", nullptr));
        cancel_but->setText(QCoreApplication::translate("addnewreservation", "Cancel", nullptr));
        roomLabel->setText(QCoreApplication::translate("addnewreservation", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addnewreservation: public Ui_addnewreservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWRESERVATION_H
