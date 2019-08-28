#ifndef EXQCOMBOBOX_H
#define EXQCOMBOBOX_H

#include <QWidget>

namespace Ui {
class ExQcomboBox;
}

class ExQcomboBox : public QWidget
{
    Q_OBJECT

public:
    explicit ExQcomboBox(QWidget *parent = nullptr);
    ~ExQcomboBox();

private slots:
    void on_btnLeftInit_clicked();
    void on_btnLeftClear_clicked();
    void on_checkBoxOnlyWrite_clicked();
    void on_btnRightInit_clicked();
    void on_btnBottomAdd_clicked();
    void on_btnBottomClear_clicked();
    void on_checkBoxOnlyRead_clicked();
    void onSelectDisplay(QString str);

private:
    Ui::ExQcomboBox *ui;
};

#endif // EXQCOMBOBOX_H
