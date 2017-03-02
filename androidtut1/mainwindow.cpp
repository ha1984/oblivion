#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QSignalMapper>
#include <QTimer>
#include <digitalclock.h>
#include <QDebug>

extern QMediaPlayer * music;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->dial->setValue(99);



    setupPics();

    QSignalMapper* signalMapper = new QSignalMapper (this) ;
    connect (ui->buyJacket, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    connect (ui->buyShoes, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    connect (ui->buyTrousers, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    connect (ui->buyCar, SIGNAL(clicked()), signalMapper, SLOT(map())) ;


    signalMapper -> setMapping (ui->buyJacket, 200) ;
    signalMapper -> setMapping (ui->buyShoes, 50) ;
    signalMapper -> setMapping (ui->buyTrousers, 100) ;
    signalMapper -> setMapping (ui->buyCar, 900) ;

    // Connect button signal to appropriate slot:
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(decreaseAccount(int)));

    // music button:
    connect(ui->musicButton, SIGNAL(clicked()), this, SLOT(playMusic()));


    //volume:
    connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(setVolume(int)));


}

void MainWindow::setupPics()
{
    QPixmap pixJacket(":/images/jacke.png");

    QPixmap ScaledPixJacket = pixJacket.scaled(QSize(150,150),  Qt::KeepAspectRatio);

    ui->jacketPic->setPixmap(ScaledPixJacket);

    QPixmap pixShoes(":/images/schuhe.png");

    QPixmap ScaledPixShoes = pixShoes.scaled(QSize(150,150),  Qt::KeepAspectRatio);

    ui->shoesPic->setPixmap(ScaledPixShoes);


    QPixmap pixTrousers(":/images/trousers.png");

    QPixmap ScaledPixTrousers = pixTrousers.scaled(QSize(150,150),  Qt::KeepAspectRatio);

    ui->trousersPic->setPixmap(ScaledPixTrousers);

    QPixmap pixCar(":/images/car.png");

    QPixmap ScaledPixCar = pixCar.scaled(QSize(150,150),  Qt::KeepAspectRatio);

    ui->carPic->setPixmap(ScaledPixCar);
}

void MainWindow::endOfDay()
{
    if (ui->bankAccount->value() > 0){
        ui->message->setText("Spend more money!");
        // alarm if too much money:
        alarmsound = new QMediaPlayer();
        alarmsound->setMedia(QUrl("qrc:/sounds/alarm.mp3"));

        //play bullet sound
        if (alarmsound->state() == QMediaPlayer::PlayingState){
            alarmsound->setPosition(0);
        }
        else if (alarmsound->state() == QMediaPlayer::StoppedState){
            alarmsound->play();
        }
    }

    // rest of money is transferred to penalty account and bank account is reset:
     restMoney += ui->bankAccount->value();
     ui->penalty->setValue(restMoney);

     ui->bankAccount->setValue(1000);
}

void MainWindow::decreaseAccount(int price)
{
    int money = ui->bankAccount->value() - price;

    if (money >= 0){
        moneysound = new QMediaPlayer();
        moneysound->setMedia(QUrl("qrc:/sounds/cash.mp3"));

        //play bullet sound
        if (moneysound->state() == QMediaPlayer::PlayingState){
            moneysound->setPosition(0);
        }
        else if (moneysound->state() == QMediaPlayer::StoppedState){
            moneysound->play();
        }

    ui->bankAccount->setValue(money);
    }
}

void MainWindow::increaseAccount(int salary)
{
    ui->bankAccount->setValue(salary);
}

void MainWindow::playMusic()
{

    music->play();
}


void MainWindow::setVolume(int volume)
{
       music->setVolume(volume);

}

MainWindow::~MainWindow()
{
    delete ui;
}
