#include "mainwindow.h"
#include <QApplication>

MainWindow * meWindow;
QMediaPlayer * music;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sax.mp3"));

    meWindow = new MainWindow();
    meWindow->show();

    return a.exec();
}
