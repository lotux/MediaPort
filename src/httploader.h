#ifndef HTTPLOADER_H
#define HTTPLOADER_H

#include <QObject>
#include <QBuffer>
#include <QHttp>
#include <QImage>
#include <QUrl>

class HttpLoader : public QObject
{
    Q_OBJECT
public:
    explicit HttpLoader(QObject *parent = 0);
    QImage getImage(QUrl url);

signals:
private:
    QBuffer *buffer;
    QByteArray bytes;
    QHttp *http;
    int Request;
    QImage img;

public slots:
    void Finished(int requestId, bool error);
};

#endif // HTTPLOADER_H
