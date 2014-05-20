#include "widget.h"

Interprete::Interprete(QWidget *parent)
    : QWidget(parent)
{
    generalDisplay=new QTextEdit(this);
        generalDisplay->setReadOnly(true);
        //generalDisplay->setTextInteractionFlags(0);
        generalDisplay->setFocusPolicy(Qt::NoFocus);
    input=new QLineEdit(this);

    //initialisation de QMap
    reference["+"] = &Interprete::addition;
    reference["swap"]= &Interprete::swap;
    reference["swapstr"]=&Interprete::swapString;
    reference["sin"]=&Interprete::sinus;
    reference["cos"]=&Interprete::cosinus;
    reference["tan"]=&Interprete::tangente;
    reference["sqrt"]=&Interprete::racineCarre;
    reference["trunc"]=&Interprete::tronque;

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

        // Exécution
        execute();

        // Affichage du résultat
        // generalDisplay->setText(generalDisplay->toPlainText()+'\n'+QString::number(numPile.depiler()));

        input->clear();
    }
}

void Interprete::execute(){

    // Liste des mots de l'instruction
    instruction = input->text().split(" ");

    curseur=0;
    do{
    // Si le mot clef existe
        if(reference.find(instruction[curseur]) != reference.end()){
            (this->*reference.value(instruction[curseur]))(); // Appelle de la fonction
        }
        else{
            //int test = instruction[curseur].toDouble();
            numPile.empiler(instruction[curseur].toDouble());
        }
        ++curseur;
    }while(curseur< instruction.count());

}

// +
void Interprete::addition() {
    double a = numPile.depiler();
    double b = numPile.depiler();
    numPile.empiler(a+b);
}

// swap
void Interprete::swap(){
    double a = numPile.depiler();
    double b = numPile.depiler();
    numPile.empiler(b);
    numPile.empiler(a);
}

// swapstr
void Interprete::swapString(){
    std::string a = strPile.depiler();
    std::string b = strPile.depiler();
    strPile.empiler(b);
    strPile.empiler(a);
}

#define PI 3.14159265358979323846

// sin
void Interprete::sinus(){
    double rad(PI*(numPile.depiler())/180);
    rad=sin(rad);
    numPile.empiler(180*rad*PI);
}

// cos
void Interprete::cosinus(){
    double rad(PI*(numPile.depiler())/180);
    rad=cos(rad);
    numPile.empiler(180*rad*PI);
}

// tan
void Interprete::tangente(){
    double rad(PI*(numPile.depiler())/180);
    rad=tan(rad);
    numPile.empiler(180*rad*PI);
}

// sqrt
void Interprete::racineCarre(){
    numPile.empiler(sqrt(numPile.depiler()));
}

// trunc
void Interprete::tronque(){
    numPile.empiler(double(int(numPile.depiler())));
}

// line
