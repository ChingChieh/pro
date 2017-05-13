#include "Mana.h"
#include <QFont>

Mana::Mana(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the mana to 0
    mana = 10;

    // draw the text
    setPlainText(QString("Mana: ") + QString::number(mana)); // Mana:10
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

    QTimer * M_timer = new QTimer(this);
    connect(M_timer,SIGNAL(timeout()),this,SLOT(m_increase()));
    M_timer->start(2000);
}

void Mana::m_decrease(){
    mana--;
    setPlainText(QString("Mana: ") + QString::number(mana)); // Mana:2
}

int Mana::getMana(){
    return mana;
}

void Mana::m_increase(){
    mana++;
    setPlainText(QString("Mana: ") + QString::number(mana)); // Mana:3
}
