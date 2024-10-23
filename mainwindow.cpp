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

    setRedButtonColor();
    ui->blueButton->setStyleSheet( QString("QPushButton {background-color: rgb(50,50,139);} QPushButton:pressed {background-color: rgb(0 ,0 ,255);}"));

    // Disable red and blue buttons and slider?
}

void MainWindow::setRedButtonColor()
{
    ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
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
    // controller.gameStart();
}

void MainWindow::redButtonFlash() // TODO: Connect this.
{
        ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(255,150,150);})"));
        QTimer::singleShot(500, this &MainWindow::setRedButtonColor);
}
