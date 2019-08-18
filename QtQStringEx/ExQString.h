#ifndef EXQSTRING_H
#define EXQSTRING_H

#include <QWidget>

namespace Ui {
class ExQString;
}

class ExQString : public QWidget
{
    Q_OBJECT

public:
    explicit ExQString(QWidget *parent = nullptr);
    ~ExQString();

private slots:
    void on_btnResult_clicked();
    void on_btn2_clicked();
    void on_btn8_clicked();
    void on_btn10_clicked();
    void on_btn16_clicked();

private:
    Ui::ExQString *ui;

    float m_val;
};

#endif // EXQSTRING_H
