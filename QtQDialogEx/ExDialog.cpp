#include "ExDialog.h"
#include "ui_ExDialog.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>

ExDialog::ExDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExDialog)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("文件、颜色、字体、保存、消息、输入等对话框使用"));
}

ExDialog::~ExDialog()
{
    delete ui;
}

//标准文件对话框QFileDialog+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExDialog::on_btnOpenFile_clicked()
{
    QString path = QDir::currentPath();                        //获取应用程序当前目录
    QString fileter = "文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)";

    QString fileNmae = QFileDialog::getOpenFileName(this, "选择一个文件", path, fileter);
    if (! fileNmae.isEmpty()) {
        ui->plainTextEdit->appendPlainText(fileNmae);
    }
}

void ExDialog::on_btnOpenFiles_clicked()
{
    QString path = QDir::currentPath();                        //获取应用程序当前目录
    QString fileter = "文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)";

    QStringList fileNmaeList = QFileDialog::getOpenFileNames(this, "选择多个文件", path, fileter);
    for (int i = 0; i < fileNmaeList.count(); i++) {
        ui->plainTextEdit->appendPlainText(fileNmaeList.at(i));
    }
}

void ExDialog::on_btnExistingDir_clicked()
{
    QString currPath = QCoreApplication::applicationDirPath(); //获取应用程序当前目录
    QString path = QFileDialog::getExistingDirectory(this, "选择一个目录【非文件】", currPath, QFileDialog::ShowDirsOnly);   //最后一个参数，表示只显示路径

    if (!path.isEmpty()) {
        ui->plainTextEdit->appendPlainText(path);
    }
}

void ExDialog::on_btnGetColor_clicked()
{
    QPalette pal = ui->plainTextEdit->palette();              //获取条调色板
    QColor initColor = pal.color(QPalette::Text);
    QColor color = QColorDialog::getColor(initColor, this, "选择颜色");

    if (color.isValid()) {                                    //因为没有.isEmpty(),故而使用.isValid()来判断
        pal.setColor(QPalette::Text, color);
        ui->plainTextEdit->setPalette(pal);
    }
}

void ExDialog::on_btnGetFont_clicked()
{
    QFont initFont = ui->plainTextEdit->font();
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, initFont);

    if (ok)
        ui->plainTextEdit->setFont(font);
}

void ExDialog::on_btnSaveFile_clicked()
{
    QString path = QDir::currentPath();                        //获取应用程序当前目录
    QString fileter = "头文件(*.h);;源文件(*.cpp);;所有文件(*.*)";
    QString fileNmae = QFileDialog::getSaveFileName(this, "保存文件", path, fileter);

    if (!fileNmae.isEmpty())
        ui->plainTextEdit->appendPlainText(fileNmae);
}

//标准消息对话框+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExDialog::on_btnQuestion_clicked()
{
    QMessageBox::StandardButton ret = QMessageBox::question(this, "问题消息对话框", "question对话框的内容",  QMessageBox::Yes | QMessageBox::No | QMessageBox::Close, QMessageBox::NoButton);

    switch (ret) {
    case QMessageBox::Yes: {
        ui->plainTextEdit->appendPlainText("QMessageBox::yes 按钮被选中");
        break;
    }
    case QMessageBox::No: {
        ui->plainTextEdit->appendPlainText("QMessageBox::No 按钮被选中");
        break;
    }
    case QMessageBox::Close: {
        ui->plainTextEdit->appendPlainText("QMessageBox::Close 按钮被选中");
        break;
    }
    default: {
        ui->plainTextEdit->appendPlainText("这是 switch 的default 的选项");
        break;
    }
    }
}

void ExDialog::on_btnInformation_clicked()
{
    QMessageBox::information(this, "信息消息对话框", "information对话框的内容", QMessageBox::Ok, QMessageBox::NoButton);
}

void ExDialog::on_btnWarning_clicked()
{
    QMessageBox::warning(this, "警告消息对话框", "warning对话框的内容", QMessageBox::Ok, QMessageBox::NoButton);
}

void ExDialog::on_btnCritical_clicked()
{
    QMessageBox::critical(this, "危机消息对话框", "critical对话框的内容", QMessageBox::Ok, QMessageBox::NoButton);
}

void ExDialog::on_btnAbout_clicked()
{
    QMessageBox::about(this, "关于消息对话框", "abou 作者: 投我以木李，报之以琼玖");
}

void ExDialog::on_btnAboutQt_clicked()
{
    QMessageBox::aboutQt(this, "关于Qt消息对话框");
}

//标准输入对话框QInputDialog+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExDialog::on_btnGetString_clicked()
{
    bool ok = false;
    QString text = QInputDialog::getText(this, "输入文字对话框", "请输入一个字符串", QLineEdit::Normal, "默认输入的字符串", &ok);

    if (ok && !text.isEmpty())
        ui->plainTextEdit->appendPlainText(text);
}

void ExDialog::on_btnGetItem_clicked()
{
    QStringList list;
    list<<"2019-10-02"<<"04:28"<<"在武汉的卧室"<<"敲代码"<<"这会没有困意";

    int index = 0;
    bool editable = true;   //ComboBox是否可编辑
    bool ok = false;
    QString text = QInputDialog::getItem(this, "输入item对话框", "请选择一个item", list, index, editable, &ok);

    if (ok && !text.isEmpty())
        ui->plainTextEdit->appendPlainText(text);
}

void ExDialog::on_btnInt_clicked()
{
    int min = 0;
    int max = 100;
    int stepVal = 3;
    int size = ui->plainTextEdit->font().pointSize();
    bool ok = false;
    int val = QInputDialog::getInt(this, "输入整数对话框", "请输入一个整数改变字体大小", size, min, max, stepVal, &ok);

    if (ok) {
        QFont font = ui->plainTextEdit->font();
        font.setPointSize(val);
        ui->plainTextEdit->setFont(font);
        ui->plainTextEdit->appendPlainText("字体大小已经被设置为:" + QString::number(val));
    }
}

void ExDialog::on_btnDouble_clicked()
{
    int min = 0;
    int max = 100;
    int d = 2;                 //小数点的位数
    double val = 3.1415;
    bool ok = false;
    double ret = QInputDialog::getDouble(this, "输入浮点数对话框", "请输入一个整数改变字体大小", d, min, max, val, &ok);

    if (ok)
        ui->plainTextEdit->appendPlainText("浮点数大小为:" + QString::number(ret, 'f', 4));
}
