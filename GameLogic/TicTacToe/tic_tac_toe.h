/**
 * @file tic_tac_toe.h
 * @author DeGus
 * 
 * @brief Основной класс логики игры «Крестики-нолики».
 * 
 * @version 0.1
 * @date 2025-10-16
 * 
 * @details
 * Класс реализует базовую механику игры в крестики-нолики.Он создаёт 
 * квадратное поле заданного размера, управляет текущим игроком,
 * отслеживает корректность хода, проверяет победу и количество оставшихся
 * свободных ячеек.  
 * 
 * Взаимодействие с полем осуществляется через прокси-классы
 * [RowProxy](@ref RowProxy) и [CellProxy](@ref CellProxy),
 * которые обеспечивают удобный синтаксис доступа.
 * 
 * @copyright Copyright (c) 2025
 * 
 * @see RowProxy
 * @see CellProxy
 */



#pragma once

#include <vector>


class RowProxy;
class CellProxy;


/**
 * @class TicTacToe
 * @brief Класс, реализующий игровую логику «Крестики-нолики».
 * 
 * @details
 * Обеспечивает хранение игрового поля, текущего игрока,
 * проверку допустимости хода и определение победителя.
 */
class TicTacToe{
public:

    /// @brief Возможные состояния клетки игрового поля и
    enum class Cell {
        Empty,
        Cross,
        Zero
    };


    /**
     * @brief Конструктор игры.
     * 
     * @param size Размер квадратного поля (по умолчанию 3).
     * 
     * @throws std::invalid_argument Если размер поля меньше 3.
     */
    TicTacToe(int size=3);


        /**
     * @brief Проверяет, можно ли поставить символ в указанную клетку.
     * 
     * @param row Индекс строки.
     * @param col Индекс столбца.
     * @return true Если клетка находится в пределах поля, пуста и игра не завершилась.
     * @return false Если клетка занята или координаты выходят за пределы поля.
     */
    bool CanPlace(int row, int col) const;

    /**
     * @brief Возвращает победителя текущей игры.
     * 
     * @return Cell::Cross, Cell::Zero или Cell::Empty, если победителя нет.
     */
    Cell WhoWinner() const;

    /**
     * @brief Возвращает текущего игрока.
     * 
     * @return Cell::Cross или Cell::Zero.
     */
    Cell CurrentPlayer() const;

    /// @brief возвращает количество оставшихся пустых клеток.
    int GetEmptyCells() const;

private:

    int size;   ///< Размер игрового поля (количество строк и столбцов).
    std::vector<std::vector<Cell>> table; ///< Двумерный вектор, представляющий игровое поле.
    int emptyCells; ///< Количество оставшихся пустых клеток.

    Cell currentPlayer = Cell::Cross; ///< Текущий игрок.
    Cell winner = Cell::Empty;        ///< Победитель текущей партии.

    /**
     * @brief Проверяет, находится ли клетка в пределах игрового поля.
     * 
     * @param row Индекс строки.
     * @param col Индекс столбца.
     * @return true Если координаты внутри поля.
     * @return false В противном случае.
     */
    bool IsInside(int row, int col) const;

    /**
     * @brief Обновляет состояние победителя после каждого хода.
     * 
     * @param row Индекс строки, в которую был сделан ход.
     * @param col Индекс столбца, в который был сделан ход.
     */
    void WinnerUpd(int row, int col);


    friend class CellProxy;
    friend class RowProxy;

public:
    /**
     * @brief Доступ к строке игрового поля для записи.
     * 
     * @param row Индекс строки.
     * @return RowProxy Объект-прокси, предоставляющий доступ к ячейкам строки.
     */
    RowProxy operator[](int row);

    /**
     * @brief Доступ к строке игрового поля только для чтения.
     * 
     * @param row Индекс строки.
     * @return const std::vector<Cell>& Ссылка на вектор ячеек строки.
     */
    const std::vector<Cell>& operator[](int row) const;
};
