#ifndef EXQLISTWIDGET_H
#define EXQLISTWIDGET_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QDebug>

namespace Ui {
class ExQListWidget;
}

class ExQListWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExQListWidget(QWidget *parent = nullptr);
    ~ExQListWidget();

private slots:
    void on_actListInit_triggered();   //初始化ListWidget
    void on_actInsert_triggered();     //插入item
    void on_actAdd_triggered();        //添加item
    void on_actClear_triggered();      //清除所有item
    void on_actDel_triggered();        //删除item
    void on_actSelAll_triggered();     //选中所有item
    void on_actSelNone_triggered();    //全部不选所有的item
    void on_actSelInvs_triggered();    //反选已筛选的item
    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);   //显示当前item的变动
    void on_listWidget_customContextMenuRequested(const QPoint &pos);                             //ListWidget弹出鼠标右键菜单
    void on_actExit_triggered();       //退出软件

private:
    void setActionForToolBtn();        //创建cation和toolButton的关联
    void creatorPopMenu();             //创建两个单独的弹出式菜单的ToolButton

private:
    Ui::ExQListWidget *ui;
};

#endif // EXQLISTWIDGET_H
