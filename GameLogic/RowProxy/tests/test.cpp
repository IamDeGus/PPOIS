#include <UnitTest++/UnitTest++.h>

#include "../../RowProxy/row_proxy.h"

TEST(RowProxy_1) {
    TicTacToe game(3);

    game[0][0] = game.CurrentPlayer(); // x - -
    game[2][0] = game.CurrentPlayer(); // - - -
                                       // o - -

    RowProxy test_row(game, 2);

    CHECK(test_row[0] == TicTacToe::Cell::Zero);
    CHECK(test_row[1] == TicTacToe::Cell::Empty);
    CHECK(test_row[2] == TicTacToe::Cell::Empty);
}

TEST(RowProxy_2) {
    TicTacToe game(3);

    RowProxy row(game, 10);

    CHECK_THROW(row[0] = TicTacToe::Cell::Cross, std::out_of_range);
}

TEST(RowProxy_3) {
    TicTacToe game(3);

    RowProxy row(game, 1);
    
    row[2] = TicTacToe::Cell::Cross;
    CHECK(game[1][2] == TicTacToe::Cell::Cross);
}
