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
        ctName,
        ctSex,
        ctBirth,
        ctNation,
        ctScore,
        ctLikeAnime
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
    void on_btnSetHeader_clicked();

    void on_btnInitTable_clicked();

    void on_btnSetRow_clicked();

    void on_btnInsertRow_clicked();

    void on_btnAddRow_clicked();

    void on_btnDelRow_clicked();

    void on_btnAutoHeight_clicked();

    void on_btnAutoWidth_clicked();

    void on_btnReadToEdit_clicked();

    void on_chkBoxHeadEdit_clicked(bool checked);

    void on_chkBoxRowColor_clicked(bool checked);

    void on_chkBoxHeadRow_clicked(bool checked);

    void on_chkBoxHeadCol_clicked(bool checked);

    void on_radioBtnSelectItem_clicked();

    void on_radioBtnSelectRow_clicked();

    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

private:
    Ui::ExQTableWidget *ui;

    QLabel *m_labCellIndex;                              //状态栏上用来显示单元格的行号、列号
    QLabel *m_labCellType;                               //状态栏上用来显示单元格的type
    QLabel *m_labStudID;                                 //状态栏上用来显示单元格的学号
};

#endif // EXQTABLEWIDGET_H
