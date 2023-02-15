#include "testbtstyle.h"
#include "QtGui/qpainter.h"
#include <QHBoxLayout>
#include <QDir>
#include <QDebug>
#include <QFileInfo>

TestBTStyle::TestBTStyle(QWidget *parent)
{

//    QString filePath = "/Users/winks/Desktop/projects/QtExamples/QToolButtonAutoRaiseEx/CMakeAutoRaise/icons/normal";
//    QString filePath = "/Users/winks/Desktop/projects/QtExamples/QToolButtonAutoRaiseEx/CMakeAutoRaise/icons/tool";
    QString filePath = "D:/projects/QtExamples/QToolButtonAutoRaiseEx/CMakeAutoRaise/icons/normal";
    QDir *dir=new QDir(filePath);
    QStringList filter;
    QList<QFileInfo> *fileInfo=new QList<QFileInfo>(dir->entryInfoList(filter));
//    for(int i = 0;i<fileInfo->count(); i++)
//    {
//        qDebug()<<fileInfo->at(i).filePath();
//        qDebug()<<fileInfo->at(i).fileName();
//    }


    auto layout = new QHBoxLayout(this);
    QStringList listName;
    for(int i = 0;i<fileInfo->count(); i++)
    {
        if (fileInfo->at(i).fileName() == "." || fileInfo->at(i).fileName() == "..")
            continue;

        listName << fileInfo->at(i).fileName();
    }

//    Link: https://www.cnblogs.com/liming19680104/p/13929838.html
//    16)、border-style        类型：Border Style
//    边框边界线的样式(虚线、实线、点划线等)，默认为 none
//    以下类支持此属性：
//    QAbstractItemView 子类，QAbstractSpinBox 子类，QCheckBox，QComboBox，QFrame，QGroupBox，
//    QLabel，QPushButton，QRadioButton，QSplitter，QTextEdit，QToolTip，QLineEdit，QMenu，
//    QMenuBar(注意：没有 QDialog 和 QWidget)

//    边框样式种类：
//    solid 实线
//    dotted 点状边框
//    none无边框
//    dashed 虚线
//    double 双线
//    groove 定义3D凹槽边框。其效果取决于border-color的值
//    ridge 定义3D垄状边框。其效果取决于 border-color的值
//    inset 定义3D inset边框。其效果取决于 border-color的值
//    outset 定义3D outset边框。其效果取决于 border-color的值
    const int width = 24;
    for (const auto &it : listName){
        auto tb = new QToolButton();
        tb->setStyleSheet("border-style:none");
        tb->setObjectName(it);
        tb->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tb->setAutoRaise(true);
        tb->setIcon(QIcon(":/icons/normal/" + it));
//        tb->setIcon(QIcon(":/icons/tool/" + it));
        tb->setIconSize(QSize(width, width) * 2);
        tb->setContentsMargins(0, 0, 0, 0);
        tb->setFixedSize(QSize(width, width) * 2);
        tb->setToolTip(it);
        tb->setChecked(false);
        tb->setCheckable(true);

        layout->addWidget(tb);
    }

}

void TestBTStyle::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter pa(this);
    pa.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    pa.setPen(Qt::NoPen);
    pa.setBrush(QColor(255, 255, 255, 0.7 * 255));

    const int round = 4;
    pa.drawRoundedRect(contentsRect().adjusted(1, 1, -1, -1), round, round);
}
