#include "ExQTreeWidget.h"
#include "ui_ExQTreeWidget.h"

ExQTreeWidget::ExQTreeWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQTreeWidget)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("QTreeWidget和QDockWidget的讲解和使用"));

    setCentralWidget(ui->scrollArea);                //设置scrollArea为中心控件
    initTree();

    m_labFlie = new QLabel("当前文件的路径:", this);
    ui->statusBar->addWidget(m_labFlie);
}

ExQTreeWidget::~ExQTreeWidget()
{
    delete ui;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//初始化根节点（只能够有唯一）
void ExQTreeWidget::initTree()
{
    //准备工作
    ui->treeFiles->clear();
    QString dataStr = "";
    QIcon icon;
    icon.addFile(":/image/Image001.jpg");

    //创建唯一root的节点
    QTreeWidgetItem* root = new QTreeWidgetItem(treeItemType::itemRoot);
    root->setIcon(treeColNum::colItem, icon);
    root->setText(treeColNum::colItem, QString("相簿"));
    root->setText(treeColNum::colItemType, QString("treeItemType"));
    root->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    root->setCheckState(treeColNum::colItem, Qt::Unchecked);
    root->setData(treeColNum::colItem, Qt::UserRole, QVariant(dataStr));

    //添加顶层节点
    ui->treeFiles->addTopLevelItem(root);
}

//添加目录节点
void ExQTreeWidget::addFolderItem(QTreeWidgetItem *parItem, QString dirName)
{
    QIcon icon;
    icon.addFile(":/image/Image006.jpg");

    //添加一个新的节点
    QTreeWidgetItem* item = new QTreeWidgetItem(treeItemType::itemFile);
    QString folderName = getFinalFolderName(dirName);
    item->setIcon(treeColNum::colItem, icon);
    item->setText(treeColNum::colItem, folderName);
    item->setText(treeColNum::colItemType, QString("treeItemType"));
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setCheckState(treeColNum::colItem, Qt::Unchecked);
    item->setData(treeColNum::colItem, Qt::UserRole, QVariant(dirName));

    //添加子节点
    if (parItem->type() == treeItemType::itemFile) {                 //若是文件节点
        parItem->addChild(item);
    } else if (parItem->type() == treeItemType::itemRoot) {          //若是唯一root节点
        QTreeWidgetItem *root = ui->treeFiles->topLevelItem(0);
        root->addChild(item);
    }

}

//添加图片节点
void ExQTreeWidget::addImageItem(QTreeWidgetItem *parItem, QString fileName)
{
    if (parItem == nullptr)
        return;

    QIcon icon;
    icon.addFile(":/image/Image014.jpg");

    //添加一个新的节点
    QTreeWidgetItem* item = new QTreeWidgetItem(treeItemType::itemImage);
    QString folderName = getFinalFolderName(fileName);
    item->setIcon(treeColNum::colItem, icon);
    item->setText(treeColNum::colItem, folderName);
    item->setText(treeColNum::colItemType, QString("treeItemType"));
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setCheckState(treeColNum::colItem, Qt::Unchecked);
    item->setData(treeColNum::colItem, Qt::UserRole, QVariant(fileName));

    //添加子节点
    if (parItem->type() == treeItemType::itemFile) {                 //若是文件节点
        parItem->addChild(item);
    } else if (parItem->type() == treeItemType::itemRoot) {          //若是唯一root节点
        QTreeWidgetItem *root = ui->treeFiles->topLevelItem(0);
        root->addChild(item);
    }
}

//从完整的路径里面，获取最后的文件夹名称
QString ExQTreeWidget::getFinalFolderName(const QString &pathName)
{
    QString path = pathName;
    int cnt = pathName.count();
    int i = pathName.lastIndexOf("/");
    QString str = pathName.right(cnt - i - 1);
    return str;
}

//遍历传进来的父节点下的所有子节点；每遍历过该节点，就在其节点的信息加一个#
void ExQTreeWidget::changeItemCaption(QTreeWidgetItem *parItem)
{
    QString str = "# " + parItem->text(treeColNum::colItem);
    parItem->setText(treeColNum::colItem, str);

    if (parItem->childCount() < 0)
        return;

    for (int i = 0; i < parItem->childCount(); i++) {
        changeItemCaption(parItem->child(i));                       //回调，调用自己
    }
}

//显示当前item的图片（默认以适配高度）
void ExQTreeWidget::displayImage(QTreeWidgetItem *item)
{
    QString fileName = item->data(treeColNum::colItem, Qt::UserRole).toString();
    m_labFlie->setText(fileName);
    m_curPixmap.load(fileName);                                     //从文件载入图片
    on_actAdaptiveHeight_triggered();                               //自动适应高度显示

    ui->actAmplification->setEnabled(true);
    ui->actShrink->setEnabled(true);
    ui->actZoomRealSize->setEnabled(true);
    ui->actAdaptiveHeight->setEnabled(true);
    ui->actAdaptiveWidth->setEnabled(true);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//增加文件夹
void ExQTreeWidget::on_actAddFolder_triggered()
{
    QString path = QFileDialog::getExistingDirectory();             //选择目录

    if (! path.isEmpty()) {
        QTreeWidgetItem* item = ui->treeFiles->currentItem();       //获取当前节点

        if(item != nullptr)
            addFolderItem(item, path);
    }
}

//添加图片
void ExQTreeWidget::on_actAddFile_triggered()
{
    QStringList list = QFileDialog::getOpenFileNames(this, "选择多个将要加载的图片", "", "Images(*.jpg, *.png, *.*)");         //选择目录

    if (! list.isEmpty()) {
        QTreeWidgetItem* parItem = nullptr;
        QTreeWidgetItem* item = ui->treeFiles->currentItem();       //获取当前节点

        if (item == nullptr)
            return;

        if (item->type() == treeItemType::itemImage) {              //获得父节点
            parItem = item->parent();
        } else {
            parItem = item;
        }

        for (int i = 0; i < list.size(); i++) {
            QString strName = list.at(i);                          //获得文件名称
            addImageItem(parItem, strName);                        //添加图片文件到文件节点
        }
    }
}

//删除节点
void ExQTreeWidget::on_actDeleFile_triggered()
{
    QTreeWidgetItem* parItem = nullptr;
    QTreeWidgetItem* currItem = ui->treeFiles->currentItem();

    if (currItem->type() != treeItemType::itemRoot)
        parItem = currItem->parent();                              //只能够由其父节点删除
//    else
//        ui->treeFiles->takeTopLevelItem(0);                      //删除顶层节点使用这个

    if (currItem == nullptr || parItem == nullptr)
        return;

    parItem->removeChild(currItem);                                //移除没有从内存中删除，所以delete删除
    delete currItem;
}

//遍历所有的顶层节点(本处只有一个root顶层节点)
void ExQTreeWidget::on_actScanItems_triggered()
{
    for (int i = 0; i < ui->treeFiles->topLevelItemCount(); i++) {
        QTreeWidgetItem* currItem = ui->treeFiles->topLevelItem(i); //顶层item
        changeItemCaption(currItem);
    }
}

//图片自动适应高度
void ExQTreeWidget::on_actAdaptiveHeight_triggered()
{
    int height = ui->scrollArea->height();                        //得到scrollArea的高度
    int realHeight = m_curPixmap.height();                        //原始图片的实际高度
    m_ratio = height * 1.0 / realHeight;                          //当前显示比例，必须转换为浮点数

    QPixmap pixmap = m_curPixmap.scaledToHeight(height - 50);     //图片缩放到指定高度
    ui->labDisplay->setPixmap(pixmap);                            //设置Label的PixMap
}

//图片自动适应宽度
void ExQTreeWidget::on_actAdaptiveWidth_triggered()
{
    int width = ui->scrollArea->width();
    int realWidth = m_curPixmap.width();
    m_ratio = width * 1.0 / realWidth;

    QPixmap pixmap = m_curPixmap.scaledToHeight(width - 50);
    ui->labDisplay->setPixmap(pixmap);
}

//当前节点变化的时候，自动加载当前图片
void ExQTreeWidget::on_treeFiles_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if (current != nullptr && previous != nullptr) {
        displayImage(current);
    }
}


//放大
void ExQTreeWidget::on_actAmplification_triggered()
{
    m_ratio *= 1.2;                                             //在当前比例基础上乘以0.8
    int height = m_curPixmap.height() * m_ratio;                // 显示宽度
    int widht = m_curPixmap.width() * m_ratio;                  // 显示宽度

    QPixmap pix = m_curPixmap.scaled(widht, height);            //图片缩放到指定高度和宽度，保持长宽比例
    ui->labDisplay->setPixmap(pix);

}

//缩小
void ExQTreeWidget::on_actShrink_triggered()
{
    m_ratio *= 0.8;
    int height = m_curPixmap.height() * m_ratio;
    int widht = m_curPixmap.width() * m_ratio;

    QPixmap pix = m_curPixmap.scaled(widht, height);
    ui->labDisplay->setPixmap(pix);
}

//还原
void ExQTreeWidget::on_actZoomRealSize_triggered()
{
    m_ratio = 1;
    int height = m_curPixmap.height();
    int widht = m_curPixmap.width();

    QPixmap pix = m_curPixmap.scaled(widht, height);
    ui->labDisplay->setPixmap(pix);
}

//设置Dock窗口是否浮动
void ExQTreeWidget::on_actDockFloating_triggered(bool check)
{
    ui->dockWidget->setFloating(check);
}

//设置Dock窗口是否隐藏不显示
void ExQTreeWidget::on_actDockVisible_triggered(bool checked)
{
    ui->dockWidget->setVisible(!checked);
}

//退出
void ExQTreeWidget::on_actQiut_triggered()
{
    close();
}

//单击DockWidget组件的标题栏的关闭按钮时候，会隐藏在停靠区域，并且发射信号visibilityChanged;  停靠区域可见性变化
void ExQTreeWidget::on_dockWidget_visibilityChanged(bool visible)
{
    ui->actDockVisible->setChecked(visible);
}

//当拖动DockWidget组件，使其浮动或者停靠时候，会发射信号topLevelChanged;  更新其Action的状态
void ExQTreeWidget::on_dockWidget_topLevelChanged(bool topLevel)
{
    ui->actDockFloating->setChecked(topLevel);
}
