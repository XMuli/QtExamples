#include "ExQListWidget.h"
#include "ui_ExQListWidget.h"
#include <QDateTime>

ExQListWidget::ExQListWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQListWidget)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("QListWidget和QToolButton用法"));

    setCentralWidget(ui->splitter);                        //将QSplitter分割，填充满整个分割区 （分别选中左右控件，然后鼠标右键，Lay out -> Horizon ...）
    setActionForToolBtn();                                 //左侧全部按钮 + 右侧三个按钮关联action
    creatorPopMenu();                                      //右侧一个按钮 + 顶部ToolBar两个按钮的创建

    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);   //设置QListWidget支持右键菜单,这句话一定要有

}

ExQListWidget::~ExQListWidget()
{
    delete ui;
}


//action控件的槽函数+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//actListInit初始化ListWidget的列表项listWidget
void ExQListWidget::on_actListInit_triggered()
{
    QListWidgetItem* item;                                          //每一行都是一个QListWidgetItem
    QIcon icon;
    icon.addFile(":/images/github.png");
    bool chk = ui->checkBox->isChecked();                           //是否可编辑

    ui->listWidget->clear();
    for (int i = 0; i < 13; i++) {
        item = new QListWidgetItem();//(ui->listWidget);            //创建一个item
        item->setText(QString("初始化 第%1个项item").arg(i));        //设置文字
        item->setIcon(icon);                                        //设置icon图标
        item->setCheckState(Qt::Unchecked);                         //设置选中方式

        if (chk)                                                    //可编辑
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        else
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

        ui->listWidget->addItem(item);                              //添加项item到listWidget里面
    }
}

//actInsert在ListWidget的列表项中插入一个项item
void ExQListWidget::on_actInsert_triggered()
{
    QListWidgetItem* item;                                           //每一行都是一个QListWidgetItem
    QIcon icon;
    icon.addFile(":/images/gril.png");
    bool chk = ui->checkBox->isChecked();                             //是否可编辑

    item = new QListWidgetItem();                                     //创建一个item
    item->setText(QString("插入一个项item: " + QDateTime::currentDateTime().toString("yyyy-mm-dd hh:MM:ss:zzz")));  //设置文字
    item->setIcon(icon);                                              //设置icon图标
    item->setCheckState(Qt::Unchecked);                               //设置选中方式

    if (chk)                                                          //可编辑
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    else
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

    ui->listWidget->insertItem(ui->listWidget->currentRow(), item);    //添加项item到listWidget里面
}

//actClear清空ListWidget的所有列表项
void ExQListWidget::on_actClear_triggered()
{
    ui->listWidget->clear();
}

//actDel删除一个指定的ListWidget的列表项
void ExQListWidget::on_actDel_triggered()
{
    int row = ui->listWidget->currentRow();
    QListWidgetItem* item = ui->listWidget->takeItem(row);             //只是移除为row的item（并不删除对象）
    delete item;                                                       //手动删除对象
}

//actAdd添加一个指定的ListWidget的列表项
void ExQListWidget::on_actAdd_triggered()
{
    QListWidgetItem* item;                                           //每一行都是一个QListWidgetItem
    QIcon icon;
    icon.addFile(":/images/TREE.png");
    bool chk = ui->checkBox->isChecked();                             //是否可编辑

    item = new QListWidgetItem();                                     //创建一个item
    item->setText(QString("添加一个项item: " + QDateTime::currentDateTime().toString("yyyy-mm-dd hh:MM:ss:zzz")));  //设置文字
    item->setIcon(icon);                                              //设置icon图标
    item->setCheckState(Qt::Unchecked);                               //设置选中方式

    if (chk)                                                          //可编辑
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserTristate | Qt::ItemIsEnabled);
    else
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserTristate | Qt::ItemIsEnabled);

    ui->listWidget->addItem(item);                                    //添加项item到listWidget里面
}

//设置全选
void ExQListWidget::on_actSelAll_triggered()
{
    int nCount = ui->listWidget->count();
    for (int i = 0; i < nCount; i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        item->setCheckState(Qt::Checked);
    }
}

