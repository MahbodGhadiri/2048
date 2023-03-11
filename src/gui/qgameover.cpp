#include "qgameover.h"
#include "qresetbutton.h"

#include <iostream>
#include <string> //to_string()
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QResizeEvent>

QGameOver::QGameOver(QWidget *parent) : QWidget(parent) {  
    setStyleSheet("QGameOver { background: rgb(240,227,214); }");
    setFixedSize(425,205);
    QVBoxLayout *layout = new QVBoxLayout(this);
    // game over label
    QLabel* gameover = new QLabel("Game Over!", this);
    gameover->setStyleSheet("QLabel { color: rgb(242,86,55); font: 40pt; font: bold;} ");
    // score label
    scoreLabel = new QLabel("", this);
    // reset button
    reset = new QResetButton(this);
    reset->setFixedHeight(50);
    reset->setFixedWidth(100);
    // add game over label to window
    layout->insertWidget(0,gameover,0,Qt::AlignCenter);
    // add score label to window
    layout->insertWidget(1, scoreLabel, 0, Qt::AlignCenter);
    // add reset button to window
    layout->insertWidget(2,reset,0,Qt::AlignCenter);
}

void QGameOver::setScore(int gameScore) {
    scoreLabel->setText(QString("Your score is: %1").arg(gameScore));
}

QResetButton* QGameOver::getResetBtn() const {
    return reset;
}