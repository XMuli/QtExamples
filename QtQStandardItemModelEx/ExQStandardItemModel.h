#ifndef EXQSTANDARDITEMMODEL_H
#define EXQSTANDARDITEMMODEL_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#include "ExDelegate.h"

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
    void init(QStringList& list);           //从list初始化数据模型

private slots:
    void onCurrentChanged(const QModelIndex& current, const QModelIndex& previous);  //当前单元格发生变化时
    void on_actOpen_triggered();            //打开和导入文件，并且在plainTextEdit里面显示
    void on_actAppend_triggered();          //在表格的最后一行添加一行
    void on_actSave_triggered();            //保存文件
    void on_actInsert_triggered();          //在当前选中的一行，其前面插入一行
    void on_actDelete_triggered();          //删除一行
    void on_actExit_triggered();            //关闭退出
    void on_actModelData_triggered();       //预览模型
    void on_actAlignLeft_triggered();       //左对齐
    void on_actAlignCenter_triggered();     //文本居中
    void on_actAlingRight_triggered();      //文本右对齐
    void on_actBold_triggered(bool checked);//文本加粗

private:
    Ui::ExQStandardItemModel *ui;

    QLabel  *m_labCurrFile;                 //当前文件
    QLabel *m_labCellPos;                   //当前单元格行列号
    QLabel *m_labCellText;                  //当前单元格数据内容
    QStandardItemModel *m_model;            //数据模型
    QItemSelectionModel *m_selectModet;     //选择模型

};

#endif // EXQSTANDARDITEMMODEL_H
