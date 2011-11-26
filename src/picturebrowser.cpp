#include "picturebrowser.h"
#include "qdir.h"
#include <QTime>
#include <QApplication>
PictureBrowser::PictureBrowser() : PictureFlow()
{

#if defined(_WS_QWS) || defined(Q_WS_QWS)
  showFullScreen();
  int ww = width();
  int wh = height();
  int dim = (ww > wh) ? wh : ww;
  dim = dim * 3 / 4;
  //setSlideSize(QSize(3*dim/5, dim));
  setSlideSize(QSize(350, 350));
#else
  //setSlideSize(QSize(3*40, 5*40));
  //resize(750, 270);
  setSlideSize(QSize(250, 150));

#endif
  loadImages();
}
void PictureBrowser::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape || event->key() == Qt::Key_Enter ||
      event->key() == Qt::Key_Return)
      {
        event->accept();
        close();
      }

    // checking the speed of rendering
    if(event->key() == Qt::Key_F10)
    if(event->modifiers() == Qt::AltModifier)
    {
      qDebug("benchmarking.... please wait");
      const int blit_count = 10;

      QTime stopwatch;
      stopwatch.start();
      for(int i = 0; i < blit_count; i++)
      {
        render(); repaint(); QApplication::flush(); QApplication::syncX();
        render(); repaint(); QApplication::flush(); QApplication::syncX();
        render(); repaint(); QApplication::flush(); QApplication::syncX();
        render(); repaint(); QApplication::flush(); QApplication::syncX();
        render(); repaint(); QApplication::flush(); QApplication::syncX();
        render(); repaint(); QApplication::flush(); QApplication::syncX();
        render(); repaint(); QApplication::flush(); QApplication::syncX();
        render(); repaint(); QApplication::flush(); QApplication::syncX();
        render(); repaint(); QApplication::flush(); QApplication::syncX();
        render(); repaint(); QApplication::flush(); QApplication::syncX();
      }
      QString msg;
      int elapsed = stopwatch.elapsed();
      if( elapsed > 0 )
        msg = QString("FPS: %1").arg( blit_count*10*1000.0/elapsed );
      else
        msg = QString("Too fast. Increase blit_count");
      setWindowTitle( msg );
      event->accept();
      return;
    }

    // for debugging only: Alt+F11 cycles the reflection effect
    if(event->key() == Qt::Key_F11)
    if(event->modifiers() == Qt::AltModifier)
    {
      qDebug("changing reflection effect...");
      switch(reflectionEffect())
      {
        //case NoReflection:      setReflectionEffect(PlainReflection); break;
        case PlainReflection:   setReflectionEffect(BlurredReflection); break;
        case BlurredReflection: setReflectionEffect(PlainReflection); break;
        default:                setReflectionEffect(PlainReflection); break;
      }
      event->accept();
      return;
    }

    PictureFlow::keyPressEvent(event);
}

QStringList PictureBrowser::getFiles(const QString& path)
{
    QStringList files;

    QDir dir = QDir::current();
    if(!path.isEmpty())
      dir = QDir(path);

    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
  #if QT_VERSION >= 0x040000
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i)
    {
      QFileInfo fileInfo = list.at(i);
      files.append(dir.absoluteFilePath(fileInfo.fileName()));
    }
  #else
    const QFileInfoList* list = dir.entryInfoList();
    if(list)
    {
      QFileInfoListIterator it( *list );
      QFileInfo * fi;
      while( (fi=it.current()) != 0 )
      {
        ++it;
        files.append(dir.absFilePath(fi->fileName()));
      }
    }
  #endif

    return files;
}

void PictureBrowser::loadImages()
{
    QStringList files = getFiles();
    QImage img;
    for(int i = 0; i < (int)files.count(); i++)
      if(img.load(files[i]))
        addSlide(img);

    setCenterIndex(slideCount()/2);
    setBackgroundColor(Qt::black);
    show();
}
