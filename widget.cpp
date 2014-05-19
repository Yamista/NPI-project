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
        generalDisplay->setText(generalDisplay->toPlainText()+'\n'+QString::number(numPile.depiler()));

        input->clear();
    }
}

void Interprete::execute(){
    // Initialise notre map si elle est vide
    /*
    if(interpreteur->reference.isEmpty()){
        interpreteur->reference["+"] = addition;
        interpreteur->reference["-"] = soustraction;
        interpreteur->reference["*"] = multiplication;
        interpreteur->reference["/"] = division;
    }*/
    // Si on appelle un fichier
    // Si on veut mettre un commentaire

    // Liste des mots de l'instruction
    QStringList instruction = input->text().split(" ");

    int i=0;
    do{
    // Si le mot clef existe
        if(reference.find(instruction[i]) != reference.end()){
            (this->*reference.value(instruction[i]))(); // Appelle de la fonction
        }
        else{
            int test = instruction[i].toDouble();
            numPile.empiler(instruction[i].toDouble());
        }
    }while(i++ < instruction.count());

}

// +
void Interprete::addition() {
    double a = numPile.depiler();
    double b = numPile.depiler();
    numPile.empiler(a+b);
}
