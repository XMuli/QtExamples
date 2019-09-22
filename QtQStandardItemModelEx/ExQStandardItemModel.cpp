#include "ExQStandardItemModel.h"
#include "ui_ExQStandardItemModel.h"
#include <QDebug>
#include <QFileDialog>

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

    m_model = new QStandardItemModel(2, 6, this);                          //设置数据模型，一开始设置为默认的2行6列表的一个表
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

        for ( j = 0; j < 6 - 1; j++) {                                     //设置前5列的item
            item = new QStandardItem(tempList.at(j));
            m_model->setItem(i - 1, j, item);
        }

        item = new QStandardItem(tempList.at(j));                          //最后一列的item
        item->setCheckable(true);                                          //设置有检查框

        if ( tempList.at(j) == "https://www.google.com")
            item->setCheckState(Qt::Unchecked);
        else
            item->setCheckState(Qt::Checked);

        m_model->setItem(i - 1, 5, item);
    }
}

//当前单元格发生变化时
void ExQStandardItemModel::onCurrentChanged(const QModelIndex &current, const QModelIndex &previous)
{

}


//action+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//打开和导入文件，并且在plainTextEdit里面显示
void ExQStandardItemModel::on_actOpen_triggered()
{
    QString currPath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this, "打开一个文件", currPath, "导入数据文件(*txt); 所有文件(*.*)");

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

    init(list);                                                        //初始化.txt的数据
}


//在表格的最后一行添加一行
void ExQStandardItemModel::on_actAppend_triggered()
{

}
