#ifndef WMPLAYER_H
#define WMPLAYER_H

#include <QObject>
class QAxWidget;

class WMPlayer : public QObject
{
    Q_OBJECT
public:
    explicit WMPlayer(QObject *parent = 0);

    enum PlayStateConstants { Stopped = 0, Paused = 1, Playing = 2 };
    enum ReadyStateConstants { Uninitialized = 0, Loading = 1,
                                 Interactive = 3, Complete = 4 };
protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void onPlayStateChange(int oldState, int newState);
    void onReadyStateChange(ReadyStateConstants readyState);
    void onPositionChange(double oldPos, double newPos);
    void sliderValueChanged(int newValue);

private:
    QAxWidget *wmp;
    int updateTimer;

signals:

public slots:

};

#endif // WMPLAYER_H
