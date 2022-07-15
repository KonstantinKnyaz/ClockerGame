#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include <ctime>
#include <QMessageBox>

#define TIME_TO_CLICK 15000

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    Clicker(Q_NULLPTR),
    gameIsStarted(false),
    timer(Q_NULLPTR),
    randomClick(0)
{
    ui->setupUi(this);
    this->setWindowTitle("Кликер");
    Clicker = new ClickerGame();
    MainWindow::installEventFilter(this);
    //Таймер удалится вместе с родителем
    timer = new QTimer(this);
    connections();
}

MainWindow::~MainWindow()
{
    //Если бы не указал родителя таймеру, то надо было бы очистить его в деструкторе и занулить указатель (хотя зануление здесь необязательно тк таймер удаляется при закрытии приложения)
//    delete timer;
//    timer = nullptr;
    delete Clicker;
    Clicker = Q_NULLPTR;
    delete ui;
}

void MainWindow::startGame()
{
    qDebug() << "Старт игры";

    srand(time(0));
    randomClick = rand() % 10 + 1;
    ui->clicks->setText(QString::number(randomClick));

    timer->connect(timer ,&QTimer::timeout, [this]() {
        if(gameIsStarted) {
            unsigned int mousClick = Clicker->getAllClicksAndClear();
//            mousClick == randomClick ? Clicker->addSuccessClick() : Clicker->addFailedClick();
            if(mousClick == randomClick) {
                Clicker->addSuccessClick();
                ui->statusLabel->setStyleSheet("QLabel {color: green}");
                ui->statusLabel->setText("Успех! Идём дальше.");
            } else {
                Clicker->addFailedClick();
                ui->statusLabel->setStyleSheet("QLabel {color: red}");
                ui->statusLabel->setText("Провал! Попробуй ещё.");
            }
            QTimer::singleShot(1000, [this]() {
                ui->statusLabel->setStyleSheet("QLabel {}");
                ui->statusLabel->setText("");
            });
            qDebug() << "Клики мышкой:" << mousClick << "Необходимое число кликов:" << randomClick;
        }
        srand(time(0));
        randomClick = rand() % 10 + 1;
        ui->clicks->setText(QString::number(randomClick));
        ui->successful->setText(QString::number(Clicker->getSuccessCountClick()));
        ui->failed->setText(QString::number(Clicker->getFailedCountClick()));
    });

    timer->start(TIME_TO_CLICK);
    gameIsStarted = true;
}

void MainWindow::stopGame()
{

    QMessageBox msgBox(
                QMessageBox::Question,
                QString::fromUtf8("Игра: Кликер"),
                QString::fromUtf8("Вы действительно хотите прекратить игру?"),
                QMessageBox::Yes | QMessageBox::No
                );
    QApplication::setApplicationDisplayName(msgBox.windowTitle());
    msgBox.setButtonText(QMessageBox::Yes,"Да");
    msgBox.setButtonText(QMessageBox::No, "Нет");

    msgBox.setIcon(QMessageBox::Question);
    int r = msgBox.exec();
    if(r == QMessageBox::Yes){
        timer->disconnect();
        gameIsStarted = false;
        randomClick = 0;
        Clicker->allClear();
        ui->successful->setText("0");
        ui->failed->setText("0");
        ui->clicks->setText("0");
    }
}

void MainWindow::connections()
{
    ui->startBtn->connect(ui->startBtn, &QPushButton::clicked, [this]() {
        startGame();
    });

    ui->stopBtn->connect(ui->stopBtn, &QPushButton::clicked, [this]() {
        stopGame();
    });
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == this) {
        if (event->type() == QEvent::MouseButtonPress) {
            qDebug() << "Click";
            if(gameIsStarted) {
                Clicker->setOneClick();
                ui->widget_2->setStyleSheet("QWidget {background-color: green}");
                QTimer::singleShot(100, [this]() {
                    ui->widget_2->setStyleSheet("QWidget {}");
                });
            }
            return true;
        } else
            return false;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox(
        QMessageBox::Information,
        QString::fromUtf8("Завершение Игры"),
        QString::fromUtf8("Приходите ещё."),
        QMessageBox::Yes
    );
    msgBox.setButtonText(QMessageBox::Yes, QString::fromUtf8("Обязательно приду"));
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setIcon(QMessageBox::Information);
    int r = msgBox.exec();
    if(r == QMessageBox::Yes )
    {
        event->accept();
    }

}
