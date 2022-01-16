#ifndef OTHELLO_H
#define OTHELLO_H

#include <stdbool.h>

void init();
bool othello_move(const char *str);
int othello_whoseturn();
int othello_getboard(int row, int col);

#endif
