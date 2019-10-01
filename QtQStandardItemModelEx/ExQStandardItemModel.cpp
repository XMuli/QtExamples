#include "ExQStandardItemModel.h"
#include "ui_ExQStandardItemModel.h"
#include <QDebug>
#include <QFileDialog>
#include <QFont>
#include <QTextStream>

#define COLUMN 6  //数据表的列数

ExQStandardItemModel::ExQStandardItemModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQStandardItemModel)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("QTableView和QStandardItemModel的用法"));

    ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);     //设置主工具栏的图标样式风格

    m_labCurrFile = new QLabel("当前文件：", this);                       //设置状态栏
    m_labCellPos = new QLabel("当前单元格：", this);
    m_labCellText = new QLabel("单元格内容：", this);
    m_labCurrFile->setMinimumWidth(200);
    m_labCellPos->setMinimumWidth(200);
    m_labCellText->setMinimumWidth(200);
    ui->statusBar->addWidget(m_labCurrFile);
    ui->statusBar->addWidget(m_labCellPos);
    ui->statusBar->addWidget(m_labCellText);

    m_model = new QStandardItemModel(2, COLUMN, this);                          //设置数据模型，一开始设置为默认的2行6列表的一个表
    m_selectModet = new QItemSelectionModel(m_model, this);                //设置选择模型

    ui->tableView->setModel(m_model);                                      //设置数据模型
    ui->tableView->setSelectionModel(m_selectModet);                       //设置选择模型
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection); //设置选择模式
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);   //设置选择行为

    connect(m_selectModet, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(onCurrentChanged(QModelIndex, QModelIndex)));  //选择当前单元格变化时的信号与槽
}

ExQStandardItemModel::~ExQStandardItemModel()
{
    delete ui;
}

//从list初始化数据模型QTableView里面
void ExQStandardItemModel::init(QStringList &list)
{
    int rowCount = list.count();                                           //文本行数，第一行为表头
    m_model->setRowCount(rowCount - 1);

    QString header = list.at(0);
    QStringList headerList = header.split(QRegExp("\\s+"), QString::SkipEmptyParts); //通过一个或者多个空格或者tab按键切割
    m_model->setHorizontalHeaderLabels(headerList);                       //设置表头

    QStandardItem *item = nullptr;                                        //此处开始，设置表格数据
    QStringList tempList;
    int j = 0;

    for (int i = 1; i < rowCount; i++) {
        QString aLineText = list.at(i);
        tempList = aLineText.split(QRegExp("\\s+"), QString::SkipEmptyParts);//正则表达式中\s匹配任何空白字符，包括空格、制表符、换页符等等, 等价于[ \f\n\r\t\v]

        for ( j = 0; j < COLUMN - 1; j++) {                                     //设置前5列的item

            if (j == 3) {
                ExDelegate *itemDelegate = new ExDelegate();
                ui->tableView->setItemDelegateForColumn(3, itemDelegate);
            }

            item = new QStandardItem(tempList.at(j));
            m_model->setItem(i - 1, j, item);
        }



        item = new QStandardItem(tempList.at(j));                          //最后一列的item
        item->setCheckable(true);                                          //设置有检查框

        if ( tempList.at(j) == "https://www.google.com")
            item->setCheckState(Qt::Unchecked);
        else
            item->setCheckState(Qt::Checked);

        m_model->setItem(i - 1, COLUMN -1, item);
    }
}

//当前单元格发生变化时
void ExQStandardItemModel::onCurrentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    if (current.isValid()) {                                               //当前模型索性有效
        m_labCellPos->setText(QString("当前单元格：%1行, %2列").arg(current.row()).arg(current.column()));
        QStandardItem *item = m_model->itemFromIndex(current);             //从模型索引获得Item
        m_labCellText->setText(QString("当前文件：%1").arg(item->text()));  //显示item的文字内容

        QFont font = item->font();
        ui->actBold->setChecked(font.bold());                              //更新actFontBold的check状态
    }
}

//action+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//打开和导入文件，并且在plainTextEdit里面显示
void ExQStandardItemModel::on_actOpen_triggered()
{
    QString currPath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this, "打开一个文件", currPath, "导入数据文件(*txt);;所有文件(*.*)");

    if (fileName.isEmpty())
        return;

    QStringList list;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {                //只读形式打开文本文件
        QTextStream stream(&file);                                         //用文本流读取文件
        ui->plainTextEdit->clear();

        while (!stream.atEnd()) {                                          //读取文本中文本的内容
            QString str = stream.readLine();
            ui->plainTextEdit->appendPlainText(str);
            list.append(str);
        }

        file.close();                                                      //关闭
        m_labCurrFile->setText("当前文件：" + fileName);                    //设置状态栏

        ui->actAppend->setEnabled(true);                                   //设置action的Enabled的属性
        ui->actInsert->setEnabled(true);
        ui->actDelete->setEnabled(true);
        ui->actSave->setEnabled(true);
    }

    init(list);                                                            //初始化.txt的数据
}

