#ifndef EXQTREEWIDGET_H
#define EXQTREEWIDGET_H

#include <QMainWindow>
#include <QLabel>
#include <QTreeWidgetItem>
#include <QFileDialog>

namespace Ui {
class ExQTreeWidget;
}

class ExQTreeWidget : public QMainWindow
{
    Q_OBJECT

public:

    enum treeItemType {         //枚举，节点类型
        itemRoot,
        itemFile,
        itemImage
    };

    enum treeColNum {           //目录树列表的编号
        colItem = 0,
        colItemType = 1
    };

    explicit ExQTreeWidget(QWidget *parent = nullptr);
    ~ExQTreeWidget();

    void initTree();                                                //初始化根节点（唯一）
    void addFolderItem(QTreeWidgetItem *parItem, QString dirName);  //添加目录
    void addImageItem(QTreeWidgetItem *parItem, QString fileName);  //添加图片文件
    QString getFinalFolderName(const QString &pathName);            //从完整的路径里面，获取最后的文件夹名称
    void changeItemCaption(QTreeWidgetItem* parItem);               //遍历item下面的所有节点
    void displayImage(QTreeWidgetItem* item);                       //显示当前item的图片（默认以适配高度）

private slots:
    void on_actAddFolder_triggered();                               //增加文件夹
    void on_actAddFile_triggered();                                 //添加图片文件
    void on_actDeleFile_triggered();                                //删除节点
    void on_actScanItems_triggered();                               //遍历所有的顶层节点(本处只有一个root顶层节点)
    void on_actAdaptiveHeight_triggered();                          //图片自动适应高度
    void on_actAdaptiveWidth_triggered();                           //图片自动适应宽度
    void on_actAmplification_triggered();                           //放大
    void on_actShrink_triggered();                                  //缩小
    void on_actZoomRealSize_triggered();                            //还原
    void on_actDockFloating_triggered(bool check);                  //设置Dock窗口是否浮动
    void on_actDockVisible_triggered(bool checked);                 //设置Dock窗口是否隐藏不显示
    void on_actQiut_triggered();                                    //退出
    void on_treeFiles_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);  //当前节点变化的时候，自动加载当前图片
    void on_dockWidget_visibilityChanged(bool visible);             //单击DockWidget组件的标题栏的关闭按钮时候，会隐藏在停靠区域，并且发射信号visibilityChanged;  停靠区域可见性变化
    void on_dockWidget_topLevelChanged(bool topLevel);              //当拖动DockWidget组件，使其浮动或者停靠时候，会发射信号topLevelChanged;  更新其Action的状态

private:
    Ui::ExQTreeWidget *ui;

    QLabel *m_labFlie;      //状态栏显示当前文件路径
    QPixmap m_curPixmap;    //显示当前文件图片
    float   m_ratio;        //图片缩放比例

};

#endif // EXQTREEWIDGET_H
