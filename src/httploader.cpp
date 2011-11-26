#include "httploader.h"

HttpLoader::HttpLoader(QObject *parent) :
    QObject(parent)
{
    http = new QHttp(this);
    connect(http, SIGNAL(requestFinished(int, bool)),
            this, SLOT(Finished(int,bool)));
    buffer = new QBuffer(&bytes);
    buffer->open(QIODevice::WriteOnly);

}

QImage HttpLoader::getImage(QUrl url)
{
    http->setHost(url.host());
    Request = http->get (url.path(),buffer);
    return img;
}
void HttpLoader::Finished(int requestId, bool error)
{
    if (Request == requestId){
    img.loadFromData(bytes);
    }
}

