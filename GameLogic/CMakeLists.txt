add_library(GameLogic STATIC)

target_sources(GameLogic PRIVATE
    TicTacToe/tic_tac_toe.cpp
    RowProxy/row_proxy.cpp
    CellProxy/cell_proxy.cpp
)

target_include_directories(GameLogic
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(GameLogic PUBLIC cxx_std_20)
