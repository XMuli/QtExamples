cmake_minimum_required(VERSION 3.5)

project(ExPicShot VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories(3rdparty/spdlog/include)  # spdlog 路径，不必再添加链接库

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
)

add_executable(ExPicShot
    ${PROJECT_SOURCES}
)

target_link_libraries(ExPicShot PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(ExPicShot PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

