#include "TUI/tui.h"

int main(int argc,char *argv[])
{
    int size(3);

    if (argc == 2)
        size = std::stoi(argv[1]);

    tui game(size);
    
    game.Run();
    return 0;
}
