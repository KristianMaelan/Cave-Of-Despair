#ifndef LOGGER_H
#define LOGGER_H

#include <string>

/* This thing is just a utility class to get messages into a program widget
   instead of having to cout or qDebug() to a console.

   It does not have anything to do with the OpenGL code

   It is used by getting an instance of the class and calling the logText() function
*/

///Colors for the Logger class
enum class LogType
{
    LOG = 0,
    HIGHLIGHT,
    WARNING,
    REALERROR       //For some reason "ERROR" is taken, even within this enum class...
};

///Basic logging functionality to the widget in the MainWindow.
/// This class is a singleton, so you get it by calling getInstance();
class Logger
{
public:
    ///Getting the instance of this class. This class is a singleton.
    static Logger* getInstance();

    ///Setting the pointer to MainWindow, so the logger knows where to print
    void setMainWindow(class MainWindow *mainWindowIn);

    ///Printing the given string to the log window. Optional logtype (sets color) as second parameter
    void logText(std::string input, LogType colorIn = LogType::LOG);

private:
    //Protecting the constructors since this class is a singleton
    Logger();
    void operator=(Logger&){};  //Assignment operator
    Logger(const Logger&){};    //Copy constructor

    class MainWindow* mMainWindow{nullptr};
};

#endif // LOGGER_H
