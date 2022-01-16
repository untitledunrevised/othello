/*
	Name: Othello
	Author: Untitled_unrevised
*/

#include "othello.h"

static int board[8][8], whoseturn, blackcnt, whitecnt;
BOOL gameover;

void othello_init() {
	int i, j;
	for(i = 0; i < 8; ++i)
		for(j = 0; j < 8; ++j)
			board[i][j] = 0;
	board[3][3] = board[4][4] = -1;
	board[3][4] = board[4][3] = 1;
	whoseturn = 1;
	blackcnt = 2;
	whitecnt = 2;
	gameover = FALSE;
}

BOOL othello_hasnext(int row, int col) {
	if(board[row][col])
		return FALSE;
	int i, j;
	for(i = row-1; i >= 0 && board[i][col] == -whoseturn; --i);
	if(i >= 0 && i != row-1 && board[i][col] == whoseturn)
		return TRUE;
	for(i = row+1; i < 8 && board[i][col] == -whoseturn; ++i);
	if(i < 8 && i != row+1 && board[i][col] == whoseturn)
		return TRUE;
	for(j = col-1; j >= 0 && board[row][j] == -whoseturn; --j);
	if(j >= 0 && j != col-1 && board[row][j] == whoseturn)
		return TRUE;
	for(j = col+1; j < 8 && board[row][j] == -whoseturn; ++j);
	if(j < 8 && j != col+1 && board[row][j] == whoseturn)
		return TRUE;
	for(i = row-1, j = col-1; i >= 0 && j >= 0 && board[i][j] == -whoseturn; --i, --j);
	if(i >= 0 && j >= 0 && i != row-1 && board[i][j] == whoseturn)
		return TRUE;
	for(i = row-1, j = col+1; i >= 0 && j < 8 && board[i][j] == -whoseturn; --i, ++j);
	if(i >= 0 && j < 8 && i != row-1 && board[i][j] == whoseturn)
		return TRUE;
	for(i = row+1, j = col-1; i < 8 && j >= 0 && board[i][j] == -whoseturn; ++i, --j);
	if(i < 8 && j >= 0 && i != row+1 && board[i][j] == whoseturn)
		return TRUE;
	for(i = row+1, j = col+1; i < 8 && j < 8 && board[i][j] == -whoseturn; ++i, ++j);
	if(i < 8 && j < 8 && i != row+1 && board[i][j] == whoseturn)
		return TRUE;
	return FALSE;
}

BOOL othello_execute(int row, int col) {
	if(board[row][col])
		return FALSE;
	int i, j;
	BOOL flg = FALSE;
	for(i = row-1; i >= 0 && board[i][col] == -whoseturn; --i);
	if(i >= 0 && i != row-1 && board[i][col] == whoseturn) {
		for(i = row-1; i >= 0 && board[i][col] == -whoseturn; --i) {
			board[i][col] = whoseturn;
			blackcnt += whoseturn;
			whitecnt -= whoseturn;
		}
		flg = TRUE;
	}
	for(i = row+1; i < 8 && board[i][col] == -whoseturn; ++i);
	if(i < 8 && i != row+1 && board[i][col] == whoseturn) {
		for(i = row+1; i < 8 && board[i][col] == -whoseturn; ++i) {
			board[i][col] = whoseturn;
			blackcnt += whoseturn;
			whitecnt -= whoseturn;
		}
		flg = TRUE;
	}
	for(j = col-1; j >= 0 && board[row][j] == -whoseturn; --j);
	if(j >= 0 && j != col-1 && board[row][j] == whoseturn) {
		for(j = col-1; j >= 0 && board[row][j] == -whoseturn; --j) {
			board[row][j] = whoseturn;
			blackcnt += whoseturn;
			whitecnt -= whoseturn;
		}
		flg = TRUE;
	}
	for(j = col+1; j < 8 && board[row][j] == -whoseturn; ++j);
	if(j < 8 && j != col+1 && board[row][j] == whoseturn) {
		for(j = col+1; j < 8 && board[row][j] == -whoseturn; ++j) {
			board[row][j] = whoseturn;
			blackcnt += whoseturn;
			whitecnt -= whoseturn;
		}
		flg = TRUE;
	}
	for(i = row-1, j = col-1; i >= 0 && j >= 0 && board[i][j] == -whoseturn; --i, --j);
	if(i >= 0 && j >= 0 && i != row-1 && board[i][j] == whoseturn) {
		for(i = row-1, j = col-1; i >= 0 && j >= 0 && board[i][j] == -whoseturn; --i, --j) {
			board[i][j] = whoseturn;
			blackcnt += whoseturn;
			whitecnt -= whoseturn;
		}
		flg = TRUE;
	}
	for(i = row-1, j = col+1; i >= 0 && j < 8 && board[i][j] == -whoseturn; --i, ++j);
	if(i >= 0 && j < 8 && i != row-1 && board[i][j] == whoseturn) {
		for(i = row-1, j = col+1; i >= 0 && j < 8 && board[i][j] == -whoseturn; --i, ++j) {
			board[i][j] = whoseturn;
			blackcnt += whoseturn;
			whitecnt -= whoseturn;
		}
		flg = TRUE;
	}
	for(i = row+1, j = col-1; i < 8 && j >= 0 && board[i][j] == -whoseturn; ++i, --j);
	if(i < 8 && j >= 0 && i != row+1 && board[i][j] == whoseturn) {
		for(i = row+1, j = col-1; i < 8 && j >= 0 && board[i][j] == -whoseturn; ++i, --j) {
			board[i][j] = whoseturn;
			blackcnt += whoseturn;
			whitecnt -= whoseturn;
		}
		flg = TRUE;
	}
	for(i = row+1, j = col+1; i < 8 && j < 8 && board[i][j] == -whoseturn; ++i, ++j);
	if(i < 8 && j < 8 && i != row+1 && board[i][j] == whoseturn) {
		for(i = row+1, j = col+1; i < 8 && j < 8 && board[i][j] == -whoseturn; ++i, ++j) {
			board[i][j] = whoseturn;
			blackcnt += whoseturn;
			whitecnt -= whoseturn;
		}
		flg = TRUE;
	}
	return flg;
}

BOOL othello_move(const char *str) {
	if(str[1] < '1' || str[1] > '8')
		return FALSE;
	if((str[0] < 'a' || str[0] > 'h') && (str[0] < 'A' || str[0] > 'H'))
		return FALSE;
	int row = str[1] - '1';
	int col;
	if(str[0] >= 'a')
		col = str[0] - 'a';
	else
		col = str[0] - 'A';
	if(!othello_execute(row, col))
		return FALSE;
	board[row][col] = whoseturn;
	if(whoseturn == 1)
		++blackcnt;
	else
		++whitecnt;
	if(blackcnt + whitecnt == 64) {
		gameover = TRUE;
		return TRUE;
	}
	int i, j;
	//Check if the opposite can move
	whoseturn = -whoseturn;
	for(i = 0; i < 8; ++i)
		for(j = 0; j < 8; ++j)
			if(othello_hasnext(i, j))
				return TRUE;
	//Find the opposite can't move
	whoseturn = -whoseturn;
	for(i = 0; i < 8; ++i)
		for(j = 0; j < 8; ++j)
			if(othello_hasnext(i, j))
				return TRUE;
	//Draw
	gameover = TRUE;
	return TRUE;
}

int othello_whoseturn() { return whoseturn; }
int othello_getboard(int row, int col) { return board[row][col]; }
int othello_blackcnt() { return blackcnt; }
int othello_whitecnt() { return whitecnt; }
BOOL othello_gameover() { return gameover; }
