# src/CMakeLists.txt

# Находим ВСЕ .cpp файлы рекурсивно
file(GLOB_RECURSE SOURCE_FILES 
    "*.cpp" 
    "*.cxx" 
    "*.cc"
)

# Выводим список найденных файлов (для отладки)
# message(STATUS "Found source files: ${SOURCE_FILES}")

# Создаем библиотеку
add_library(CookingLib ${SOURCE_FILES})

# Добавляем текущую директорию и все поддиректории в include path
target_include_directories(CookingLib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Включаем все поддиректории тоже
target_include_directories(CookingLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Common
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Exeptions
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/GetSomething
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/I
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/Address
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/Certification
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/Company
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/CookingBookDescription
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/Date
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/Gender
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/Grade    
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/Health
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/KitchenDescription
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/KitchenUnitDescription
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/PersonDescription
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/PersonMetaData
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/RecipeDescription
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/Size
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/StateOfPurity
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/Temperature
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Types/Weight
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Vector/Converter
    ${CMAKE_CURRENT_SOURCE_DIR}/Cooking
    ${CMAKE_CURRENT_SOURCE_DIR}/Recipe
    ${CMAKE_CURRENT_SOURCE_DIR}/Recipe/Step
    ${CMAKE_CURRENT_SOURCE_DIR}/Ingredient
    ${CMAKE_CURRENT_SOURCE_DIR}/Kitchen
    ${CMAKE_CURRENT_SOURCE_DIR}/Person
    ${CMAKE_CURRENT_SOURCE_DIR}/Supplier
    ${CMAKE_CURRENT_SOURCE_DIR}/KitchenUnit
    ${CMAKE_CURRENT_SOURCE_DIR}/KitchenUnit/CookUnit
    ${CMAKE_CURRENT_SOURCE_DIR}/KitchenUnit/StorageUnit
    ${CMAKE_CURRENT_SOURCE_DIR}/KitchenUnit/OtherUnit
    ${CMAKE_CURRENT_SOURCE_DIR}/Tool
    ${CMAKE_CURRENT_SOURCE_DIR}/Utensil
)

if(CODE_COVERAGE)
    target_compile_options(CookingLib PRIVATE --coverage -g)
    target_link_options(CookingLib PRIVATE --coverage)
endif()
