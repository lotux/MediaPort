#ifndef PICTUREBROWSER_H
#define PICTUREBROWSER_H
#include <qevent.h>
#include "pictureflow.h"


class PictureBrowser : public PictureFlow
{
public:
    PictureBrowser();
    void keyPressEvent(QKeyEvent *event);
    QStringList getFiles(const QString& path = QString());
    void loadImages();

};

#endif // PICTUREBROWSER_H
