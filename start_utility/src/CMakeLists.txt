cmake_minimum_required(VERSION 2.8)
project(fill_in)

set(SOURCE_EXE main.cpp)    # Установка переменной на main.cpp
set(SOURCE_LIB files_init.cpp  # Установка переменной на библиотеке 
               fill_in.cpp)


add_library(create_project STATIC ${SOURCE_LIB}) # Добавляем статическую библиотеку
add_executable(start ${SOURCE_EXE})     # Создаем exe файл заточенный под определенную систему

target_link_libraries(start create_project)     # Линкуем прогу с либой
