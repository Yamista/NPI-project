#include "widget.h"

Interprete::Interprete(QWidget *parent)
    : QWidget(parent)
{
    generalDisplay=new QTextEdit(this);
        generalDisplay->setReadOnly(true);
        //generalDisplay->setTextInteractionFlags(0);
        generalDisplay->setFocusPolicy(Qt::NoFocus);
    input=new QLineEdit(this);

    QVBoxLayout* vLayout1=new QVBoxLayout(this);
        vLayout1->addWidget(generalDisplay);
        vLayout1->addWidget(input);

    this->setLayout(vLayout1);

    connect(input,SIGNAL(editingFinished()),this,SLOT(doInput()));

}

Interprete::~Interprete()
{

}

void Interprete::doInput(){
    if(input->isActiveWindow()){
        generalDisplay->setText(generalDisplay->toPlainText()+'\n'+input->text());

        //execution

        input->clear();
    }
}
