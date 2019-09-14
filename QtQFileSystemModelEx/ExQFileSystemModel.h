#ifndef EXQFILESYSTEMMODEL_H
#define EXQFILESYSTEMMODEL_H

#include <QMainWindow>
#include <QLabel>
#include <QCheckBox>
#include <QFileSystemModel>

namespace Ui {
class ExQFileSystemModel;
}

class ExQFileSystemModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExQFileSystemModel(QWidget *parent = nullptr);
    ~ExQFileSystemModel();

    void init();                //初始化，以及初始化状态栏

private slots:
    void on_treeView_clicked(const QModelIndex &index);  //单击treeView，会在状态栏显示当前节点的信息

private:
    Ui::ExQFileSystemModel *ui;

    QLabel* m_labFileName;       //文件名
    QLabel* m_labFileSize;       //文件大小
    QLabel* m_labFileType;       //文件类型
    QLabel* m_labPath;           //路径
    QCheckBox* m_chkBoxIsFile;   //当前是否为文件或文件夹
    QFileSystemModel* m_model;   //设置文件系统的模型
};

#endif // EXQFILESYSTEMMODEL_H
