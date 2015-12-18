#include "logmanager.h"
#include <QDateTime>
#include <QDebug>
#include <QFileInfo>

const QString LogManager::LOG_GOMINA = "gomina.log";
const QString LogManager::LOG_GAME_ENGINE = "engine.log";
const QString LogManager::LOG_BRAIN = "brain.log";
const QString LogManager::LOG_NETWORK = "network.log";


LogManager::LogManager() {}

LogManager::~LogManager() {}

//la méthode init doit être executée avant de se servir du LogManager
bool LogManager::init(QString logLocation)
{
    //installation du handler de message personalisé
    qInstallMessageHandler(gominaMessageHandler);

    //on check si les fichiers de logs existent ou on les créé + ouverture en lecture
    gominaLogFile = new QFile(logLocation + "/" + LOG_GOMINA);
    if (!gominaLogFile->open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    //on ouvre un stream vers le fichier de log
    fluxGomina(&gominaLogFile);
    return true;
}

//libère toutes les ressources mobilisées par le LogManager
void LogManager::release()
{
    //fermer les handlers de fichier
    gominaLogFile->close();
}

//fonction qui écrit les messages
void LogManager::gominaMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // utilisation de mutex pour le thread safe ?! c'est trop lent ? alternative ?

    fluxGomina << "QtMsgType=" + QString::number(type) << msg;
    //fprintf(stdout, "un message de mon application à été pris en charge par mon handler custom.");
}

void LogManager::writeMessage(const QString &msg, LogType type = TypeGomina)
{
    switch (type)
        {
        case TypeGomina:
            qDebug() <<  QDateTime::currentDateTimeUtc().toString() + ": " + msg;
            break;

        case TypeEngine:
            break;

        case TypeBrain:
            break;

        case TypeNetwork:
            break;

        default:
            break;
        }
}


