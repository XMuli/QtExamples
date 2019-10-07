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

    void setSpinRange(int rowCount, int colCount);         //设置spin的设定(最大)值
    void setSpinValue(int rowNo, int colNo);               //设置spin的初始值

private slots:
    void on_btnSetText_clicked();
    void on_btnClose_clicked();

private:
    Ui::ExDlgLocate *ui;

    // QWidget interface
protected:
    virtual void closeEvent(QCloseEvent *event) override;  //窗口关闭事件，关闭时释放本窗口
    virtual void showEvent(QShowEvent *event) override;    //窗口显示事件
};

#endif // EXDLGLOCATE_H
