#ifndef IFMETWINDOW_H
#define IFMETWINDOW_H

#include <QMainWindow>

namespace Ui {
class IfmetWindow;
}

class IfmetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit IfmetWindow(QWidget *parent = nullptr);
    ~IfmetWindow();

private:
    Ui::IfmetWindow *ui;
};

#endif // IFMETWINDOW_H
