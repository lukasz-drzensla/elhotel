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
#include <QtWidgets/QComboBox>
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
    QTextEdit *textEdit;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QLabel *label_6;
    QTextEdit *textEdit_2;
    QLabel *label_7;
    QTextEdit *textEdit_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

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
        arr_dateEdit->setDateTime(QDateTime(QDate(2022, 1, 1), QTime(0, 0, 0)));
        dep_dateEdit = new QDateEdit(addnewreservation);
        dep_dateEdit->setObjectName("dep_dateEdit");
        dep_dateEdit->setGeometry(QRect(20, 140, 110, 25));
        dep_dateEdit->setDateTime(QDateTime(QDate(2022, 1, 2), QTime(0, 0, 0)));
        textEdit = new QTextEdit(addnewreservation);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 30, 281, 31));
        label_3 = new QLabel(addnewreservation);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 10, 49, 16));
        label_4 = new QLabel(addnewreservation);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 170, 49, 16));
        comboBox = new QComboBox(addnewreservation);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 190, 281, 24));
        label_5 = new QLabel(addnewreservation);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 220, 49, 16));
        spinBox = new QSpinBox(addnewreservation);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(20, 240, 191, 25));
        pushButton = new QPushButton(addnewreservation);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 240, 80, 24));
        label_6 = new QLabel(addnewreservation);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 330, 49, 16));
        textEdit_2 = new QTextEdit(addnewreservation);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(20, 350, 281, 31));
        label_7 = new QLabel(addnewreservation);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 270, 91, 16));
        textEdit_3 = new QTextEdit(addnewreservation);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(20, 290, 281, 31));
        pushButton_2 = new QPushButton(addnewreservation);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(130, 400, 80, 24));
        pushButton_3 = new QPushButton(addnewreservation);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(220, 400, 80, 24));

        retranslateUi(addnewreservation);

        QMetaObject::connectSlotsByName(addnewreservation);
    } // setupUi

    void retranslateUi(QDialog *addnewreservation)
    {
        addnewreservation->setWindowTitle(QCoreApplication::translate("addnewreservation", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addnewreservation", "Arrival date:", nullptr));
        label_2->setText(QCoreApplication::translate("addnewreservation", "Departure date:", nullptr));
        label_3->setText(QCoreApplication::translate("addnewreservation", "Name:", nullptr));
        label_4->setText(QCoreApplication::translate("addnewreservation", "Room:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("addnewreservation", "Room 1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("addnewreservation", "Room 2", nullptr));

        label_5->setText(QCoreApplication::translate("addnewreservation", "Price:", nullptr));
        pushButton->setText(QCoreApplication::translate("addnewreservation", "Recalculate", nullptr));
        label_6->setText(QCoreApplication::translate("addnewreservation", "NIP:", nullptr));
        label_7->setText(QCoreApplication::translate("addnewreservation", "Phone number:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("addnewreservation", "Add", nullptr));
        pushButton_3->setText(QCoreApplication::translate("addnewreservation", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addnewreservation: public Ui_addnewreservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWRESERVATION_H
