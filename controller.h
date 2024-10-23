#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gamelogic.h"
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

private:
    GameLogic model;

    std::vector<int>::iterator moveIterator;

    bool isValidMove(int buttonValue);

//     int getWaitTime(int currentWaitTime);

//     int incrementProgressBar();

//     void roundEnd();

    void playerClickedButton(int buttonValue);

//     const int COMPUTER_TURN_LENGTH = 2000; // TODO: adjust this as needed.

public:
     explicit Controller(QObject *parent = nullptr);

public slots:
    void gameStart();

    void redButtonPressed();

    void blueButtonPressed();

signals:
//     void updateProgressBar(int);

    void gameEnd();
};

#endif // CONTROLLER_H
