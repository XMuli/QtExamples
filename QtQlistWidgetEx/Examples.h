#ifndef EXAMPLES_H
#define EXAMPLES_H

#include <QWidget>

namespace Ui {
class Examples;
}

class Examples : public QWidget
{
    Q_OBJECT

public:
    explicit Examples(QWidget *parent = nullptr);
    ~Examples();

private:
    Ui::Examples *ui;
};

#endif // EXAMPLES_H
