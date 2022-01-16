#ifndef OTHELLO_H
#define OTHELLO_H

#include <stdbool.h>

void othello_init();
bool othello_move(const char *str);
int othello_whoseturn();
int othello_getboard(int row, int col);
int othello_blackcnt();
int othello_whitecnt();
bool othello_gameover();

#endif
