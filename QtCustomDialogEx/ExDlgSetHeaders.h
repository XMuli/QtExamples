#ifndef EXDLGSETHEADERS_H
#define EXDLGSETHEADERS_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class ExDlgSetHeaders;
}

class ExDlgSetHeaders : public QDialog
{
    Q_OBJECT

public:
    explicit ExDlgSetHeaders(QWidget *parent = nullptr);
    ~ExDlgSetHeaders();

    void setHeaderList(QStringList& headers);
    QStringList headerList();

private:
    Ui::ExDlgSetHeaders *ui;

    QStringListModel *m_model;          //管理字符串列表数据
};

#endif // EXDLGSETHEADERS_H
