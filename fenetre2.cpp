#include "fenetre2.h"

fenetre2::fenetre2(QString mot1): QDialog()
{
    QVBoxLayout *layoutprincipal = new QVBoxLayout;

        QGroupBox *groupe1 = new QGroupBox;

         QVBoxLayout *layout1 = new QVBoxLayout;

             m_texte = new QTextEdit(mot1);
             m_fermer = new QPushButton("fermer");

                layout1->addWidget(m_texte);
                layout1->addWidget(m_fermer);

         groupe1->setLayout(layout1);

    layoutprincipal->addWidget(groupe1);


    setFixedSize(600, 600);



    QObject::connect(m_fermer, SIGNAL(clicked()), qApp, SLOT(quit()));

    this->setLayout(layoutprincipal);



}


fenetre2::~fenetre2()
{
    delete m_fermer;
    delete m_texte;

}





