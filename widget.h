#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include "pile.h"
#include <stdexcept>

class Interprete : public QWidget
{
    Q_OBJECT
private:
    QTextEdit* generalDisplay;
    QLineEdit* input;

    Pile<QString> strPile;
    Pile<double> numPile;

public:
    Interprete(QWidget *parent = 0);
    ~Interprete();

public slots:
    void doInput();
};

#endif // WIDGET_H
