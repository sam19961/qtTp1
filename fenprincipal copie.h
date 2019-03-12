#ifndef FENPRINCIPAL_H
#define FENPRINCIPAL_H

#include <QWidget>

namespace Ui {
class Fenprincipal;
}

class Fenprincipal : public QWidget
{
    Q_OBJECT

public:
    explicit Fenprincipal(QWidget *parent = nullptr);
    ~Fenprincipal();

private:
    Ui::Fenprincipal *ui;
};

#endif // FENPRINCIPAL_H
