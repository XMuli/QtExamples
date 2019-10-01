#include "ExDelegate.h"
#include <QComboBox>

ExDelegate::ExDelegate()
{
}


//创建用于编辑的模型数据的widget组件，如一个QComboBox组件
QWidget *ExDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *comboBox = new QComboBox(parent);
    comboBox->addItem("github：https://github.com/touwoyimuli");
    comboBox->addItem("csdn博客：https://blog.csdn.net/qq_33154343");
    comboBox->addItem("github.io博客：https://touwoyimuli.github.io/");
    comboBox->addItem("https://www.google.com/ qt 学习 加油 2019-09-30");

    return  comboBox;                      //返回此编辑器
}

//从数据模型获取数据，显示在代理组件之中，让其编辑
void ExDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString str = index.model()->data(index, Qt::EditRole).toString();
    QComboBox *comboBox = static_cast<QComboBox *>(editor);
    comboBox->addItem(str);
    //其他组件的话， 此处可以设定写的值一类，eg：setText(str)  setValue()
}

//将widget上的数据更新到数据模型
void ExDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox *>(editor);
    QString str = comboBox->currentText();
    model->setData(index, str, Qt::EditRole);
}

//用于给widget组件设置一个合适的大小
void ExDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);      //设置组件的大小
}
