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

    const int COMPUTER_TURN_LENGTH = 2000; // TODO: adjust this as needed.

public:
    explicit Controller(QObject *parent = nullptr);

    void roundEnd();

    void playerClickedButton(int buttonValue);


public slots:
    void gameStart();

signals:
    updateProgressBar(int);

    gameEnd();
};

#endif // CONTROLLER_H
