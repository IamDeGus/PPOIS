#include <UnitTest++/UnitTest++.h>

#include "../../CellProxy/cell_proxy.h"
#include "../../RowProxy/row_proxy.h"

TEST(CellProxy_1) {
    TicTacToe game(3);

    game[0][0] = game.CurrentPlayer(); // x - -
    game[2][0] = game.CurrentPlayer(); // - - -
                                       // o - -

    CellProxy test_cell(game, 2, 0);

    CHECK(test_cell == TicTacToe::Cell::Zero);
}

TEST(CellProxy_2) {
    TicTacToe game(3);

    game[0][0] = game.CurrentPlayer(); // x - -
    game[2][0] = game.CurrentPlayer(); // - - -
                                       // o - -

    CellProxy test_cell(game, 2, 8);

    CHECK_THROW(test_cell = TicTacToe::Cell::Cross, std::out_of_range);
}

TEST(CellProxy_3) {
    TicTacToe game(3);

    CellProxy test_cell(game, 1, 1);
    test_cell = TicTacToe::Cell::Cross;
    
    CHECK(game[1][1] == TicTacToe::Cell::Cross);
}
