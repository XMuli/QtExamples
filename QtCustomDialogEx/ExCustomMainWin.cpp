#include "ExCustomMainWin.h"
#include "ui_ExCustomMainWin.h"
#include <QDebug>


ExCustomMainWin::ExCustomMainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExCustomMainWin)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("自定义和标准对话框的用法"));

    m_model = nullptr;
    m_dlglocate = nullptr;
    m_dlgSetHeaders = nullptr;

    m_model = new QStandardItemModel(10, 5, this);                       //创建数据模型
    m_seleModel = new QItemSelectionModel(m_model);                      //Item选择模型
    connect(m_seleModel, SIGNAL(currentChanged(QModelIndex,QModelIndex)), this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));

    ui->tableView->setModel(m_model);
    ui->tableView->setSelectionModel(m_seleModel);

    //创建状态栏组件
    m_labCellPos = new QLabel("当前单元格：",this);
    m_labCellPos->setMinimumWidth(180);
    m_labCellPos->setAlignment(Qt::AlignHCenter);

    m_labCellText = new QLabel("单元格内容：",this);
    m_labCellText->setMinimumWidth(200);


    ui->statusBar->addWidget(m_labCellPos);
    ui->statusBar->addWidget(m_labCellText);
}

ExCustomMainWin::~ExCustomMainWin()
{
    delete ui;
}

//定位到单元格，并设置字符串
void ExCustomMainWin::setACellText(int row, int col, QString text)
{
    QModelIndex index = m_model->index(row, col);
    m_seleModel->clearSelection();
    m_seleModel->setCurrentIndex(index, QItemSelectionModel::Select);
    m_model->setData(index, text, Qt::DisplayRole);                    //设置单元格字符串
}

//设置actLocatee的enabled属性
void ExCustomMainWin::setActLocateEnable(bool enable)
{
    ui->actLocate->setEnabled(enable);
}

//将ExDlgLocate指针设置为NULL
void ExCustomMainWin::setDlgLocateNull()
{
    m_dlglocate = nullptr;
}

void ExCustomMainWin::on_actSetHeader_triggered()
{
    if (m_dlgSetHeaders == nullptr)
        m_dlgSetHeaders = new ExDlgSetHeaders(this);                       //只有主窗口销毁时候，该dialog窗口才会销毁

    if(m_dlgSetHeaders->headerList().count() != m_model->columnCount()) {  //如果表头列数发生变化，就重新初始化
        QStringList list;

        for (int i = 0; i < m_model->columnCount(); i++) {
            list.append(m_model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
        }

        m_dlgSetHeaders->setHeaderList(list);                               //对话框，初始化显示
    }

    int ret = m_dlgSetHeaders->exec();                                      //以模态对话框的方式显示
    if (ret == QDialog::Accepted) {                                         //Ok按键被按下
        QStringList list = m_dlgSetHeaders->headerList();
        m_model->setHorizontalHeaderLabels(list);                           //设置模型的表头标题
    }
}


void ExCustomMainWin::on_actSetSize_triggered()
{
    //创建模态对话框， 动态创建， 使用过后删除
    ExDlgSize *dlgSize = new ExDlgSize(this);
    Qt::WindowFlags flags = dlgSize->windowFlags();
    dlgSize->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);      //在窗口上给窗口一个窄的对话框边框。用于固定大小的对话框。
    dlgSize->setRowCol(m_model->rowCount(), m_model->columnCount());

    int ret = dlgSize->exec();                                              //以模态对话框显示
    if (ret == QDialog::Accepted) {                                         //Ok按钮被按下，获取对话框中输入，设置行数和列数
        int row = dlgSize->getRowCount();
        int col = dlgSize->getColCount();
        m_model->setRowCount(row);
        m_model->setColumnCount(col);
    }

    delete dlgSize;
}

void ExCustomMainWin::on_actLocate_triggered()
{
    ui->actLocate->setEnabled(false);
     m_dlglocate = new ExDlgLocate(this);
     m_dlglocate->setAttribute(Qt::WA_DeleteOnClose);                     //关闭对话框时候，自动删除

     Qt::WindowFlags flags = m_dlglocate->windowFlags();
     m_dlglocate->setWindowFlags(flags | Qt::WindowStaysOnTopHint);       //窗口置顶

     m_dlglocate->setSpinRange(m_model->rowCount(), m_model->columnCount());
     QModelIndex curIndex = m_seleModel->currentIndex();

     if (curIndex.isValid())
         m_dlglocate->setSpinValue(curIndex.row(), curIndex.column());

     m_dlglocate->show();
}

void ExCustomMainWin::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    if (current.isValid()) {
        //状态栏的显示
        QStandardItem* item;
        item = m_model->itemFromIndex(current);

        m_labCellPos->setText(QString::asprintf("当前单元格：%d行，%d列", current.row(),current.column())); //显示模型索引的行和列号
        m_labCellText->setText("单元格内容："+ item->text());              //显示item的文字内容
    }
}
