#ifndef EXQSTRINGFUN_H
#define EXQSTRINGFUN_H

#include <QWidget>

namespace Ui {
class ExQStringFun;
}

class ExQStringFun : public QWidget
{
    Q_OBJECT

public:
    explicit ExQStringFun(QWidget *parent = nullptr);
    ~ExQStringFun();

private slots:
    void on_btnAppend_clicked();

    void on_btnPrepend_clicked();

    void on_btnToUpper_clicked();

    void on_btnToLower_clicked();

    void on_btnLeft_clicked();

    void on_btnRight_clicked();

    void on_btnSection_clicked();

    void on_btnSimplified_clicked();

    void on_btnTrimmed_clicked();

    void on_btnCount_clicked();

    void on_btnSize_clicked();

    void on_btnIndexOf_clicked();


    void on_btnLastIndexOf_clicked();

    void on_btnStartsWith_clicked();

    void on_btnEndsWith_clicked();

    void on_btnContains_clicked();

    void on_btnIsNull_clicked();

    void on_btnIsEmpty_clicked();

private:
    Ui::ExQStringFun *ui;
};

#endif // EXQSTRINGFUN_H
