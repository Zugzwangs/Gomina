/*******************************************************/
// cette classe est l'entrée de tous les messages de log
//produits par l'application
/*******************************************************/

#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <qqueue.h>
#include <QTextStream>
#include <QFile>

class LogManager
{

public:
    static const QString LOG_GOMINA;
    static const QString LOG_GAME_ENGINE;
    static const QString LOG_BRAIN;
    static const QString LOG_NETWORK;
    enum LogType { TypeGomina = 0, TypeEngine = 1, TypeBrain = 2, TypeNetwork = 3 };

    LogManager();
    ~LogManager();

    static void release();
    static bool init(QString logLocation);
    static void gominaMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    static void writeMessage(const QString &msg, LogType type);

private:
    static QFile* gominaLogFile;
    static QTextStream fluxGomina;

};

#endif // LOGMANAGER_H
