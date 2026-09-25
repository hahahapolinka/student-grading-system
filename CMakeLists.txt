cmake_minimum_required(VERSION 3.14)
project(students_grade_system LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Все исходники и заголовки лежат в одной папке (плоская структура учебного приложения).
file(GLOB SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(students ${SOURCES})

# Заголовки рядом с исходниками; явно указываем корень, чтобы сборка из build/
# не зависела от тонкостей поиска include по умолчанию.
target_include_directories(students PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
