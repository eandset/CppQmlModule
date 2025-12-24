cmake_minimum_required(VERSION 3.16)
project(SimpleCppModule VERSION 1.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)

# Находим Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Quick Qml)

# Создаем плагин
add_library(simplecppmoduleplugin MODULE
    SimpleCppModulePlugin.cpp
    CppText.cpp
)

# Настраиваем плагин
set_target_properties(simplecppmoduleplugin PROPERTIES
    OUTPUT_NAME "simplecppmoduleplugin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/module"
)

# Подключаем зависимости
target_link_libraries(simplecppmoduleplugin
    PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Qml
)

# Устанавливаем модуль
install(TARGETS simplecppmoduleplugin
    LIBRARY DESTINATION "/usr/lib/qt6/qml/SimpleCppModule"
)

# Устанавливаем qmldir
install(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/qmldir"
    DESTINATION "/usr/lib/qt6/qml/SimpleCppModule"
)

# plugins.qmltypes
install(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/plugins.qmltypes"
    DESTINATION "/usr/lib/qt6/qml/SimpleCppModule"
)
