#include "webpage.h"
#include <QWebFrame>

WebPage::WebPage(QObject *parent)
{
  connect(this,SIGNAL(selectionChanged()),this,SLOT(doNothing()));
}
void WebPage::doNothing(){
    this->focusNextPrevChild(1);

}
