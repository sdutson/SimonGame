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

    setRedButtonColor();
    setBlueButtonColor();
    ui->loseMessage->setVisible(false);
}

void MainWindow::setRedButtonColor()
{
    ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
}

void MainWindow::setBlueButtonColor()
{
    ui->blueButton->setStyleSheet( QString("QPushButton {background-color: rgb(50,50,139);} QPushButton:pressed {background-color: rgb(0 ,0 ,255);}"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startButtonClicked()
{
    ui->startButton->setEnabled(false);
    ui->redButton->setEnabled(true);
    ui->blueButton->setEnabled(true);
}

void MainWindow::blueButtonFlash() // TODO: Connect this.
{
    ui->blueButton->setStyleSheet( QString("QPushButton {background-color: rgb(255, 0, 0);}"));
    QTimer::singleShot(500, this, &MainWindow::setBlueButtonColor);
}

void MainWindow::redButtonFlash() // TODO: Connect this.
{
    ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(255,150,150);}"));
    QTimer::singleShot(500, this, &MainWindow::setRedButtonColor);
}

void MainWindow::gameOver()
{
    ui->loseMessage->setVisible(true);
}
