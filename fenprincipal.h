#ifndef FENPRINCIPAL_H
#define FENPRINCIPAL_H
#include "fenetre2.h"

namespace Ui {
class Fenprincipal;
}

class Fenprincipal : public QWidget
{
    Q_OBJECT

public:

    ~Fenprincipal();
    Fenprincipal();


public slots:
    QString generation_code();

private:

    Ui::Fenprincipal *ui;
    QPushButton *m_generer;
    QPushButton *m_quitter;

    QLineEdit *m_auteur;
    QDateEdit *m_date;
    QTextEdit *m_role;

    QCheckBox *m_check1;
    QCheckBox *m_check2;
    QCheckBox *m_check3;
    QCheckBox *m_check4;

    QLineEdit *m_classe_mere;
    QLineEdit *m_classe;

    QTextEdit *texte;


};

#endif // FENPRINCIPAL_H
