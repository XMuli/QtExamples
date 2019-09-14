#include "ExQFileSystemModel.h"
#include "ui_ExQFileSystemModel.h"

ExQFileSystemModel::ExQFileSystemModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExQFileSystemModel)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("文件系统模型QFileSystemModel的介绍和使用"));

    init();
    connect(ui->treeView, &QTreeView::clicked, ui->listView, &QListView::setRootIndex);
    connect(ui->treeView, &QTreeView::clicked, ui->tableView, &QTableView::setRootIndex);
}

ExQFileSystemModel::~ExQFileSystemModel()
{
    delete ui;
}

//初始化，以及初始化状态栏
void ExQFileSystemModel::init()
{
    //设置数据模型，且加载到各个视图上面
    m_model = new QFileSystemModel(this);
    QString currPath = QDir::currentPath();  //获取当前路径
    m_model->setRootPath(currPath);          //设置根目录
    ui->treeView->setModel(m_model);         //设置数据模型
    ui->listView->setModel(m_model);
    ui->tableView->setModel(m_model);
    ui->columnView->setModel(m_model);

    //初始化状态栏
    m_labFileName = new QLabel("名称：", ui->statusBar);
    m_labFileName->setMinimumWidth(180);
    m_labFileSize = new QLabel("大小：", ui->statusBar);
    m_labFileSize->setFixedWidth(130);
    m_labFileType = new QLabel("类型：", ui->statusBar);
    m_labFileType->setFixedWidth(130);
    m_labPath = new QLabel("路径：" + currPath, ui->statusBar);
    m_chkBoxIsFile = new QCheckBox("当前为文件夹", ui->statusBar);
    m_chkBoxIsFile->setFixedWidth(130);

    //各种QLable添加到状态栏
    ui->statusBar->addWidget(m_labFileName);
    ui->statusBar->addWidget(m_labFileSize);
    ui->statusBar->addWidget(m_labFileType);
    ui->statusBar->addWidget(m_chkBoxIsFile);
    ui->statusBar->addWidget(m_labPath);
}

//单击treeView，会在状态栏显示当前节点的信息
void ExQFileSystemModel::on_treeView_clicked(const QModelIndex &index)
{
    m_chkBoxIsFile->setChecked(m_model->isDir(index));                //是否是目录
    m_labFileName->setText("名称：" + m_model->fileName(index));      //文件名称
    double size = m_model->size(index) / 1024.0;

    if (size < 1024)
        m_labFileSize->setText("类型：" + QString::number(size, 'f', 2) + "KB");
    else if (1024 <= size && size < 1024 * 1024)
        m_labFileSize->setText("类型：" + QString::number(size / 1024, 'f', 2) + "MB");
    else
        m_labFileSize->setText("类型：" + QString::number(size / (1024 * 1024), 'f', 2) + "GB");

    m_labFileType->setText(m_model->type(index));
    m_labPath->setText(m_model->filePath(index));
}
