#include "ExQcomboBox.h"
#include "ui_ExQcomboBox.h"

#include <QMap>
#include <QTextBlock>
#include <QDebug>

ExQcomboBox::ExQcomboBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExQcomboBox)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("QComboBox和QPlainTextEdit的用法"));

    connect(ui->comBoxRight, &QComboBox::currentTextChanged, this, &ExQcomboBox::onSelectDisplay);
}

ExQcomboBox::~ExQcomboBox()
{
    delete ui;
}


//左上角区域+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//初始化简单的QComboBox控件
void ExQcomboBox::on_btnLeftInit_clicked()
{
    QIcon ico;
    ico.addFile(":/images/github.ico");

    ui->comBoxLeft->clear();
    for (int i = 0; i < 13; i++) {
        ui->comBoxLeft->addItem(ico, QString("第%1个item项").arg(i));   //带有ico图标的项
    }
}

//清除简单的QComboBox控件
void ExQcomboBox::on_btnLeftClear_clicked()
{
    ui->comBoxLeft->clear();
}

//勾选QComboBox为可以编辑状态
void ExQcomboBox::on_checkBoxOnlyWrite_clicked()
{
    if(ui->checkBoxOnlyWrite->isChecked())
        ui->comBoxLeft->setEditable(true);
    else
        ui->comBoxLeft->setEditable(false);
}

//右上角区域+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//初始化复杂的QComboBox控件（给每一项都添加一个对应的自定义数据[不显示]）
void ExQcomboBox::on_btnRightInit_clicked()
{
    QIcon ico;
    ico.addFile(":/images/gril.ico");

    QMap<QString, QString> map;
    map.insert("张投", "16岁");
    map.insert("张我", "17岁");
    map.insert("张以", "18岁");
    map.insert("张木", "19岁");
    map.insert("张李", "20岁");
    map.insert("张，", "21岁");
    map.insert("张报", "22岁");
    map.insert("张之", "23岁");
    map.insert("张以", "24岁");
    map.insert("张琼", "25岁");
    map.insert("张玖", "26岁");
    map.insert("张。", "27岁");

    ui->comBoxRight->clear();
    foreach(QString str, map.keys()){
        ui->comBoxRight->addItem(ico, str, map.value(str));           //因为有Map，所以QComboBox显示会按照key排序，而非上面的定义顺序,注意不是map.key(str)
    }
}

//底部区域+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//文本框内容每次读取一行，添加到ComboBox作为item项
void ExQcomboBox::on_btnBottomAdd_clicked()
{
    QTextDocument* doc = ui->plainTextEdit->document();               //获取文本对象
    int cnt = doc->blockCount();                                      //回车符是一个block
    QIcon ico;
    ico.addFile(":/images/github.ico");
    ui->comBoxLeft->clear();
    ui->comBoxRight->clear();

    for (int i = 0; i < cnt; i++) {
        QTextBlock text = doc->findBlockByNumber(i);                  //获取文本中一段（以换行为标志）
        ui->comBoxLeft->addItem(ico, text.text());
        ui->comBoxRight->addItem(ico, text.text(), QString("附加内容:%1").arg(i));
    }
}

//清除可编辑的富文本的编辑器的所有内容
void ExQcomboBox::on_btnBottomClear_clicked()
{
    ui->plainTextEdit->clear();
}

//设置富文本的编辑器(plainTextEdit)只可读
void ExQcomboBox::on_checkBoxOnlyRead_clicked()
{
    if(ui->checkBoxOnlyRead->isChecked())
        ui->plainTextEdit->setEnabled(false);
    else
        ui->plainTextEdit->setEnabled(true);
}


//公共的槽函数区域+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//显示当前选中的ComboBox的item项的内容
void ExQcomboBox::onSelectDisplay(QString str)
{
    QString strData = ui->comBoxRight->currentData().toString();     // 获取当前item的关联数据的内容
    ui->labDisplay->setText(str + "  " + strData);
    ui->plainTextEdit->appendPlainText(str + "  " + strData);
}
