#ifndef EXDIALOG_H
#define EXDIALOG_H

#include <QDialog>

namespace Ui {
class ExDialog;
}

class ExDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExDialog(QWidget *parent = nullptr);
    ~ExDialog();

private slots:
    void on_btnOpenFile_clicked();        //打开一个文件
    void on_btnOpenFiles_clicked();       //打开多个文件
    void on_btnExistingDir_clicked();     //选择已有目录
    void on_btnGetColor_clicked();        //选择颜色
    void on_btnGetFont_clicked();         //选择字体
    void on_btnSaveFile_clicked();        //保存文件

    void on_btnQuestion_clicked();
    void on_btnInformation_clicked();
    void on_btnWarning_clicked();
    void on_btnCritical_clicked();
    void on_btnAbout_clicked();
    void on_btnAboutQt_clicked();

    void on_btnGetString_clicked();       //输入字符串
    void on_btnGetItem_clicked();         //item选择输入
    void on_btnInt_clicked();             //输入整数
    void on_btnDouble_clicked();          //输入浮点数

private:
    Ui::ExDialog *ui;
};

#endif // EXDIALOG_H
