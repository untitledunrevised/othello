#ifndef _OTHELLO_DLL_H_
#define _OTHELLO_DLL_H_

#include <windows.h>

#define DLLEXPORT __declspec(dllexport)

DLLEXPORT void othello_init();
DLLEXPORT BOOL othello_move(const char *str);
DLLEXPORT int othello_whoseturn();
DLLEXPORT int othello_getboard(int row, int col);
DLLEXPORT int othello_blackcnt();
DLLEXPORT int othello_whitecnt();
DLLEXPORT BOOL othello_gameover();

#endif
