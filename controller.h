#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gamelogic.h"
#include <QObject>

class Controller : public QObject
{
    // TODO: Example code has Q_OBJECT here. Do we need it?
    Q_OBJECT

    GameLogic model;

    std::vector<int>::iterator moveIterator;

    bool isValidMove(int buttonValue);

    int getWaitTime(int currentWaitTime);

    int incrementProgressBar();

    void roundEnd();

    void playerClickedButton(int buttonValue);

    const int COMPUTER_TURN_LENGTH = 2000; // TODO: adjust this as needed.


public:
    explicit Controller(QObject *parent = nullptr);

public slots:
    void gameStart();

    void redButtonPressed();

    void blueButtonPressed();

signals:
    updateProgressBar(int);

    gameEnd();
};

#endif // CONTROLLER_H
