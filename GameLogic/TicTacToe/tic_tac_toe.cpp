#include "tic_tac_toe.h"
#include "../RowProxy/row_proxy.h"
#include "../CellProxy/cell_proxy.h"

#include <stdexcept>

using namespace std;


TicTacToe::TicTacToe(const int size){
    if (size < 3)
        throw invalid_argument("Size must be >= 3");
    
    this->size = size;
    table.resize(size, vector<Cell>(size, Cell::Empty));
    emptyCells = size * size;
}

int TicTacToe::GetEmptyCells() const{
    return emptyCells;
}


bool TicTacToe::CanPlace(int row, int col) const{
    return IsInside(row, col) &&
           (Cell::Empty == winner) &&
           (Cell::Empty == table[row][col]);
}

TicTacToe::Cell TicTacToe::WhoWinner() const{
    return winner;
}

TicTacToe::Cell TicTacToe::CurrentPlayer() const{
    return currentPlayer;
}

bool TicTacToe::IsInside(int row, int col) const{
    return (row < size && row >= 0) &&
           (col < size && col >= 0);
}


void TicTacToe::WinnerUpd(int row, int col){
    int total[4] = {0, 0, 0, 0};

    for(int i{-2}; i <= 2; i++){

        if (i == 0) continue;

        // диагональ с левого верхнего угла
        if (IsInside(row + i, col + i)){
            if (table[row + i][col + i] == currentPlayer)
                total[0]++;
            else
                total[0] = 0;
        }

        // диагональ с правого верхнего угла
        if (IsInside(row + i, col - i)){
            if (table[row + i][col - i] == currentPlayer)
                total[1]++;
            else
                total[1] = 0;
        }

        // вертикаль
        if (IsInside(row + i, col)){
            if (table[row + i][col] == currentPlayer)
                total[2]++;
            else
                total[2] = 0;
        }

        // ujhbpjynfk,
        if (IsInside(row, col + i)){
            if (table[row][col + i] == currentPlayer)
                total[3]++;
            else
                total[3] = 0;
        }


        for (int j{0}; j < 4; j++){
            if (total[j] == 2){
                winner = currentPlayer;
                currentPlayer = Cell::Empty;
                return;
            }
        }

    }
}


RowProxy TicTacToe::operator[](int row) {
    if (row < 0 || row >= size)
        throw std::out_of_range("row");
    return RowProxy(*this, row);
}

const std::vector<TicTacToe::Cell>& TicTacToe::operator[](int row) const {
    if (row < 0 || row >= size)
        throw std::out_of_range("row");
    return table[row];
}
