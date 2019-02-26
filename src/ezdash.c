// ezdash.c
//

#include "ezdash.h"
#include <curses.h>


int r,c;  // current row and column (upper-left is (0,0))

// str_array = {"str1", "str2", ...}
//
void ezdash_print_page(ezdash_component comp, int start_row, int num_lines, const char **str_array){ // ezdash_print_page#

    int i;

    clear();
//    move(start_row,0);

    for(i=0; i<num_lines && i<comp.dash_height; i++){

        mvaddnstr(
            i%comp.rows,
           (i/comp.rows)*comp.dash_width,
            str_array[i],
            comp.dash_width);

    }

    refresh();

}



void ezdash_init(){

    int i;  char d;

    WINDOW* wnd;

    wnd = initscr();    // curses call to initialize window
//    cbreak();           // curses call to set no waiting for Enter key
//    noecho();           // curses call to set no echoing
//    getmaxyx(wnd,nrows,ncols);  // curses call to find size of window
//    clear();            // curses call to clear screen, send cursor to position (0,0)

//    refresh();  // curses call to implement all changes since last refresh

    scrollok(wnd, TRUE); // printw() acts like printf now

    const char *foo[] = {
        "foo blah blah blah\n",
        "bartering\n",
    };

    const char *bar[] = {
        "a\n",
        "z\n",
    };

//    ezdash_print_page(1, 2, foo);

    d = getch();    // curses call to input from keyboard

//    ezdash_print_page(1, 2, bar);

    d = getch();    // curses call to input from keyboard

    printw("Type something: ");
    char str[80];
    getstr(str);
    printw("You Entered: %s", str);
    d = getch();    // curses call to input from keyboard

//    r = 0; c = 0;
//
//    while (1)  {
//
//        d = getch();    // curses call to input from keyboard
//        if(d=='q')break;
//
//        draw(d);        // draw the character
//
//    }

//    while(1);

    endwin();  // curses call to restore the original window and leave

}


// Clayton Bauman 2019
