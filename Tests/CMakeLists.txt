file(GLOB_RECURSE GAMELOGIC_TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/GameLogic/*/tests/test.cpp
)

add_executable(run_tests
    ${CMAKE_SOURCE_DIR}/Tests/test_runner.cpp
    ${GAMELOGIC_TEST_SOURCES}
)


target_include_directories(run_tests PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/GameLogic
)

target_link_libraries(run_tests PRIVATE GameLogic)


target_include_directories(run_tests PRIVATE /usr/include)
target_link_libraries(run_tests PRIVATE /usr/lib/libUnitTest++.a)
