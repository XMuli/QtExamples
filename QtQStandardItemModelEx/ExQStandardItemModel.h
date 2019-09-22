#ifndef EXQSTANDARDITEMMODEL_H
#define EXQSTANDARDITEMMODEL_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>

namespace Ui {
class ExQStandardItemModel;
}

class ExQStandardItemModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExQStandardItemModel(QWidget *parent = nullptr);
    ~ExQStandardItemModel();

private:
    void init(QStringList& list);          //从list初始化数据模型

private slots:
    void onCurrentChanged(const QModelIndex& current, const QModelIndex& previous);  //当前单元格发生变化时
    void on_actOpen_triggered();           //打开和导入文件，并且在plainTextEdit里面显示
    void on_actAppend_triggered();         //在表格的最后一行添加一行

private:
    Ui::ExQStandardItemModel *ui;

    QLabel  *m_labCurrFile;                //当前文件
    QLabel *m_labCellPos;                  //当前单元格行列号
    QLabel *m_labCellText;                 //当前单元格数据内容
    QStandardItemModel *m_model;           //数据模型
    QItemSelectionModel *m_selectModet;    //选择模型

};

#endif // EXQSTANDARDITEMMODEL_H
