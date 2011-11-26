#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include <QObject>
#include "vlc_on_qt.h"
class PlayerFactory : public QObject
{
    Q_OBJECT
public:
    explicit PlayerFactory(QObject *parent = 0);
    VLCPlayer vlcplayer;
    WMPlayer  wmplayer;

signals:

public slots:

};

#endif // PLAYERFACTORY_H