//在表格的最后一行添加一行
void ExQStandardItemModel::on_actAppend_triggered()
{
    QList<QStandardItem *> list;
    QStandardItem *item;

    //获取表头前五列
    for (int i = 0; i < COLUMN - 1; i++) {
        item = new QStandardItem("添加一行");
        list<<item;
    }

    //获取最后一列
    QString str = m_model->headerData(m_model->columnCount() - 1, Qt::Horizontal, Qt::DisplayRole).toString();
    item = new QStandardItem(str + "添加一行");
    item->setCheckable(true);
    list<<item;

    m_model->insertRow(m_model->rowCount(), list);
    QModelIndex currIndex = m_model->index(m_model->rowCount() - 1, 0);  //创建最后一行的ModelIndex
    m_selectModet->clearSelection();
    m_selectModet->setCurrentIndex(currIndex, QItemSelectionModel::Select);
}

//保存文件
void ExQStandardItemModel::on_actSave_triggered()
{
    QString path = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getSaveFileName(this, tr("选择一个文件"), path, "另存数据(*.txt);;所有数据(*.*)");
    if ( fileName.isEmpty())
        return;

    QFile file(fileName);

    if (!(file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate))) //读写，文本，覆盖原有内容打开
        return;

    QTextStream stream(&file);                                            //用文本流读取文件
    QStandardItem *item;
    int i = 0 ;
    int j = 0;
    QString str = "";
    ui->plainTextEdit->clear();

    //获取表头文字
    for (i = 0; i < m_model->columnCount(); i++) {
        item =  m_model->horizontalHeaderItem(i);
        str = str + item->text() + "\t\t";                                 //以TAB按键隔开
    }
    stream<<str<<"\n";
    ui->plainTextEdit->appendPlainText(str);

    //获取数据区文字
    for (i = 1; i < m_model->rowCount(); i++) {
        str = "";

        for (j = 0; j < m_model->columnCount(); j++) {
            item = m_model->item(i, j);
            str = str + item->text() + "\t\t";
        }
        stream<<str<<"\n";
        ui->plainTextEdit->appendPlainText(str);
    }
}

//在当前选中的一行，其前面插入一行
void ExQStandardItemModel::on_actInsert_triggered()
{
    QList<QStandardItem *> list;
    QStandardItem *item;

    for (int i = 0; i < COLUMN - 1; i++) {
        item = new QStandardItem("插入一行");
        list<<item;
    }

    QString str = m_model->headerData(m_model->columnCount() - 1, Qt::Horizontal, Qt::DisplayRole).toString();
    item = new QStandardItem(str + "插入一行");
    item->setCheckable(true);
    list<<item;

    QModelIndex currIndex = m_selectModet->currentIndex();
    m_model->insertRow(currIndex.row(), list);                 //在当前行的前面插入一行
    m_selectModet->clearSelection();
    m_selectModet->setCurrentIndex(currIndex, QItemSelectionModel::Select);
}


//删除一行
void ExQStandardItemModel::on_actDelete_triggered()
{
    QModelIndex currIndex = m_selectModet->currentIndex();
    m_model->removeRow(currIndex.row());
}

//关闭退出
void ExQStandardItemModel::on_actExit_triggered()
{
    close();
}

//预览数据模型:模型数据导出到PlainTextEdit显示
void ExQStandardItemModel::on_actModelData_triggered()
{                                          //用文本流读取文件
    QStandardItem *item;
    int i = 0 ;
    int j = 0;
    QString str = "";
    ui->plainTextEdit->clear();

    //获取表头文字
    for (i = 0; i < m_model->columnCount(); i++) {
        item =  m_model->horizontalHeaderItem(i);
        str = str + item->text() + "\t\t";                                 //以TAB按键隔开
    }

    ui->plainTextEdit->appendPlainText(str);

    //获取数据区文字
    for (i = 1; i < m_model->rowCount(); i++) {
        str = "";

        for (j = 0; j < m_model->columnCount(); j++) {
            item = m_model->item(i, j);
            str = str + item->text() + "\t\t";
        }
        ui->plainTextEdit->appendPlainText(str);
    }
}

//左对齐
void ExQStandardItemModel::on_actAlignLeft_triggered()
{
    if (!m_selectModet->hasSelection())
        return;

    QModelIndexList list = m_selectModet->selectedIndexes();     //获得选中的List<item>

    for (int i = 0; i < list.count(); i++) {
        QModelIndex index = list.at(i);
        QStandardItem *item = m_model->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignLeft);                   //设置文本左对齐
    }
}

//文本居中
void ExQStandardItemModel::on_actAlignCenter_triggered()
{
    if (!m_selectModet->hasSelection())
        return;

    QModelIndexList list = m_selectModet->selectedIndexes();     //获得选中的List<item>

    for (int i = 0; i < list.count(); i++) {
        QModelIndex index = list.at(i);                          //获取一个模型索引
        QStandardItem *item = m_model->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignCenter);                 //设置文本居中
    }
}

//文本右对齐
void ExQStandardItemModel::on_actAlingRight_triggered()
{
    if (!m_selectModet->hasSelection())
        return;

    QModelIndexList list = m_selectModet->selectedIndexes();

    for (int i = 0; i < list.count(); i++) {
        QModelIndex index = list.at(i);
        QStandardItem *item = m_model->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignRight);
    }
}

//文本加粗
void ExQStandardItemModel::on_actBold_triggered(bool checked)
{
    if (!m_selectModet->hasSelection())
        return;

    QModelIndexList list = m_selectModet->selectedIndexes();

    for (int i = 0; i < list.count(); i++) {
        QModelIndex index = list.at(i);
        QStandardItem *item = m_model->itemFromIndex(index);
        QFont font = item->font();
        font.setBold(checked);
        item->setFont(font);
    }
}
