#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0);
    QSettings settings;
    void loadSettings();
    void saveSettings();
    void saveKeyValue();
    void saveVolume(int value);
    int getVolume();

signals:

public slots:

};

#endif // SETTINGS_H
