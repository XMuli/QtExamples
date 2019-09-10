#include "Examples.h"
#include "ui_Examples.h"

CUSTOMSTYLE_USE_NAMESPACE

Examples::Examples(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Examples)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("创建自定义的CustomStyle风格"));

    init();
}

Examples::~Examples()
{
    delete ui;
}

//获取当前系统支持的默认系统风格
void Examples::init()
{
    //当前系统支持的系统风格,放入QcomboBox的item里面,且打印出来
    QStringList listStyle = QStyleFactory::keys();
    foreach(QString val, listStyle) {
        ui->comboBox->addItem(val);
        qDebug()<<val;
    }

    //设置一个默认的风格
    ui->comboBox->addItem("ExCustomStyle");
//    qApp->setStyle(QStyleFactory::create("Fusion"));
    qApp->setStyle(new ExCustomStyle());
}


void Examples::on_comboBox_currentIndexChanged(const QString &style)
{
//    qDebug()<<"当前选中的风格:"<<style;
    //当前选中item项为系统预支持的风格
    QStringList listStyle = QStyleFactory::keys();
    foreach(QString val, listStyle) {
        if (style == val) {
            qApp->setStyle(QStyleFactory::create(style));
            return;
        }
    }

    //不属于系统风格,则使用自己的风格
    ExCustomStyle* customStyle = new ExCustomStyle;
    qApp->setStyle(customStyle);

}
