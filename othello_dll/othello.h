#ifndef _OTHELLO_DLL_H_
#define _OTHELLO_DLL_H_

#include <windows.h>

#define DLLEXPORT __declspec(dllexport)

DLLEXPORT void init();
DLLEXPORT BOOL othello_move(const char *str);
DLLEXPORT int othello_whoseturn();
DLLEXPORT int othello_getboard(int row, int col);

#endif
