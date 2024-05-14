cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

set(PROJECT_NAME lab2) # Создаем обычную локальную переменную с именем проекта.
project(${PROJECT_NAME}) # Название проекта.

# Определяем переменные с именами приложений и библиотек.
set(SKIPLIST SKIPLIST)
set(PRIORETY PRIORETY)
set(TEST TEST)



# Создаем переменную для типов сборки и устанавливаем значения Debug и Release.
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)

# Если не указан тип сборки, устанавливаем Release по умолчанию.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Включаем папку с заголовочными файлами gtest.
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
# Добавляем субдиректорию для сборки gtest.
add_subdirectory(gtest)

# Включаем папки с заголовочными файлами и библиотеками для остальных проектов.
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/PRIORETY
    ${CMAKE_CURRENT_SOURCE_DIR}/SKIPLIST
    ${CMAKE_CURRENT_SOURCE_DIR}/TEST
)

# Добавляем субдиректории для сборки остальных проектов.
add_subdirectory(PRIORETY)
add_subdirectory(SKIPLIST)
add_subdirectory(TEST)
