#ifndef FENETRE2_H
#define FENETRE2_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QTabWidget>
#include <QSlider>
#include <QInputDialog>
#include <QFormLayout>
#include <QCheckBox>
#include <QGroupBox>
#include <QDateEdit>
#include <QTextEdit>


class fenetre2 : public QDialog
{
    Q_OBJECT


public:
    fenetre2(QString mot1);
    ~fenetre2();


protected:
    QPushButton *m_fermer;
    QTextEdit *m_texte;

};

#endif // FENETRE2_H
