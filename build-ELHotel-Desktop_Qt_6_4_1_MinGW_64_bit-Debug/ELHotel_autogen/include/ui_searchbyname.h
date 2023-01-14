/********************************************************************************
** Form generated from reading UI file 'searchbyname.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBYNAME_H
#define UI_SEARCHBYNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_searchByName
{
public:
    QTextEdit *textEdit;
    QPushButton *searchbtn;
    QLabel *var_txt;
    QLabel *label_2;
    QTextBrowser *result_txt;

    void setupUi(QDialog *searchByName)
    {
        if (searchByName->objectName().isEmpty())
            searchByName->setObjectName("searchByName");
        searchByName->resize(534, 582);
        textEdit = new QTextEdit(searchByName);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 30, 411, 31));
        searchbtn = new QPushButton(searchByName);
        searchbtn->setObjectName("searchbtn");
        searchbtn->setGeometry(QRect(440, 30, 80, 24));
        var_txt = new QLabel(searchByName);
        var_txt->setObjectName("var_txt");
        var_txt->setGeometry(QRect(20, 10, 49, 16));
        label_2 = new QLabel(searchByName);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 151, 16));
        result_txt = new QTextBrowser(searchByName);
        result_txt->setObjectName("result_txt");
        result_txt->setGeometry(QRect(20, 100, 501, 471));

        retranslateUi(searchByName);

        QMetaObject::connectSlotsByName(searchByName);
    } // setupUi

    void retranslateUi(QDialog *searchByName)
    {
        searchByName->setWindowTitle(QCoreApplication::translate("searchByName", "Search", nullptr));
        searchbtn->setText(QCoreApplication::translate("searchByName", "Search", nullptr));
        var_txt->setText(QCoreApplication::translate("searchByName", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("searchByName", "Found reservatons:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchByName: public Ui_searchByName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBYNAME_H
