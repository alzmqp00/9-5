#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>				/* printf, scanf definitions.	*/
#include <stdlib.h>		
void path(char[][8], int, int, int*);
int main(void)
{
	int x = 0;
	int y = 1;
	int state;
	char map[8][8] = {
		 {'X',    ' ',    ' ',    ' ',    ' ',    'X',    'X',    'X'},
		 {' ',    'X',    ' ',    'X',    ' ',    ' ',    ' ',    'X'},
		 {' ',    'X',    ' ',    'X',    ' ',    'X',    ' ',    'X'},
		 {' ',    'X',    ' ',    'X',    ' ',    'X',    ' ',    'X'},
		 {' ',    'X',    ' ',    ' ',    ' ',    'X',    'X',    'X'},
		 {' ',    'X',    ' ',    'X',    ' ',    ' ',    ' ',    'X'},
		 {' ',    'X',    ' ',    'X',    ' ',    'X',    ' ',    'X'},
		 {' ',    ' ',    ' ',    ' ',    ' ',    'X',    ' ',    ' '}
	};
	path(map, x, y, &state);
	if (state != 1) {
		printf("NO path");
	}
	system("pause");
	return 0;
}

void path(char map[][8], int x, int y, int* state) {
	map[x][y] = '*';
	if (x == 7 and y == 7) {
		*state = 1;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		printf("-----------\nnext path:\n");
	}
	else
	{
		if (map[x][y + 1] == ' ' and y + 1 <= 7) {

			path(map, x, y + 1, state);
		}
		if (x - 1 >= 0 and map[x - 1][y] == ' ') {

			path(map, x - 1, y, state);
		}
		if (x + 1 <= 7 and map[x + 1][y] == ' ') {

			path(map, x + 1, y, state);
		}
		if (y - 1 >= 7 and map[x][y - 1] == ' ') {

			path(map, x, y - 1, state);
		}
	}
	map[x][y] = ' ';
}
