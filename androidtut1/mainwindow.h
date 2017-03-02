#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setupPics();
    void endOfDay();

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int restMoney = 0;
    QMediaPlayer *moneysound;
    QMediaPlayer *alarmsound;
    //QMediaPlayer *music;
private slots:
    void decreaseAccount(int price);
    void increaseAccount(int salary);
    void playMusic();
    void setVolume(int volume);
};

#endif // MAINWINDOW_H
