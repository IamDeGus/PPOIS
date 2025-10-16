/**
 * @file cell_proxy.h
 * @author DeGus
 * 
 * @brief Прокси-класс для обращения к отдельной ячейке поля TicTacToe.
 * 
 * @version 0.1
 * @date 2025-10-16
 * 
 * @copyright Copyright (c) 2025
 *
 * 
 * @see TicTacToe
 * @see RowProxy
 */

#pragma once

#include "../TicTacToe/tic_tac_toe.h"


/**
 * @class CellProxy
 * @brief Прокси-класс для обращения к отдельной ячейке поля TicTacToe.
 *
 * @details 
 * Позволяет получать и изменять значение ячейки с помощью операторов
 * приведения и присваивания.
 */
class CellProxy{
public:
    /**
     * @brief Конструктор CellProxy.
     * @param game Ссылка на игру TicTacToe.
     * @param row Индекс строки ячейки (0-based).
     * @param col Индекс столбца ячейки (0-based).
     */
    CellProxy(TicTacToe& game, int row, int col);

    /**
     * @brief Неявное преобразование в значение ячейки.
     * @return Текущее состояние ячейки (Cross, Zero или Empty).
     */
    operator TicTacToe::Cell() const;

    /**
     * @brief Присваивание значения ячейке.
     * @param value Новое значение ячейки.
     * @return Ссылка на изменённую ячейку.
     */
    TicTacToe::Cell& operator = (TicTacToe::Cell value);

private:
    TicTacToe& game; ///< Ссылка на объект игры.
    int row;         ///< Индекс строки.
    int col;         ///< Индекс столбца.
};
