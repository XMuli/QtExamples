#include "widget.h"

#include <QApplication>
#include "spdlog/spdlog.h"

#include "spdlog/logger.h"
#include "spdlog/sinks/basic_file_sink.h"

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);

// 方法一: 默认为彩色格式且输出到终端
//    spdlog::info("Welcome to spdlog!");
//    spdlog::error("Some error message with arg: {}", 1);

//    spdlog::warn("Easy padding in numbers like {:08d}", 12);
//    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
//    spdlog::info("Support for floats {:03.2f}", 1.23456);
//    spdlog::info("Positional args are {1} {0}..", "too", "supported");
//    spdlog::info("{:<30}", "left aligned");


// 方法二: 默认格式输出到文本文件
    auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
    logger->flush_on(spdlog::level::debug);  // 遇到 err 级别缓冲区倾倒写入文本
    //spdlog::flush_every(std::chrono::seconds(5));

    logger->info("Welcome to spdlog!");
    logger->error("Some error message with arg: {}", 1);
    logger->warn("Easy padding in numbers like {:08d}", 12);
    logger->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    logger->info("Support for floats {:03.2f}", 1.23456);
    logger->info("Positional args are {1} {0}..", "too", "supported");
    logger->info("{:<30}", "left aligned");
    logger->set_level(spdlog::level::debug); // Set global log level to debug
    logger->debug("This message should be displayed..");

    Widget w;
    w.show();
    return a.exec();
}
