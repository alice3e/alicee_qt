cmake_minimum_required(VERSION 3.16)

project(alicee_qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем необходимые модули Qt


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)

# пути ко всем файлам кода
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        lib/qcustomplot.cpp
        lib/qcustomplot.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(alicee_qt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        login_form.h login_form.cpp login_form.ui
    )
else()
    if(ANDROID)
        add_library(alicee_qt SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(alicee_qt
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Связываем проект с модулями Widgets и PrintSupport
target_link_libraries(alicee_qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)
include_directories(${CMAKE_SOURCE_DIR}/lib)


set_target_properties(alicee_qt PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS alicee_qt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(alicee_qt)
endif()
