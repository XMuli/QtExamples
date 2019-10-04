#ifndef EXCUSTOMMAINWIN_H
#define EXCUSTOMMAINWIN_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#include "ExDlgSize.h"
#include "ExDlgSetHeaders.h"
#include "ExDlgLocate.h"

namespace Ui {
class ExCustomMainWin;
}

class ExCustomMainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExCustomMainWin(QWidget *parent = nullptr);
    ~ExCustomMainWin();

    void setACellText(int row, int col, QString text);   //设置一个单元格,有ExDlgLocate调用

private slots:
    void on_actSetHeader_triggered();
    void on_actSetSize_triggered();
    void on_actLocate_triggered();

private:
    Ui::ExCustomMainWin *ui;

    QStandardItemModel *m_model;            //数据模型
    QItemSelectionModel *m_seleModel;       //item选择模型
    ExDlgSetHeaders *m_dlgSetHeaders;
    ExDlgLocate *m_dlglocate;
};

#endif // EXCUSTOMMAINWIN_H
