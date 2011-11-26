#include "playlist.h"
#include "constants.h"

PlayList::PlayList(QObject *parent) :
    QObject(parent)
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)),
               this, SLOT(handleHttpData(QNetworkReply*)));
}
void PlayList::handleHttpData(QNetworkReply *reply)
{
    playListData.empty();
    mediaJson.clear();
    //QUrl url = reply->url();
    if (!reply->error())
    {
       QTextStream stream(reply->readAll());

       QStringList lineStringList;
       while(!stream.atEnd())
       {
        QString lineData = stream.readLine();
        mediaJson += lineData;
        lineStringList = lineData.trimmed().split(',');
        playListData.append(lineStringList);
       }
       emit playListReady();
    }
    else{
    }
}

QString PlayList::getPlayList()
{
    QList<QStringList> returnData = playListData;
    return mediaJson;
}
void PlayList::updatePlayList(QString m_query)
{
    QUrl m_playListUrl = QUrl ( QString(Constants::PLAYLIST_PATH)
                                        + "query="+ m_query);
    networkManager.get(QNetworkRequest(m_playListUrl));
}
