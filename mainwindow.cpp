#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller.h"
#include <QTimer>

MainWindow::MainWindow(Controller& controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startButtonClicked);
    connect(ui->startButton, &QPushButton::clicked, &controller, &Controller::gameStart);
    connect(&controller, &Controller::gameEnd, this, &MainWindow::gameOver);
    connect(ui->redButton, &QPushButton::clicked, &controller, &Controller::redButtonPressed);
    connect(ui->blueButton, &QPushButton::clicked, &controller, &Controller::blueButtonPressed);
    connect(&controller, &Controller::updateProgressBar, ui->progressBar, &QProgressBar::setValue);
    connect(&controller, &Controller::flashButton, this, &MainWindow::buttonFlash);
    connect(&controller, &Controller::buttonEnabled, this, &MainWindow::buttonEnabled);

    setRedButtonColor();
    setBlueButtonColor();
    ui->loseMessage->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRedButtonColor()
{
    ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255, 150, 150);}"));
}

void MainWindow::setBlueButtonColor()
{
    ui->blueButton->setStyleSheet( QString("QPushButton {background-color: rgb(50,50,139);} QPushButton:pressed {background-color: rgb(150, 150, 255);}"));
}

void MainWindow::buttonFlash(int buttonId)
{
    if (buttonId == 0)
    {
        redButtonFlash();
        return;
    }
    blueButtonFlash();
}

void MainWindow::buttonEnabled(bool enabled)
{
    if(enabled)
    {
        ui->progressBar->setValue(0);
    }
    ui->redButton->setEnabled(enabled);
    ui->blueButton->setEnabled(enabled);
}

void MainWindow::startButtonClicked()
{
    ui->startButton->setEnabled(false);
    ui->loseMessage->setVisible(false);
}

void MainWindow::redButtonFlash()
{
    ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(255, 150, 150);}"));
    QTimer::singleShot(500, Qt::PreciseTimer, this, &MainWindow::setRedButtonColor);
}

void MainWindow::blueButtonFlash()
{
    ui->blueButton->setStyleSheet( QString("QPushButton {background-color: rgb(150, 150, 255);}"));
    QTimer::singleShot(500, Qt::PreciseTimer, this, &MainWindow::setBlueButtonColor);
}

void MainWindow::gameOver()
{
    ui->loseMessage->setVisible(true);
    buttonEnabled(false);
    ui->startButton->setEnabled(true);
}
