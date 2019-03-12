#include "fenprincipal.h"
#include "ui_fenprincipal.h"

Fenprincipal::Fenprincipal() : QWidget()
{
    QVBoxLayout *layoutprincipal = new QVBoxLayout;


    QGroupBox *groupBox1 = new QGroupBox("Options");
    QGroupBox *groupBox2 = new QGroupBox("Definition de la classe");
    QGroupBox *groupBox3 = new QGroupBox("Commentaire");
        groupBox3->setCheckable(1);
        groupBox3->setChecked(0);
    QGroupBox *groupBox4 = new QGroupBox("");



    QFormLayout *layoutform = new QFormLayout;

        m_classe_mere = new QLineEdit;
        m_classe = new QLineEdit;

        layoutform->addRow("classe_mere: ", m_classe_mere);
        layoutform->addRow("classe: ", m_classe);




    QVBoxLayout *layoutBox = new QVBoxLayout;


        m_check1 = new QCheckBox("proteger le header contre des problèmes", this);
        m_check2 = new QCheckBox("faire un construteur", this);
        m_check3 = new QCheckBox("faire un destructeur", this);
        m_check4 = new QCheckBox("faire une fonction get_nom", this);

        layoutBox->addWidget(m_check1);
        layoutBox->addWidget(m_check2);
        layoutBox->addWidget(m_check3);
        layoutBox->addWidget(m_check4);


   QFormLayout *layoutcommentaire = new QFormLayout;

        m_auteur = new QLineEdit;
        m_date = new QDateEdit;
            QDate date1;
            date1.setDate(2019, 02, 20);
            m_date->setDate(date1);
        m_role = new QTextEdit;


        layoutcommentaire->addRow("&Auteur: ", m_auteur);
        layoutcommentaire->addRow("Date de création", m_date);
        layoutcommentaire->addRow("Role de la classe: ", m_role);


    QHBoxLayout *lesboutons = new QHBoxLayout;

        m_generer = new QPushButton("generer", this);
        m_quitter = new QPushButton("quitter", this);


        lesboutons->addWidget(m_generer);
        lesboutons->addWidget(m_quitter);

    groupBox1->setLayout(layoutBox);
    groupBox2->setLayout(layoutform);
    groupBox3->setLayout(layoutcommentaire);
    groupBox4->setLayout(lesboutons);



    layoutprincipal->addWidget(groupBox2);
    layoutprincipal->addWidget(groupBox1);
    layoutprincipal->addWidget(groupBox3);
    layoutprincipal->addWidget(groupBox4);

    this->setLayout(layoutprincipal);




    QObject::connect(m_generer, SIGNAL(clicked()), this, SLOT(generation_code()));
    QObject::connect(m_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));



};




QString Fenprincipal::generation_code()
{
    QObject::connect(m_auteur, SIGNAL(textChanged(QString)), m_auteur, SLOT(setText(QString)));
    QString code;
    code.push_back("\\*");
    code.push_back("<br/>");
    if(m_auteur->isModified()){
        code.push_back("L'auteur: ");
        code.push_back(m_auteur->text());
        code.push_back("<br/>");
    }

    code.push_back("Date de creation: ");
    code.push_back(m_date->text());
    code.push_back("<br/>");

    code.push_back("Role de la classe: ");
    code.push_back(m_role->toHtml());
    code.push_back("<br/>");
    code.push_back("*/");
    code.push_back("<br/>");

    if(m_check1->isChecked()){
        code.push_back("<br/>");
        code.push_back("#ifndef HEADER_");
        code.push_back(m_classe->text().toUpper());
        code.push_back("<br/>");
        code.push_back("#define HEADER_");
        code.push_back(m_classe->text().toUpper());
        code.push_back("<br/>");
        code.push_back("<br/>");

    }


    code.push_back("<br/>");
    code.push_back("class ");
    code.push_back(m_classe->text());
    code.push_back(" : public ");
    code.push_back(m_classe_mere->text());
    code.push_back("<br/>");
    code.push_back("{");
    code.push_back("<br/>");
    code.push_back("    public : ");
    code.push_back("<br/>");

    if(m_check2->isChecked()){
        code.push_back("        ");
        code.push_back(m_classe->text());
        code.push_back("();");
        code.push_back("<br/>");
        code.push_back("<br/>");
    }

    if(m_check3->isChecked()){
        code.push_back("        ~");
        code.push_back(m_classe->text());
        code.push_back("();");
        code.push_back("<br/>");
        code.push_back("<br/>");
    }

    if(m_check4->isChecked()){
        code.push_back("        ");
        code.push_back("void get_nom();");
        code.push_back("<br/>");
        code.push_back("<br/>");
    }

    code.push_back("    protected:");
    code.push_back("<br/>");
    code.push_back("<br/>");
    code.push_back("    private:");
    code.push_back("<br/>");
    code.push_back("}");
    code.push_back("<br/>");
    code.push_back("<br/>");
    code.push_back("#endif");

    fenetre2 *f2 = new fenetre2(code);

    QObject::connect(m_generer, SIGNAL(clicked()), f2, SLOT(exec()));

    return code;
}

Fenprincipal::~Fenprincipal()
{

    delete m_classe_mere;
    delete m_classe;
    delete m_date;
    delete m_role;
    delete m_check1;
    delete m_check2;
    delete m_check3;
    delete m_check4;
    delete m_auteur;
    delete m_generer;
    delete m_quitter;
    //delete ui;
}
