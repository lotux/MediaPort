#include "settings.h"
#include <QWebSettings>
#include <QCoreApplication>



Settings::Settings(QObject *parent) :
    QObject(parent)
{
    loadSettings();
}

void Settings::loadSettings()
{
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalStorageDatabaseEnabled, true);
    QWebSettings::globalSettings()->setOfflineWebApplicationCachePath(  QCoreApplication::applicationDirPath() + QString("/webappCache/") );
    QWebSettings::globalSettings()->setLocalStoragePath( QCoreApplication::applicationDirPath() + QString("/localStore/"));
    QWebSettings::globalSettings()->setOfflineStoragePath(QCoreApplication::applicationDirPath() + QString("/dbcache/"));

};

void Settings::saveSettings()
{
};

void Settings::saveKeyValue()
{
};

int Settings::getVolume()
{
    return settings.value("Volume",50).toInt();
};

void Settings::saveVolume(int value)
{
    settings.setValue("volume",value);
};
