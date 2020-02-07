#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QWidget>

class Example : public QWidget
{
    Q_OBJECT

public:
    Example(QWidget *parent = nullptr);
    ~Example();
};
#endif // EXAMPLE_H
