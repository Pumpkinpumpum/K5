# Минимальная версия CMake, необходимая для этого проекта
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(TaskManager)

# Установим стандарт C++ (например, C++17)
set(CMAKE_CXX_STANDARD 17)

# Добавляем исполняемый файл
add_executable(upravlenie_zadachami
    main.cpp
    Task.cpp
    TaskList.cpp
)

# Если необходимо, добавьте дополнительные флаги компилятора
# например, для отладки
# set(CMAKE_CXX_FLAGS_DEBUG "-g")