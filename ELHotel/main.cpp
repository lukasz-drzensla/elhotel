#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QMessageBox>
#include <fstream>
#include <vector>

//engine system libraries
#include "header/Reservation.h"
#include "header/dateTime.h"
#include "header/globalConstants.h"
#include "header/dataBase.h"
#include "header/Room.h"

using std::ifstream, std::ofstream, std::string;

globalConstants::shared_variables globalConstants::sharedVariables {};

int global_init()
{
    ifstream config("config.txt");
    if (!config.is_open())
    {
        ofstream error("config.txt");
        error.close();
        return -1;
    }
    int n{};
    int err = 0;
    while (!config.eof())
    {
        string temp{};
        getline(config, temp);
        int t{};
        try
        {
            t = stoi(temp);
        }
        catch (const std::exception&)
        {
            err = 1;
        }
        switch (n) {
        case 0:
        {
            if (!err)
            {
                //globalConstants::roomRate = t;
                globalConstants::sharedVariables.roomRate = t;
            }
            else
            {
                //globalConstants::roomRate = 1;
                globalConstants::sharedVariables.roomRate = 1;
            }
            break;
        }
        case 1:
        {
            if (!err){
                //globalConstants::thisYear = t;
                globalConstants::sharedVariables.thisYear = t;
            }
            else
            {
                //globalConstants::thisYear = 2020;
                globalConstants::sharedVariables.thisYear = 2020;
            }
            break;
        }
        case 2:
        {
            if (!err)
            {
                //globalConstants::next_index = t;
                globalConstants::sharedVariables.next_index = t;
            }
            else
            {
                //globalConstants::next_index = 0;
                globalConstants::sharedVariables.next_index = 0;
            }
            break;
        }
        case 3:
        {
            if (!err)
            {
                //globalConstants::next_room_index = t;
                globalConstants::sharedVariables.next_room_index = t;
            }
            else
            {
                //globalConstants::next_room_index = 0;
                globalConstants::sharedVariables.next_room_index = 0;
            }
            break;
        }
        };
        ++n;
    }
    config.close();
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ELHotel_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    int init = global_init(); //read the config file with all the constants including price per day, etc

    if (init == -1)
    {
        QMessageBox msgBox;
        msgBox.setText("Error reading config file");
        msgBox.exec();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
