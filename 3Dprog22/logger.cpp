#include "logger.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPlainTextEdit>
#include <string>

/* This thing is just a utility class to get messages into a program widget
   instead of having to cout or qDebug() to a console.

   It does not have anything to do with the OpenGL code

   It is used by getting an instance of the class and calling the logText() function
*/

Logger::Logger()
{}

Logger *Logger::getInstance()
{
    static Logger *mInstance = new Logger();
    return mInstance;
}

void Logger::setMainWindow(MainWindow *mainWindowIn)
{
    mMainWindow = mainWindowIn;
}

void Logger::logText(std::string input, LogType colorIn)
{
    QColor textColor;

    //Setting the color of the text to be printed
    switch (colorIn) {
    case LogType::LOG :
        textColor = Qt::white;
        break;
    case LogType::HIGHLIGHT :
        textColor = Qt::darkGreen;
        break;
    case LogType::WARNING :
        textColor = Qt::yellow;
        break;
    case LogType::REALERROR :
        textColor = Qt::red;
        break;
    default:
        textColor = Qt::darkGray;
    }

    //Doing the requirements for printing the text to the Output widget
    QTextCharFormat textformat;
    textformat = mMainWindow->ui->outputLog->currentCharFormat();
    textformat.setForeground(QBrush((textColor)));
    mMainWindow->ui->outputLog->setCurrentCharFormat(textformat);
    mMainWindow->ui->outputLog->appendPlainText(input.c_str());
}
