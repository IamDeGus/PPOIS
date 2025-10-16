#include "tui.h"
#include "../GameLogic/RowProxy/row_proxy.h"
#include "../GameLogic/CellProxy/cell_proxy.h"
// #include <locale.h>

tui::tui(int size) : game(TicTacToe(size)), size(size), cursor_row(0), cursor_col(0) {

    setlocale(LC_ALL, "");
    initscr();            // создаёт stdscr и инициализирует режим терминала

    cbreak();
    noecho();
    keypad(stdscr, TRUE); 
    curs_set(0);          

    if (has_colors()) {
        start_color();
        // пара 1 — крестики, пара 2 — нолики, 3 - вспомогательный текст, 4 - ничья
        init_pair(1, 1,    COLOR_BLACK);
        init_pair(2, 6,    COLOR_BLACK);
        init_pair(3, 8, COLOR_BLACK);
        init_pair(4, 3, COLOR_BLACK);
    }
}


tui::~tui(){
    endwin();
}


void  tui::DrawTitle(int r, int c) const{
    mvprintw(r - 8, c - 8, "┌───────────────┐");
    mvprintw(r - 7, c - 8, "│               │");
    mvprintw(r - 6, c - 8, "└─󰯴󰯷󰯽󰰧󰰡─󰯷󰯴󰰃󰰤󰰃󰰕󰰒─┘");


    attron(COLOR_PAIR(1));
    mvprintw(r - 7, c - 6, "TIC ");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(r - 7, c - 2, " TAC ");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(4));
    mvprintw(r - 7, c + 3, " TOE");
    attroff(COLOR_PAIR(4));
}


short tui::DrawPlayer(int r, int c) const{

    short color;
    const char* text;

    if (game.GetEmptyCells() == 0 || game.WhoWinner() != TicTacToe::Cell::Empty){
        switch (game.WhoWinner())
        {
        case TicTacToe::Cell::Cross:
            color = 1;
            text = "   CROSS WON   ";
            break;

        case TicTacToe::Cell::Zero:
            color = 2;
            text = "   ZEROO WON   ";
            break;

        default:
            color = 4;
            text = "     DRAWW     ";
            break;
        }
    } else {
        switch (game.CurrentPlayer())
        {
        case TicTacToe::Cell::Cross:
            color = 1;
            text = "       X       ";
            break;

        case TicTacToe::Cell::Zero:
            color = 2;
            text = "       O       ";
            break;
        }
    }

    attron(COLOR_PAIR(color) | A_REVERSE);
    
    mvprintw(r, c, "               ");
    mvprintw(r + 1, c, text);
    mvprintw(r + 2, c, "               ");

    attroff(COLOR_PAIR(color) | A_REVERSE);

    return color;
}

void tui::DrawMenu(int r, int c) const{

    attron(COLOR_PAIR(3));

    mvprintw(r, c, "CONTROLS");
    
    mvprintw(r + 2, c, "Game Control: ");
    mvprintw(r + 3, c, "    [h] Help ");
    mvprintw(r + 4, c, "    [r] Restart ");
    mvprintw(r + 5, c, "    [q] Quit ");

    mvprintw(r + 7, c, "Movement: ");
    mvprintw(r + 8, c, "    [󰜷]");
    mvprintw(r + 9, c, "  [󰜱 󰜮 󰜴]");
    mvprintw(r + 10, c, "   Movee");

    mvprintw(r + 9, c + 12, "[ 󱞦 ]");
    mvprintw(r + 10, c + 12, "Press");

    attroff(COLOR_PAIR(3));

}


