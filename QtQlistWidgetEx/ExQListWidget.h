#ifndef EXQLISTWIDGET_H
#define EXQLISTWIDGET_H

#include <QMainWindow>

namespace Ui {
class ExQListWidget;
}

class ExQListWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExQListWidget(QWidget *parent = nullptr);
    ~ExQListWidget();

private:
    Ui::ExQListWidget *ui;
};

#endif // EXQLISTWIDGET_H
