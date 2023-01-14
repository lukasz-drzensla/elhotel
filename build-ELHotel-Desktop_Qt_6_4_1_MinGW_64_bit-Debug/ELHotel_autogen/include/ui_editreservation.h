/********************************************************************************
** Form generated from reading UI file 'editreservation.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITRESERVATION_H
#define UI_EDITRESERVATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_editreservation
{
public:
    QLabel *label_11;
    QLabel *label_10;
    QTextEdit *nip_txt;
    QTextEdit *name_txt;
    QLabel *label_4;
    QLabel *max_people_label;
    QDateEdit *dep_dateEdit;
    QTextEdit *comment_txt;
    QSpinBox *spinPeople;
    QLabel *label_5;
    QPushButton *recalc_button;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *roomLabel;
    QLabel *label_12;
    QLabel *label;
    QLabel *label_9;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *cancel_but;
    QLabel *label_8;
    QSpinBox *spinPaid;
    QPushButton *add_reservation_button;
    QSpinBox *spinPrice;
    QTextEdit *phone_txt;
    QLabel *left_txt;
    QDateEdit *arr_dateEdit;

    void setupUi(QDialog *editreservation)
    {
        if (editreservation->objectName().isEmpty())
            editreservation->setObjectName("editreservation");
        editreservation->resize(306, 628);
        label_11 = new QLabel(editreservation);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 260, 49, 16));
        label_10 = new QLabel(editreservation);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(60, 450, 31, 16));
        nip_txt = new QTextEdit(editreservation);
        nip_txt->setObjectName("nip_txt");
        nip_txt->setGeometry(QRect(10, 390, 281, 31));
        nip_txt->setAcceptRichText(false);
        name_txt = new QTextEdit(editreservation);
        name_txt->setObjectName("name_txt");
        name_txt->setGeometry(QRect(10, 20, 281, 31));
        label_4 = new QLabel(editreservation);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 160, 49, 16));
        max_people_label = new QLabel(editreservation);
        max_people_label->setObjectName("max_people_label");
        max_people_label->setGeometry(QRect(90, 450, 49, 16));
        dep_dateEdit = new QDateEdit(editreservation);
        dep_dateEdit->setObjectName("dep_dateEdit");
        dep_dateEdit->setGeometry(QRect(10, 130, 110, 25));
        dep_dateEdit->setDateTime(QDateTime(QDate(2022, 1, 1), QTime(10, 0, 0)));
        comment_txt = new QTextEdit(editreservation);
        comment_txt->setObjectName("comment_txt");
        comment_txt->setGeometry(QRect(10, 500, 281, 81));
        spinPeople = new QSpinBox(editreservation);
        spinPeople->setObjectName("spinPeople");
        spinPeople->setGeometry(QRect(10, 450, 42, 25));
        label_5 = new QLabel(editreservation);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 210, 49, 16));
        recalc_button = new QPushButton(editreservation);
        recalc_button->setObjectName("recalc_button");
        recalc_button->setGeometry(QRect(210, 230, 80, 24));
        label_6 = new QLabel(editreservation);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 370, 49, 16));
        label_7 = new QLabel(editreservation);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 310, 91, 16));
        roomLabel = new QLabel(editreservation);
        roomLabel->setObjectName("roomLabel");
        roomLabel->setGeometry(QRect(10, 190, 49, 16));
        label_12 = new QLabel(editreservation);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(130, 280, 81, 16));
        label = new QLabel(editreservation);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 71, 16));
        label_9 = new QLabel(editreservation);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 480, 131, 16));
        label_3 = new QLabel(editreservation);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 0, 49, 16));
        label_2 = new QLabel(editreservation);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 110, 91, 16));
        cancel_but = new QPushButton(editreservation);
        cancel_but->setObjectName("cancel_but");
        cancel_but->setGeometry(QRect(210, 590, 80, 24));
        label_8 = new QLabel(editreservation);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 430, 49, 16));
        spinPaid = new QSpinBox(editreservation);
        spinPaid->setObjectName("spinPaid");
        spinPaid->setGeometry(QRect(10, 280, 111, 25));
        spinPaid->setMaximum(2147483647);
        add_reservation_button = new QPushButton(editreservation);
        add_reservation_button->setObjectName("add_reservation_button");
        add_reservation_button->setGeometry(QRect(120, 590, 80, 24));
        spinPrice = new QSpinBox(editreservation);
        spinPrice->setObjectName("spinPrice");
        spinPrice->setGeometry(QRect(10, 230, 191, 25));
        spinPrice->setMaximum(2147483647);
        phone_txt = new QTextEdit(editreservation);
        phone_txt->setObjectName("phone_txt");
        phone_txt->setGeometry(QRect(10, 330, 281, 31));
        left_txt = new QLabel(editreservation);
        left_txt->setObjectName("left_txt");
        left_txt->setGeometry(QRect(220, 280, 49, 16));
        arr_dateEdit = new QDateEdit(editreservation);
        arr_dateEdit->setObjectName("arr_dateEdit");
        arr_dateEdit->setGeometry(QRect(10, 80, 110, 25));
        arr_dateEdit->setDateTime(QDateTime(QDate(2021, 12, 31), QTime(10, 0, 0)));

        retranslateUi(editreservation);

        QMetaObject::connectSlotsByName(editreservation);
    } // setupUi

    void retranslateUi(QDialog *editreservation)
    {
        editreservation->setWindowTitle(QCoreApplication::translate("editreservation", "Edit reservation", nullptr));
        label_11->setText(QCoreApplication::translate("editreservation", "Paid:", nullptr));
        label_10->setText(QCoreApplication::translate("editreservation", "Max:", nullptr));
        nip_txt->setPlaceholderText(QCoreApplication::translate("editreservation", "0", nullptr));
        name_txt->setPlaceholderText(QCoreApplication::translate("editreservation", "Name Surname", nullptr));
        label_4->setText(QCoreApplication::translate("editreservation", "Room:", nullptr));
        max_people_label->setText(QCoreApplication::translate("editreservation", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("editreservation", "Price:", nullptr));
        recalc_button->setText(QCoreApplication::translate("editreservation", "Recalculate", nullptr));
        label_6->setText(QCoreApplication::translate("editreservation", "NIP:", nullptr));
        label_7->setText(QCoreApplication::translate("editreservation", "Phone number:", nullptr));
        roomLabel->setText(QCoreApplication::translate("editreservation", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("editreservation", "Left to be paid:", nullptr));
        label->setText(QCoreApplication::translate("editreservation", "Arrival date:", nullptr));
        label_9->setText(QCoreApplication::translate("editreservation", "Comments:", nullptr));
        label_3->setText(QCoreApplication::translate("editreservation", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("editreservation", "Departure date:", nullptr));
        cancel_but->setText(QCoreApplication::translate("editreservation", "Cancel", nullptr));
        label_8->setText(QCoreApplication::translate("editreservation", "People:", nullptr));
        add_reservation_button->setText(QCoreApplication::translate("editreservation", "Edit", nullptr));
        phone_txt->setPlaceholderText(QCoreApplication::translate("editreservation", "123-456-789", nullptr));
        left_txt->setText(QCoreApplication::translate("editreservation", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editreservation: public Ui_editreservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITRESERVATION_H
