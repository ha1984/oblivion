#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H
#include <QLCDNumber>
#include <QTime>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = 0);
    QTime time;
private slots:
    void showTime();
};

#endif // DIGITALCLOCK_H
