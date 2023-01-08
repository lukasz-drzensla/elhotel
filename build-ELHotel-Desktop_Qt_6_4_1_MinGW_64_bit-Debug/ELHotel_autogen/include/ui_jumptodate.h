/********************************************************************************
** Form generated from reading UI file 'jumptodate.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUMPTODATE_H
#define UI_JUMPTODATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_jumptodate
{
public:
    QPushButton *Jump;
    QDateEdit *dateEdit;

    void setupUi(QDialog *jumptodate)
    {
        if (jumptodate->objectName().isEmpty())
            jumptodate->setObjectName("jumptodate");
        jumptodate->resize(137, 71);
        Jump = new QPushButton(jumptodate);
        Jump->setObjectName("Jump");
        Jump->setGeometry(QRect(40, 40, 80, 24));
        dateEdit = new QDateEdit(jumptodate);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(10, 10, 110, 25));
        dateEdit->setDateTime(QDateTime(QDate(2022, 1, 1), QTime(0, 0, 0)));

        retranslateUi(jumptodate);

        QMetaObject::connectSlotsByName(jumptodate);
    } // setupUi

    void retranslateUi(QDialog *jumptodate)
    {
        jumptodate->setWindowTitle(QCoreApplication::translate("jumptodate", "Jump to a date", nullptr));
        Jump->setText(QCoreApplication::translate("jumptodate", "Jump", nullptr));
    } // retranslateUi

};

namespace Ui {
    class jumptodate: public Ui_jumptodate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUMPTODATE_H
