#ifndef UPDATECHECKER_H
#define UPDATECHECKER_H

#include <QObject>
#include <QtNetwork>

class UpdateChecker : public QObject
{
    Q_OBJECT
public:
    explicit UpdateChecker(QObject *parent = 0);
    void checkForUpdate();
    QString remoteVersion();

signals:
    void newVersion(QString);

public slots:
    void requestFinished(QNetworkReply *reply);
private:

    bool m_needUpdate;
    QString m_remoteVersion;
    QNetworkAccessManager m_networkManager;

};

#endif // UPDATECHECKER_H
