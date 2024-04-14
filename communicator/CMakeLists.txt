cmake_minimum_required(VERSION 3.16)

project(communicator VERSION 1.0 LANGUAGES CXX)

find_package(Qt6 6.2 COMPONENTS Quick Gui REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

qt_add_executable(communicator
    main.cpp
)

qt_add_qml_module(communicator
    URI main
    QML_FILES
        main-window.qml
    RESOURCES resources.qrc
)

target_link_libraries(communicator PRIVATE Qt6::Gui Qt6::Quick)