void tui::DrawBoard() const{
    clear();

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    const int cell_h = std::max(1, 3 - size / 5); // вертикальный шаг
    const int cell_w = std::max(3, 7 - (size / 5) * 2); // горизонтальный шаг

    int board_h = (size - 1) * cell_h;
    int board_w = (size - 1) * cell_w;

    const int start_row = (max_y - board_h) / 2 + 2;
    const int start_col = (max_x - board_w) / 2 - 10;

    DrawTitle(start_row, max_x / 2);

    short color = DrawPlayer(start_row - 4, max_x / 2 - 17);


    attron(COLOR_PAIR(color));

    for (int i{start_col - 3}; i < max_x / 2 - 17; i++){
        mvaddwstr(start_row - 2, i, L"─");
    }
    for (int i{max_x / 2 - 2}; i < start_col + board_w + 4; i++){
        mvaddwstr(start_row - 2, i, L"─");
    }

    for (int i{-3}; i < board_w + 4; i++){
        mvaddwstr(start_row + board_h + 2, start_col + i, L"─");
    }

    for (int i{-1}; i < board_h + 2; i++){
        mvaddwstr(start_row + i, start_col - 4, L"│");
        mvaddwstr(start_row + i, start_col + board_w + 4, L"│");
    }

    mvaddwstr(start_row - 2, start_col - 4, L"┌");
    mvaddwstr(start_row - 2, start_col + board_w + 4, L"┐");
    mvaddwstr(start_row + board_h + 2, start_col - 4, L"└");
    mvaddwstr(start_row + board_h + 2, start_col + board_w + 4, L"┘");



    attroff(COLOR_PAIR(color));

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            TicTacToe::Cell cell = game[r][c];
            char ch = symbols.at(cell);
            int y = start_row + r * cell_h;
            int x = start_col + c * cell_w;

            // если это выделенная клетка — инвертируем атрибут
            if (r == cursor_row && c == cursor_col) {
                attron(A_REVERSE);
            }

            // цвет для X и O (если поддерживается)
            if (has_colors()) {
                if (cell == TicTacToe::Cell::Cross) attron(COLOR_PAIR(1));
                else if (cell == TicTacToe::Cell::Zero) attron(COLOR_PAIR(2));
            }

            mvaddch(y, x, ch);

            // выключаем цвет и/или обратный атрибут
            if (has_colors()) {
                if (cell == TicTacToe::Cell::Cross) attroff(COLOR_PAIR(1));
                else if (cell == TicTacToe::Cell::Zero) attroff(COLOR_PAIR(2));
            }
            if (r == cursor_row && c == cursor_col) {
                attroff(A_REVERSE);
            }
        }
    }


    attron(COLOR_PAIR(3));
    for(int i{-2}; i < board_h + 3; i++){
        mvaddwstr(start_row + i, start_col + board_w + 7, L"│");
    }
    attroff(COLOR_PAIR(3));

    DrawMenu(start_row - 2, start_col + board_w + 10);


    refresh();
}


void tui::DrawRule() const{
    clear();

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    const int cell_h = std::max(1, 3 - size / 5); // вертикальный шаг
    const int cell_w = std::max(3, 7 - (size / 5) * 2); // горизонтальный шаг

    int board_h = (size - 1) * cell_h;

    const int start_row = (max_y - board_h) / 2 + 2;
    const int start_col = max_x / 2 - 26;


    DrawTitle(start_row, max_x / 2);

    int y{start_row - 3};
    
    mvprintw(y - 1, start_col, "┌───────────────────────────────────────────────────┐");

    mvprintw(y++, start_col, "│   Tic-tac-toe is a logic game played between two  │");
    mvprintw(y++, start_col, "│ players on a 3x3 or larger square board (up to an │");
    mvprintw(y++, start_col, "│ \"infinite board\"). One player plays the \"crosses\",│");
    mvprintw(y++, start_col, "│ the other the \"zero.\"                             │");
    mvprintw(y++, start_col, "│                                                   │");
    mvprintw(y++, start_col, "│   Players take turns placing symbols (X or O) on  │");
    mvprintw(y++, start_col, "│ empty squares of the board. The frst player to    │");
    mvprintw(y++, start_col, "│ line up three of their pieces vertically, hori-   │");
    mvprintw(y++, start_col, "│ zontally, or diagonally wins.                     │");
    mvprintw(y++, start_col, "└───────────────────────────────────────────────────┘");
    y++;
    mvprintw(y++, start_col, "   ─X─┼─X─┼─X─        · │ X │ ·         X │ · │ O    ");
    mvprintw(y++, start_col, "    ──┼───┼──         ──┼───┼──         ──┼───┼─┼    ");
    mvprintw(y++, start_col, "    · │ X │ O         O │ · │ ·         · │ O │ O    ");
    mvprintw(y++, start_col, "    ──┼───┼──         ──┼───┼──         ──┼───┼─┼    ");
    mvprintw(y++, start_col, "    O │ · │ O         · │ · │ ·         X │ X │ O    ");

    int ch = getch();

}

void tui::Run(){
    bool quit = false;
    // главный цикл — реагируем на клавиши пока пользователь не вышел
    while (!quit) {
        DrawBoard();
        int ch = getch();  // ждём клавишу

        switch (ch) {
            case 'q':  // выход
                quit = true;
                break;
            case 'r':
                Restart();
                break;
            
            case 'h':
                DrawRule();
                break;

            case KEY_UP:
                if (cursor_row > 0) cursor_row--;
                break;

            case KEY_DOWN:
                if (cursor_row < size - 1) cursor_row++;
                break;

            case KEY_LEFT:
                if (cursor_col > 0) cursor_col--;
                break;

            case KEY_RIGHT:
                if (cursor_col < size - 1) cursor_col++;
                break;

            case ' ':  // пробел = сделать ход
            case '\n': // или Enter
                if (game.CanPlace(cursor_row, cursor_col)){
                    game[cursor_row][cursor_col] = game.CurrentPlayer();
                }
                break;
        }
    }
}

void tui::Restart(){
    game = TicTacToe(size);
    cursor_row = 0;
    cursor_col = 0;
}
