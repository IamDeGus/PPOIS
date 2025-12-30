# tests/CMakeLists.txt

# Ищем UnitTest++
find_package(UnitTest++ REQUIRED)

# Рекурсивно находим ВСЕ тестовые файлы
file(GLOB_RECURSE TEST_SOURCES "*.cpp")

# Создаем исполняемый файл для тестов
add_executable(runTests
    ${TEST_SOURCES}
)

# Связываем с нашей библиотекой и UnitTest++
target_link_libraries(runTests
    CookingLib           # Библиотека из src/
    /usr/lib/libUnitTest++.a
)

# Добавляем пути к заголовкам
target_include_directories(runTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}           # Для main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src    # Для исходного кода проекта
)

# Цель для запуска тестов
add_custom_target(test
    COMMAND runTests
    DEPENDS runTests
    COMMENT "Running unit tests..."
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

if(CODE_COVERAGE)
    # Вариант A: Полностью отключить coverage для тестов
    # set_source_files_properties(
    #     ${TEST_SOURCES}
    #     PROPERTIES
    #     COMPILE_FLAGS "-fno-profile-arcs -fno-test-coverage"
    # )

    target_link_options(runTests PRIVATE --coverage)
    target_compile_options(runTests PRIVATE
        -fno-profile-arcs
        -fno-test-coverage
    ) 
    
    # ИЛИ Вариант B: Просто пометить как тесты
    # (gcovr может фильтровать по директории)
endif()
