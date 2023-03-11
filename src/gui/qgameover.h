#ifndef QGAMEOVER_H
#define QGAMEOVER_H

#include <QWidget>
#include "qresetbutton.h"

class QGameOver : public QWidget
{
    Q_OBJECT
public:
    explicit QGameOver(QWidget *parent = 0);

    QResetButton* getResetBtn() const;

    int getScore();
    
    void setScore(int score);

signals:

public slots:

private:
    QResetButton* reset;
    QLabel* scoreLabel;
};

#endif 