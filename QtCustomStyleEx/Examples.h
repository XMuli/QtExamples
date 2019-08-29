#ifndef EXAMPLES_H
#define EXAMPLES_H

#include <QWidget>
#include <QStyleFactory>
#include <QDebug>

#include "ExCustomStyle.h"

namespace Ui {
class Examples;
}

class Examples : public QWidget
{
    Q_OBJECT

public:
    explicit Examples(QWidget *parent = nullptr);
    ~Examples();

    void init();                                                  //获取当前系统支持的默认系统风格
private slots:
    void on_comboBox_currentIndexChanged(const QString &style);

private:
    Ui::Examples *ui;
};

#endif // EXAMPLES_H
