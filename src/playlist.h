#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QtNetwork>
#include <QtScript>

class PlayList : public QObject
{
    Q_OBJECT
public:
    explicit PlayList(QObject *parent = 0);
    QNetworkAccessManager networkManager;
    QString getPlayList();
signals:
    void playListReady();

private:

    QList<QStringList> playListData;
    QString mediaJson;
    QScriptEngine jsEngine;

private slots:
    void handleHttpData(QNetworkReply *networkReply);
public slots:
    void updatePlayList(QString query);
};

#endif // PLAYLIST_H
