/*******************************************************/
// cette classe est l'entrée de tous les messages de log
// produits par l'application
/*******************************************************/

#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <QFile>
#include <QTextStream>
#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(general)
Q_DECLARE_LOGGING_CATEGORY(engine)
Q_DECLARE_LOGGING_CATEGORY(network)

class LogManager
{

public:
    static const QString LOG_GOMINA;
    static const QString LOG_GAME_ENGINE;
    static const QString LOG_NETWORK;
    static const QString LOG_BRAIN;
    enum LogType { TypeGomina = 0, TypeEngine = 1, TypeBrain = 2, TypeNetwork = 3 };

    LogManager();
    ~LogManager();

    static bool init(QString logLocation);
    static void release();
    static void gominaMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private:
    static QFile* gominaLogFile;
    static QFile* gameEngineLogFile;
    static QFile* networkLogFile;
    static QTextStream* fluxGomina;
    static QTextStream* fluxGameEngine;
    static QTextStream* fluxNetwork;
};

#endif // LOGMANAGER_H
