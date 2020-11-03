#include <curses.h>
#include <iostream>

using namespace std;

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int ch;
    nodelay(stdscr, TRUE);
    for (;;) {
         if ((ch = getch()) == ERR) {
         }
         else {
             cout << "Input is " << ch << endl;
         }
    }

    cout << "Hello World!" << endl;

    endwin();
    return 0;
}
