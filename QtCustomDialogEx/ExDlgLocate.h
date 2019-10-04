#ifndef EXDLGLOCATE_H
#define EXDLGLOCATE_H

#include <QDialog>

class ExCustomMainWin;


namespace Ui {
class ExDlgLocate;
}

class ExDlgLocate : public QDialog
{
    Q_OBJECT

public:
    explicit ExDlgLocate(QWidget *parent = nullptr);
    ~ExDlgLocate();

    void setSpinRange(int rowCount, int colCount);      //设置spin的设定值
    void setSpinValue(int rowNo, int colNo);            //设置spin的显示值

private slots:
    void on_btnSetText_clicked();

private:
    void closeEvent(QCloseEvent* e);

private:
    Ui::ExDlgLocate *ui;
};

#endif // EXDLGLOCATE_H
