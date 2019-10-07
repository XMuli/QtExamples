#ifndef EXCUSTOMMAINWIN_H
#define EXCUSTOMMAINWIN_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#include "ExDlgSize.h"
#include "ExDlgSetHeaders.h"
#include "ExDlgLocate.h"
#include <QLabel>

namespace Ui {
class ExCustomMainWin;
}

class ExCustomMainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExCustomMainWin(QWidget *parent = nullptr);
    ~ExCustomMainWin();

    void setACellText(int row, int col, QString text);   //定位到单元格，并设置字符串
    void setActLocateEnable(bool enable);                //设置actLocatee的enabled属性
    void setDlgLocateNull();                             //将ExDlgLocate指针设置为NULL

private slots:
    void on_actSetHeader_triggered();
    void on_actSetSize_triggered();
    void on_actLocate_triggered();
    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);

private:
    Ui::ExCustomMainWin *ui;

    QStandardItemModel *m_model;                        //数据模型
    QItemSelectionModel *m_seleModel;                   //item选择模型
    ExDlgSetHeaders *m_dlgSetHeaders;
    ExDlgLocate *m_dlglocate;
    QLabel  *m_labCellPos;                              //当前单元格行列号
    QLabel  *m_labCellText;                             //当前单元格内容
};

#endif // EXCUSTOMMAINWIN_H
