#ifndef EXQSTRINGLISTMODEL_H
#define EXQSTRINGLISTMODEL_H

#include <QWidget>

namespace Ui {
class ExQStringListModel;
}

class ExQStringListModel : public QWidget
{
    Q_OBJECT

public:
    explicit ExQStringListModel(QWidget *parent = nullptr);
    ~ExQStringListModel();

private:
    Ui::ExQStringListModel *ui;
};

#endif // EXQSTRINGLISTMODEL_H
