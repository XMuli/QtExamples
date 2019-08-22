#include "ExQStringFun.h"
#include "ui_ExQStringFun.h"

ExQStringFun::ExQStringFun(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ExQStringFun)
{
    ui->setupUi(this);

    setWindowTitle(QObject::tr("QString类的一些常用函数"));
}

ExQStringFun::~ExQStringFun()
{
    delete ui;
}

//字符串相关
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ExQStringFun::on_btnAppend_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();
    str1.append(str2);
    ui->editResult->setText(str1);
}

void ExQStringFun::on_btnPrepend_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();
    str1.prepend(str2);
    ui->editResult->setText(str1);
}

void ExQStringFun::on_btnToUpper_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strRet = str1.toUpper();
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnToLower_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strRet = str1.toLower();
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnLeft_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    int n = ui->spinLabSpin->value();
    QString strRet = str1.left(n);
    ui->editResult->setText(strRet);

}

void ExQStringFun::on_btnRight_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    int n = ui->spinLabSpin->value();
    QString strRet = str1.right(n);
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnSection_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();
    int n = ui->spinLabSpin->value();

    QString str3 = str1.section(str2, n, n+1);
    ui->editResult->setText(str3);
}

void ExQStringFun::on_btnSimplified_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strRet = str1.simplified();
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnTrimmed_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strRet = str1.trimmed();
    ui->editResult->setText(strRet);
}

//数字相关
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExQStringFun::on_btnCount_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strRet = QString("count():%1").arg(str1.count());
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnSize_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString strRet = QString("size():%1").arg(str1.size());
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnIndexOf_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();

    QString strRet = QString("IndexOf():%1").arg(str1.indexOf(str2));
    ui->editResult->setText(strRet);
}


void ExQStringFun::on_btnLastIndexOf_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();

    QString strRet = QString("lastIndexOf():%1").arg(str1.lastIndexOf(str2));
    ui->editResult->setText(strRet);
}

//逻辑判断相关
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ExQStringFun::on_btnStartsWith_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();
    QString str3 = "";

    if (str1.startsWith(str2))
        str3 = "str1是以str2字符串开头";
    else
        str3 = "str1不是以str2字符串开头";

    QString strRet = QString("startsWith():%1").arg(str3);
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnEndsWith_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();
    QString str3 = "";

    if (str1.endsWith(str2))
        str3 = "str1是以str2字符串结尾";
    else
        str3 = "str1不是以str2字符串结尾";

    QString strRet = QString("endsWith():%1").arg(str3);
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnContains_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str2 = ui->comboxStr2->currentText();
    QString str3 = "";

    if (str1.contains(str2))
        str3 = "str1字符中包含str2字符串";
    else
        str3 = "str1字符中不包含str2字符串";

    QString strRet = QString("contains():%1").arg(str3);
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnIsNull_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str = "未赋值";

    if(str1.isNull())
        str = "true";
    else
        str = "false";

    QString strRet = QString("str1.isNull() => %1").arg(str);
    ui->editResult->setText(strRet);
}

void ExQStringFun::on_btnIsEmpty_clicked()
{
    QString str1 = ui->comboxStr1->currentText();
    QString str = "未赋值";

    if(str1.isNull())
        str = "true";
    else
        str = "false";

    QString strRet = QString("str1.isEmpty() => %1").arg(str);
    ui->editResult->setText(strRet);
}
