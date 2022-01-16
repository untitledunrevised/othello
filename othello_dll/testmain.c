#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
	HINSTANCE hinstdll = LoadLibrary("othello.dll");
	if(hinstdll != NULL) {
		
		void (*othello_init)() = (void(__cdecl *)())GetProcAddress(hinstdll, "othello_init");
		BOOL (*othello_move)(const char *) = (BOOL(__cdecl *)(const char *))GetProcAddress(hinstdll, "othello_move");
		int (*othello_whoseturn)() = (int(__cdecl *)())GetProcAddress(hinstdll, "othello_whoseturn");
		int (*othello_getboard)(int, int) = (int(__cdecl *)(int, int))GetProcAddress(hinstdll, "othello_getboard");
		int (*othello_blackcnt)() = (int(__cdecl *)())GetProcAddress(hinstdll, "othello_blackcnt");
		int (*othello_whitecnt)() = (int(__cdecl *)())GetProcAddress(hinstdll, "othello_whitecnt");
		BOOL (*othello_gameover)() = (BOOL(__cdecl *)())GetProcAddress(hinstdll, "othello_gameover");
		
		othello_init();
		while(!othello_gameover()) {
			system("cls");
			int i, j;
			puts(" ABCDEFGH");
			for(i = 0; i < 8; ++i) {
				putchar(i + '1');
				for(j = 0; j < 8; ++j) {
					int tp = othello_getboard(i, j);
					if(tp == 1)
						putchar('@');
					if(tp == -1)
						putchar('O');
					if(tp == 0)
						putchar('-');
				}
				puts("");
			}
			printf("Black: %d\n", othello_blackcnt());
			printf("White: %d\n", othello_whitecnt());
			if(othello_whoseturn() == 1)
				puts("Black\'s turn.");
			else
				puts("White\'s turn.");
			char str[1024];
			gets(str);
			if(!othello_move(str)) {
				puts("Invalid command. Try again.");
				system("pause");
			}
		};
		int black = othello_blackcnt();
		int white = othello_whitecnt();
		if(black > white)
			puts("Black wins.");
		if(black < white)
			puts("White wins.");
		if(black == white)
			puts("Draw.");
		system("pause");
		FreeLibrary(hinstdll);
	}
	return 0;
}
