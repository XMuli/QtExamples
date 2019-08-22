#ifndef EXQDIALQLCD_H
#define EXQDIALQLCD_H

#include <QWidget>

namespace Ui {
class ExQdialQLCD;
}

class ExQdialQLCD : public QWidget
{
    Q_OBJECT

public:
    explicit ExQdialQLCD(QWidget *parent = nullptr);
    ~ExQdialQLCD();

public slots:
    void onDisplayLCD(int val);

private slots:
    void on_raidBtn2_clicked();

    void on_raidBtn8_clicked();

    void on_raidBtn10_clicked();

    void on_raidBtn16_clicked();

private:
    Ui::ExQdialQLCD *ui;
};

#endif // EXQDIALQLCD_H
