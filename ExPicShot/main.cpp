#include "widget.h"

#include <QApplication>
#include "spdlog/spdlog.h"

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    Widget w;
    w.show();
    return a.exec();
}
