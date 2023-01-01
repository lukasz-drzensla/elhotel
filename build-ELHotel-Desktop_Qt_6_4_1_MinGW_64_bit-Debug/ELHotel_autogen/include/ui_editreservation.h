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
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_editreservation
{
public:

    void setupUi(QDialog *editreservation)
    {
        if (editreservation->objectName().isEmpty())
            editreservation->setObjectName("editreservation");
        editreservation->resize(640, 480);

        retranslateUi(editreservation);

        QMetaObject::connectSlotsByName(editreservation);
    } // setupUi

    void retranslateUi(QDialog *editreservation)
    {
        editreservation->setWindowTitle(QCoreApplication::translate("editreservation", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editreservation: public Ui_editreservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITRESERVATION_H
