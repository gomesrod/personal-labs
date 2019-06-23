#include <iostream>
#include <curses.h>

int main()
{
    initscr();

    printw("Teste");
    refresh();

    getch();
    endwin();
    return 0;
}