//设置全不选
void ExQListWidget::on_actSelNone_triggered()
{
    int nCount = ui->listWidget->count();
    for (int i = 0; i < nCount; i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        item->setCheckState(Qt::Unchecked);
    }
}

//设置反选
void ExQListWidget::on_actSelInvs_triggered()
{
    int nCount = ui->listWidget->count();
    for (int i = 0; i < nCount; i++) {
        QListWidgetItem* item = ui->listWidget->item(i);

        if (item->checkState() == Qt::Checked)
            item->setCheckState(Qt::Unchecked);
        else
            item->setCheckState(Qt::Checked);
    }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//设置QListWidget的当前item发生变化，触发的信号,会在右侧显示出来
void ExQListWidget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (current != nullptr) {
        if (previous == nullptr)
            ui->lineEditRight->setText(QString("当前项:%1；  前一项%2").arg(current->text()).arg("不存在"));
        else
            ui->lineEditRight->setText(QString("当前项:%1；  前一项%2").arg(current->text()).arg(previous->text()));
    }
}

//左侧五个按钮， 右侧右边三个按钮 进行QToolButton和action 关联
void ExQListWidget::setActionForToolBtn()
{
    //左侧,第一页的五个按钮
    ui->toolBtnInit->setDefaultAction(ui->actListInit);
    ui->toolBtnClear->setDefaultAction(ui->actClear);
    ui->toolBtnInsert->setDefaultAction(ui->actInsert);
    ui->toolBtnAdd->setDefaultAction(ui->actAdd);
    ui->toolBtnDelete->setDefaultAction(ui->actDel);

    //右侧 右边的三个按钮
    ui->toolBtnSelAll->setDefaultAction(ui->actSelAll);
    ui->toolBtnSelNone->setDefaultAction(ui->actSelInvs);
    ui->toolBtnSelInvs->setDefaultAction(ui->actSelNone);
}


//ToolBar 添加项选择（带下拉框） 和退出；右侧一个按钮也添加一个项的选择
void ExQListWidget::creatorPopMenu()
{
    //创建菜单
    QMenu* menu = new QMenu(this);                                         //创建弹出式菜单
    menu->addAction(ui->actSelAll);
    menu->addAction(ui->actSelInvs);
    menu->addAction(ui->actSelNone);

    //右侧ListWidget， 其上方的toolBtn按钮
    //设置toolBtnSelectItem的多个属性：PopupMode、ToolButtonStyle等（在Design已经设置）
    ui->toolBtnSelectItem->setDefaultAction(ui->actSelPopMenu);            //关联action
    ui->toolBtnSelectItem->setMenu(menu);                                  //设置下拉菜单menu

    //工具栏QToolBar上面的下拉菜单样式按钮
    QToolButton* toolBtn = new QToolButton(this);
    toolBtn->setPopupMode(QToolButton::InstantPopup);                      //下拉式菜单样式属性
    toolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);              //设置汉字出现在icon下面
    toolBtn->setDefaultAction(ui->actSelPopMenu);                          //关联action
    toolBtn->setMenu(menu);                                                //关联菜单
    ui->toolBar->addSeparator();                                           //添加隔栏
    ui->toolBar->addWidget(toolBtn);                                       //添加到工具栏

    //添加退出按钮
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actExit);                                   //添加退出按钮
}


//鼠标右键自定义快捷菜单
void ExQListWidget::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug()<<"11111111";
    Q_UNUSED(pos)
    QMenu* menu = new QMenu(this);                                         //创建菜单
    menu->addAction(ui->actListInit);
    menu->addAction(ui->actAdd);
    menu->addAction(ui->actDel);
    menu->addAction(ui->actClear);
    menu->addAction(ui->actInsert);
    menu->addSeparator();
    menu->addAction(ui->actSelAll);
    menu->addAction(ui->actSelNone);
    menu->addAction(ui->actSelInvs);
    menu->exec(QCursor::pos());                                            //在鼠标光标位置显示右键快捷菜单
    delete menu;                                                           //手工创建的指针必须手工删除
}

//退出
void ExQListWidget::on_actExit_triggered()
{
    this->close();
}
