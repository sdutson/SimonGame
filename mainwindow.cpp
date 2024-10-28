#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
#include "Color.h"
#include <QTimer>

/// @author - Samuel Dutson & Alexander Kuettel
/// Github authors: sdutson and alexanderkuettel
/// Github link: https://github.com/University-of-Utah-CS3505/a6-simon-f24-alexanderkuettel
/// Assign 06
/// Creative Element: For our creative element we added a button that allowed the player to reset the round(Once per game).
MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startButtonClicked);
    connect(ui->startButton, &QPushButton::clicked, &model, &Model::gameStart);
    connect(&model, &Model::gameEnd, this, &MainWindow::gameOver);
    connect(ui->redButton, &QPushButton::clicked, &model, &Model::redButtonPressed);
    connect(ui->blueButton, &QPushButton::clicked, &model, &Model::blueButtonPressed);
    connect(&model, &Model::updateProgressBar, ui->progressBar, &QProgressBar::setValue);
    connect(&model, &Model::flashButton, this, &MainWindow::buttonFlash);
    connect(&model, &Model::buttonEnabled, this, &MainWindow::buttonEnabled);
    connect(ui->reshowFlashes, &QPushButton::clicked, &model, &Model::restartTurnButtonPressed);
    connect(&model, &Model::restartTurnUsed, ui->reshowFlashes, &QPushButton::setEnabled);

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

void MainWindow::buttonFlash(Color buttonId)
{
    if (buttonId == Color::RED)
    {
        redButtonFlash();
    }
    else
    {
        blueButtonFlash();
    }
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
    ui->reshowFlashes->setEnabled(true);
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
