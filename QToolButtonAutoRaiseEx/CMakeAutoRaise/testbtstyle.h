#ifndef TESTBTSTYLE_H
#define TESTBTSTYLE_H

#include <QWidget>
#include <QVector>
#include <QToolButton>
#include <vector>

class TestBTStyle : public QWidget
{
    Q_OBJECT
public:
    TestBTStyle(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<QToolButton *> m_vItem;
    std::vector<std::pair<QString, bool>> m_vTbName;
};

#endif // TESTBTSTYLE_H
