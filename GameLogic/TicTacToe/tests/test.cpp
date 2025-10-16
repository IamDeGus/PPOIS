#include <UnitTest++/UnitTest++.h>

#include "../tic_tac_toe.h"
#include "../../RowProxy/row_proxy.h"

TEST(TicTacToe_BasicRule_1) {
    TicTacToe game(3);
    CHECK(TicTacToe::Cell::Cross == game.CurrentPlayer());
}

TEST(TicTacToe_BasicRule_2) {
    TicTacToe game(3);
    CHECK(TicTacToe::Cell::Empty == game.WhoWinner());
}

TEST(TicTacToe_BasicRule_3) {
    TicTacToe game(26);
    CHECK(TicTacToe::Cell::Cross == game.CurrentPlayer());
}

TEST(TicTacToe_BasicRule_4) {
    TicTacToe game(26);
    CHECK(TicTacToe::Cell::Empty == game.WhoWinner());
}


TEST(TicTacToe_Init_1) {
    TicTacToe game(3);
    CHECK_EQUAL(9, game.GetEmptyCells());
}

TEST(TicTacToe_Init_2) {
    TicTacToe game(4);
    CHECK_EQUAL(16, game.GetEmptyCells());
}

TEST(TicTacToe_Init_3) {
    TicTacToe game(5);
    CHECK_EQUAL(25, game.GetEmptyCells());
}

TEST(TicTacToe_Init_4) {
    TicTacToe game(17);
    CHECK_EQUAL(289, game.GetEmptyCells());
}

TEST(TicTacToe_Bad_Init_1) {
    CHECK_THROW(TicTacToe game(1), std::invalid_argument);
}

TEST(TicTacToe_Bad_Init_2) {
    CHECK_THROW(TicTacToe game(-5), std::invalid_argument);
}


TEST(TicTacToe_CanPlace_1) {
    TicTacToe game(3);

    for(int r{0}; r < 3; r++){
        for(int c{0}; c < 3; c++){
            CHECK_EQUAL(game.CanPlace(r, c), true);
        }
    }
}

TEST(TicTacToe_CanPlace_2) {
    TicTacToe game(3);

    game[0][0] = TicTacToe::Cell::Cross;

    CHECK_EQUAL(game.CanPlace(0, 0), false);

    for(int r{1}; r < 3; r++){
        for(int c{0}; c < 3; c++){
            CHECK_EQUAL(game.CanPlace(r, c), true);
        }
    }

    for (int c{1}; c < 3; c++)
        CHECK_EQUAL(game.CanPlace(0, c), true);
}

TEST(TicTacToe_CanPlace_3) {
    TicTacToe game(3);

    CHECK_EQUAL(game.CanPlace(-1, 0), false);
    CHECK_EQUAL(game.CanPlace(3, 3), false);
    CHECK_EQUAL(game.CanPlace(0, 71), false);
    CHECK_EQUAL(game.CanPlace(3, -2), false);
}


TEST(TicTacToe_CanPlace_4) {
    TicTacToe game(3);

    game[0][0] = game.CurrentPlayer(); // x o o
    game[1][0] = game.CurrentPlayer(); // x - -
    game[0][1] = game.CurrentPlayer(); // x - -
    game[2][0] = game.CurrentPlayer();
    game[0][2] = game.CurrentPlayer();

    for(int r{0}; r < 3; r++){
        for(int c{0}; c < 3; c++){
            CHECK_EQUAL(game.CanPlace(r, c), false);
        }
    }
}

TEST(TicTacToe_EditCell_1){
    TicTacToe game(3);

    game[0][0] = game.CurrentPlayer();
    game[0][0] = game.CurrentPlayer();

    CHECK(TicTacToe::Cell::Cross == game[0][0]);
}

TEST(TicTacToe_CurrentPlayer_1) {
    TicTacToe game(3);

    game[0][0] = game.CurrentPlayer();

    CHECK(TicTacToe::Cell::Zero == game.CurrentPlayer());
}

TEST(TicTacToe_CurrentPlayer_2) {
    TicTacToe game(3);

    game[0][0] = game.CurrentPlayer();
    game[1][0] = game.CurrentPlayer();

    CHECK(TicTacToe::Cell::Cross == game.CurrentPlayer());
}

TEST(TicTacToe_CurrentPlayer_3) {
    TicTacToe game(3);

    game[0][0] = game.CurrentPlayer();
    game[0][0] = game.CurrentPlayer();

    CHECK(TicTacToe::Cell::Zero == game.CurrentPlayer());
}


TEST(TicTacToe_Winner_1) {
    TicTacToe game(3);

    game[0][0] = game.CurrentPlayer(); // x x o
    game[1][0] = game.CurrentPlayer(); // o o x
    game[0][1] = game.CurrentPlayer(); // x o x
    game[1][1] = game.CurrentPlayer();
    game[2][0] = game.CurrentPlayer();
    game[0][2] = game.CurrentPlayer();
    game[1][2] = game.CurrentPlayer();
    game[2][1] = game.CurrentPlayer();
    game[2][2] = game.CurrentPlayer();

    CHECK(TicTacToe::Cell::Empty == game.WhoWinner());
}

TEST(TicTacToe_Winner_2) {
    TicTacToe game(3);

    game[0][0] = game.CurrentPlayer(); // x x x
    game[1][0] = game.CurrentPlayer(); // o - -
    game[0][1] = game.CurrentPlayer(); // o - -
    game[2][0] = game.CurrentPlayer();
    game[0][2] = game.CurrentPlayer();

    CHECK(TicTacToe::Cell::Cross == game.WhoWinner());
}

TEST(TicTacToe_Winner_3) {
    TicTacToe game(3);

    game[1][1] = game.CurrentPlayer(); // o x x
    game[0][0] = game.CurrentPlayer(); // o x -
    game[0][1] = game.CurrentPlayer(); // o - -
    game[1][0] = game.CurrentPlayer();
    game[0][2] = game.CurrentPlayer();
    game[2][0] = game.CurrentPlayer();

    CHECK(TicTacToe::Cell::Zero == game.WhoWinner());
}

TEST(TicTacToe_Winner_4) {
    TicTacToe game(3);

    game[1][1] = game.CurrentPlayer(); // - o x
    game[0][1] = game.CurrentPlayer(); // o x -
    game[0][2] = game.CurrentPlayer(); // x - -
    game[1][0] = game.CurrentPlayer();
    game[2][0] = game.CurrentPlayer();

    CHECK(TicTacToe::Cell::Cross == game.WhoWinner());
}

TEST(TicTacToe_Winner_5) {
    TicTacToe game(3);

    game[1][1] = game.CurrentPlayer(); // x o -
    game[0][1] = game.CurrentPlayer(); // o x -
    game[0][0] = game.CurrentPlayer(); // - - x
    game[1][0] = game.CurrentPlayer();
    game[2][2] = game.CurrentPlayer();

    CHECK(TicTacToe::Cell::Cross == game.WhoWinner());
}

TEST(TicTacToe_EmptyCells_1) {
    TicTacToe game(3);

    game[1][1] = game.CurrentPlayer();

    CHECK_EQUAL(game.GetEmptyCells(), 8);
}

TEST(TicTacToe_EmptyCells_2) {
    TicTacToe game(3);

    game[1][1] = game.CurrentPlayer();
    game[1][1] = game.CurrentPlayer();

    CHECK_EQUAL(game.GetEmptyCells(), 8);
}
