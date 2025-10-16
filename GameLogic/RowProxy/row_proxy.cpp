#include "row_proxy.h"

RowProxy::RowProxy(TicTacToe& game, int row) : 
    game(game), row(row) {}

CellProxy RowProxy::operator[](int col){
    return CellProxy(game, row, col);
}
