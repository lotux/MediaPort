#include <QtCore/QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QTextStream>
int main(int argc, char **argv)
{
    QFile file;
    file.setFileName("vlc.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
         qDebug()<< "Failed to open file";
    qDebug() << argc;
    QTextStream txt(&file);
    for(int i=0;i<argc;i++){
        txt << argv[i] << " ";
    }
    txt << "vlc";
    file.close();
    return 1;
}
