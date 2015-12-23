#include "logmanager.h"
#include <QDateTime>
#include <QDebug>
#include <QFileInfo>

Q_LOGGING_CATEGORY(general, "general")
Q_LOGGING_CATEGORY(engine, "engine")
Q_LOGGING_CATEGORY(network, "network")

const QString LogManager::LOG_GOMINA = "gomina.log";
const QString LogManager::LOG_GAME_ENGINE = "engine.log";
const QString LogManager::LOG_NETWORK = "network.log";
const QString LogManager::LOG_BRAIN = "brain.log";

QFile* LogManager::gominaLogFile = 0;
QFile* LogManager::gameEngineLogFile = 0;
QFile* LogManager::networkLogFile = 0;

QTextStream* LogManager::fluxGomina = 0;
QTextStream* LogManager::fluxGameEngine = 0;
QTextStream* LogManager::fluxNetwork = 0;

LogManager::LogManager() {}

LogManager::~LogManager() {}

//la méthode init doit être executée avant de se servir du LogManager
bool LogManager::init(QString logLocation)
{
    //on check si les fichiers de logs existent ou on les créé + ouverture en lecture
    gominaLogFile = new QFile(logLocation + "/" + LOG_GOMINA);
    if ( !gominaLogFile->open(QIODevice::Append | QIODevice::Unbuffered) )
        return false;

    gameEngineLogFile = new QFile(logLocation + "/" + LOG_GAME_ENGINE);
    if ( !gameEngineLogFile->open(QIODevice::Append | QIODevice::Unbuffered) )
        return false;

    networkLogFile = new QFile(logLocation + "/" + LOG_NETWORK);
    if ( !networkLogFile->open(QIODevice::Append | QIODevice::Unbuffered) )
        return false;

    //on ouvre un stream vers le fichier de log
    fluxGomina = new QTextStream(gominaLogFile);
    fluxGameEngine = new QTextStream(gameEngineLogFile);
    fluxNetwork = new QTextStream(networkLogFile);

    qDebug() << "redirection of logs to files from this point.";

    //formatage utilisé pour les lignes de log:
    qSetMessagePattern("%{time yyyy/MM/dd h:mm:ss.zzz t} - %{type}: %{message}");

    //installation du handler de message personalisé
    qInstallMessageHandler(gominaMessageHandler);

    //on trace le lancement de l'application
    QString beginMsg( "*********************************************\n" );
    beginMsg.append(QDateTime::currentDateTimeUtc().toString());
    beginMsg.append(": starting Gomina.");

    (*fluxGomina) << beginMsg << endl;
    fluxGomina->flush();

    (*fluxGameEngine) << beginMsg << endl;
    fluxGameEngine->flush();

    (*fluxNetwork) << beginMsg << endl;
    fluxNetwork->flush();

    return true;
}

//libère toutes les ressources mobilisées par le LogManager
void LogManager::release()
{
    //tracer la fermeture de l'application
    QString EndingMsg("gomina is closed");
    qDebug() << EndingMsg;

    //fermer les handlers de fichier et detruire les allocations dynamiques
    gominaLogFile->close();
    delete fluxGomina;
    delete gominaLogFile;

    gameEngineLogFile->close();
    delete fluxGameEngine;
    delete gameEngineLogFile;
}

//fonction qui écrit les messages
void LogManager::gominaMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    //utilisation de mutex pour le thread safe ?! c'est trop lent ? alternative ?
    if ( context.category == engine().categoryName() )
        {
        (*fluxGameEngine) << qFormatLogMessage(type, context, msg) << endl;
        fluxGameEngine->flush();
        }
    else
        {
        (*fluxGomina) << qFormatLogMessage(type, context, msg) << endl;
        fluxGomina->flush();
        }
}


