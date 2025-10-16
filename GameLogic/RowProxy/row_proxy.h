/**
 * @file row_proxy.h
 * @author DeGus
 * 
 * @brief  Прокси-класс для доступа к строке игрового поля TicTacToe.
 * 
 * @version 0.1
 * @date 2025-10-16
 * 
 * @copyright Copyright (c) 2025
 * 
 * @see TicTacToe
 * @see CellProxy
 */

#pragma once

#include "../TicTacToe/tic_tac_toe.h"
#include "../CellProxy/cell_proxy.h"


/**
 * @class RowProxy
 * @brief Прокси-класс для доступа к строке игрового поля TicTacToe.
 *
 * @details 
 * Позволяет обращаться к ячейкам строки по индексу с помощью оператора [].
 * Пример:
 * @code
 * RowProxy row(game, 1);
 * row[2] = TicTacToe::Cell::X;
 * @endcode
 */
class RowProxy{
public:

    /**
     * @brief Конструктор RowProxy.
     * @param game Ссылка на игру TicTacToe.
     * @param row Индекс строки (0-based).
     */
    RowProxy(TicTacToe& game, int row);

    /**
     * @brief Доступ к ячейке по индексу столбца.
     * @param col Индекс столбца (0-based).
     * @return Объект CellProxy, представляющий конкретную ячейку.
     */
    CellProxy operator[](int col);

private:
    TicTacToe& game; ///< Ссылка на объект игры.
    int row;         ///< Индекс строки.
};


