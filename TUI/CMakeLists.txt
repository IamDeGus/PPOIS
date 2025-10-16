add_library(TUI STATIC
    tui.cpp
)

target_include_directories(TUI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


find_library(NCURSES_LIB ncurses)
if (NCURSES_LIB)
    target_link_libraries(TUI PRIVATE ${NCURSES_LIB})
else()
    message(WARNING "ncurses not found; you may need to install it or adjust target_link_libraries")
endif()


target_link_libraries(TUI PRIVATE GameLogic)
