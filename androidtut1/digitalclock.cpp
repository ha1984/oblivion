#include "digitalclock.h"
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <mainwindow.h>

extern MainWindow * meWindow;

DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent)
{
 setSegmentStyle(Filled);

 time.setHMS(0,0,0);

 // connect timer with timeEdit widget:
 QTimer * timer = new QTimer(this);
 connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
 // change time every 50ms
 timer->start(20);

 showTime();
}

void DigitalClock::showTime()
{
    time = time.addSecs(60);
    QString text = time.toString("hh:mm");
//    if ((time.second() % 2) == 0)
//        text[2] = ' ';
    display(text);

    if ((time.hour() == 23)&&(time.minute() == 59))
    {
      meWindow->endOfDay();
    }

}
