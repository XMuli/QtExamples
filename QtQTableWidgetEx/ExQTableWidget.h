#ifndef EXQTABLEWIDGET_H
#define EXQTABLEWIDGET_H

#include <QMainWindow>
#include <QLabel>
#include <QTime>

namespace Ui {
class ExQTableWidget;
}

class ExQTableWidget : public QMainWindow
{
    Q_OBJECT

private:
    enum cellType {                                       //自定义表格单元格TYPE的类型,创建item时使用
        ctName,                                           //姓名
        ctSex,                                            //性别
        ctBirth,                                          //出生日期
        ctNation,                                         //籍贯
        ctScore,                                          //分数
        ctLikeAnime                                       //是否喜欢二次元
    };

    enum fieldColNum {                                    //自定义各个表段在表格中的列号
        colName,
        colSex,
        colBirth,
        colNation,
        colScore,
        colLikeAnime
    };

public:
    explicit ExQTableWidget(QWidget *parent = nullptr);
    ~ExQTableWidget();

    void createItemsARow(int row, QString name, QString sex, QDate birth, QString nation, int score, bool isAnime);   //为某一行创建items

private slots:
    void on_btnSetHeader_clicked();                      //设置表头
    void on_btnInitTable_clicked();                      //初始化数据表
    void on_btnSetRow_clicked();                         //设置表格的行数
    void on_btnInsertRow_clicked();                      //插入行
    void on_btnAddRow_clicked();                         //在最后一行添加一行
    void on_btnDelRow_clicked();                         //删除当前行
    void on_btnAutoHeight_clicked();                     //自动设置行高
    void on_btnAutoWidth_clicked();                      //自动设置列高
    void on_btnReadToEdit_clicked();                     //读取表格内容到文本
    void on_chkBoxHeadEdit_clicked(bool checked);        //表格可编辑模式
    void on_chkBoxRowColor_clicked(bool checked);        //间隔行底色
    void on_chkBoxHeadRow_clicked(bool checked);         //显示行表头
    void on_chkBoxHeadCol_clicked(bool checked);         //显示列表头
    void on_radioBtnSelectItem_clicked();                //单元格选择
    void on_radioBtnSelectRow_clicked();                 //行选择
    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);  //获取当前item和前一个(点击)item的行列号

private:
    Ui::ExQTableWidget *ui;

    QLabel *m_labCellIndex;                              //状态栏上用来显示单元格的行号、列号
    QLabel *m_labCellType;                               //状态栏上用来显示单元格的type
    QLabel *m_labStudID;                                 //状态栏上用来显示单元格的学号
};

#endif // EXQTABLEWIDGET_H
