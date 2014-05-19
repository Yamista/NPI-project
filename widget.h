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

class Interprete : public QWidget
{
    Q_OBJECT
private:
    QTextEdit* generalDisplay;
    QLineEdit* input;

    Pile<QString> strPile;
    Pile<double> numPile;
    QMap<QString,void(Interprete::*)()>reference;

public:
    Interprete(QWidget *parent = 0);
    ~Interprete();
    void execute();
    void addition();

public slots:
    void doInput();
};

#endif // WIDGET_H
