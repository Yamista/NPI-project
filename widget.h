#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMap>
#include "pile.h"
#include <stdexcept>
#include <iostream>
#include <math.h>

class Interprete : public QWidget
{
    Q_OBJECT
private:
    QTextEdit* generalDisplay;
    QLineEdit* input;
    QStringList instruction;
    int curseur;

    Pile<std::string> strPile;
    Pile<double> numPile;
    QMap<QString,void(Interprete::*)()>reference;

public:
    Interprete(QWidget *parent = 0);
    ~Interprete();
    void execute();
    void addition();
    void swap();
    void swapString();
    void sinus();
    void cosinus();
    void tangente();
    void racineCarre();
    void tronque();

public slots:
    void doInput();
};

#endif // WIDGET_H
