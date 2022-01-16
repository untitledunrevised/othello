/*
	Name: Othello
	Author: Untitled_unrevised
*/

#include "othello.h"

int board[8][8], whoseturn;

void init() {
	int i, j;
	for(i = 0; i < 8; ++i)
		for(j = 0; j < 8; ++j)
			board[i][j] = 0;
	board[3][3] = board[4][4] = -1;
	board[3][4] = board[4][3] = 1;
	whoseturn = 1;
}

bool othello_hasnext(int row, int col) {
	int i, j;
	for(i = row-1; i >= 0 && board[i][col] == -whoseturn; --i);
	if(i >= 0 && i != row-1 && board[i][col] == whoseturn)
		return true;
	for(i = row+1; i < 8 && board[i][col] == -whoseturn; ++i);
	if(i < 8 && i != row+1 && board[i][col] == whoseturn)
		return true;
	for(j = col-1; j >= 0 && board[row][j] == -whoseturn; --j);
	if(j >= 0 && j != col-1 && board[row][j] == whoseturn)
		return true;
	for(j = col+1; j < 8 && board[row][j] == -whoseturn; ++j);
	if(j < 8 && j != col+1 && board[row][j] == whoseturn)
		return true;
	for(i = row-1, j = col-1; i >= 0 && j >= 0 && board[i][j] == -whoseturn; --i, --j);
	if(i >= 0 && j >= 0 && i != row-1 && board[i][j] == whoseturn)
		return true;
	for(i = row-1, j = col+1; i >= 0 && j < 8 && board[i][j] == -whoseturn; --i, ++j);
	if(i >= 0 && j < 8 && i != row-1 && board[i][j] == whoseturn)
		return true;
	for(i = row+1, j = col-1; i < 8 && j >= 0 && board[i][j] == -whoseturn; ++i, --j);
	if(i < 8 && j >= 0 && i != row+1 && board[i][j] == whoseturn)
		return true;
	for(i = row+1, j = col+1; i < 8 && j < 8 && board[i][j] == -whoseturn; ++i, ++j);
	if(i < 8 && j < 8 && i != row+1 && board[i][j] == whoseturn)
		return true;
	return false;
}

bool othello_execute(int row, int col) {
	int i, j;
	bool flg = false;
	for(i = row-1; i >= 0 && board[i][col] == -whoseturn; --i);
	if(i >= 0 && i != row-1 && board[i][col] == whoseturn) {
		for(i = row-1; i >= 0 && board[i][col] == -whoseturn; --i)
			board[i][col] = whoseturn;
		flg = true;
	}
	for(i = row+1; i < 8 && board[i][col] == -whoseturn; ++i);
	if(i < 8 && i != row+1 && board[i][col] == whoseturn) {
		for(i = row+1; i < 8 && board[i][col] == -whoseturn; ++i)
			board[i][col] = whoseturn;
		flg = true;
	}
	for(j = col-1; j >= 0 && board[row][j] == -whoseturn; --j);
	if(j >= 0 && j != col-1 && board[row][j] == whoseturn) {
		for(j = col-1; j >= 0 && board[row][j] == -whoseturn; --j)
			board[row][j] = whoseturn;
		flg = true;
	}
	for(j = col+1; j < 8 && board[row][j] == -whoseturn; ++j);
	if(j < 8 && j != col+1 && board[row][j] == whoseturn) {
		for(j = col+1; j < 8 && board[row][j] == -whoseturn; ++j)
			board[row][j] = whoseturn;
		flg = true;
	}
	for(i = row-1, j = col-1; i >= 0 && j >= 0 && board[i][j] == -whoseturn; --i, --j);
	if(i >= 0 && j >= 0 && i != row-1 && board[i][j] == whoseturn) {
		for(i = row-1, j = col-1; i >= 0 && j >= 0 && board[i][j] == -whoseturn; --i, --j)
			board[i][j] = whoseturn;
		flg = true;
	}
	for(i = row-1, j = col+1; i >= 0 && j < 8 && board[i][j] == -whoseturn; --i, ++j);
	if(i >= 0 && j < 8 && i != row-1 && board[i][j] == whoseturn) {
		for(i = row-1, j = col+1; i >= 0 && j < 8 && board[i][j] == -whoseturn; --i, ++j)
			board[i][j] = whoseturn;
		flg = true;
	}
	for(i = row+1, j = col-1; i < 8 && j >= 0 && board[i][j] == -whoseturn; ++i, --j);
	if(i < 8 && j >= 0 && i != row+1 && board[i][j] == whoseturn) {
		for(i = row+1, j = col-1; i < 8 && j >= 0 && board[i][j] == -whoseturn; ++i, --j)
			board[i][j] = whoseturn;
		flg = true;
	}
	for(i = row+1, j = col+1; i < 8 && j < 8 && board[i][j] == -whoseturn; ++i, ++j);
	if(i < 8 && j < 8 && i != row+1 && board[i][j] == whoseturn) {
		for(i = row+1, j = col+1; i < 8 && j < 8 && board[i][j] == -whoseturn; ++i, ++j)
			board[i][j] = whoseturn;
		flg = true;
	}
	return flg;
}

bool othello_move(const char *str) {
	if(str[1] < '1' || str[1] > '8')
		return false;
	if((str[0] < 'a' || str[0] > 'h') && (str[0] < 'A' || str[0] > 'H'))
		return false;
	int row = str[1] - '1';
	int col;
	if(str[0] >= 'a')
		col = str[0] - 'a';
	else
		col = str[0] - 'A';
	if(!othello_execute(row, col))
		return false;
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			if(othello_hasnext(i, j)) {
				whoseturn = -whoseturn;
				break;
			}
	return true;
}

int othello_whoseturn() { return whoseturn; }
int othello_getboard(int row, int col) { return board[row][col]; }
