#ifndef EXDELEGATE_H
#define EXDELEGATE_H

#include <QStyledItemDelegate>


class ExDelegate : public QStyledItemDelegate
{
public:
    ExDelegate();

public:
    //若是写代理的组件，那么必须要有下面这是个重写这四个函数
    virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;      //创建用于编辑的模型数据的widget组件，如一个QComboBox组件
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override;                                             //从数据模型获取数据，显示在代理组件editor之中，让其编辑
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;                   //代理组件editor上的数据更新到数据模型
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;  //用于给widget组件设置一个合适的大小
};

#endif // EXDELEGATE_H
