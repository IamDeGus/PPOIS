
#include "cell_proxy.h"

#include <stdexcept>


CellProxy::CellProxy(TicTacToe& game, int row, int col) :
    game(game), row(row), col(col) {}

CellProxy::operator TicTacToe::Cell() const{
    if (!game.IsInside(row, col))
        throw std::out_of_range("index");
    
    return game.table[row][col];
}

TicTacToe::Cell& CellProxy::operator = (TicTacToe::Cell value){
    if (!game.IsInside(row, col))
        throw std::out_of_range("index");

    if (game.CanPlace(row, col)){

        game.table[row][col] = value;

        game.WinnerUpd(row, col);

        if (value == TicTacToe::Cell::Cross)
            game.currentPlayer = TicTacToe::Cell::Zero;
        if (value == TicTacToe::Cell::Zero)
            game.currentPlayer = TicTacToe::Cell::Cross;

        game.emptyCells--;

    }
    
    return game.table[row][col];
        
}
