#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
char cube[6][3][3];
int charToInt(char d) {
	if (d == 'U') return 0;
	else if (d == 'D')return 1;
	else if (d == 'F')return 2;
	else if (d == 'B')return 3;
	else if (d == 'L')return 4;
	else if (d == 'R')return 5;
}
void Up(int cw) {
	if (cw) {
		for (int i = 0; i < 3; i++) {
			char c = cube[5][0][i];
			cube[5][0][i] = cube[3][0][i];
			cube[3][0][i] = cube[4][0][i];
			cube[4][0][i] = cube[2][0][i];
			cube[2][0][i] = c;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			char c = cube[2][0][i];
			cube[2][0][i] = cube[4][0][i];
			cube[4][0][i] = cube[3][0][i];
			cube[3][0][i] = cube[5][0][i];
			cube[5][0][i] = c;
		}
	}
}
void Down(int cw) {
	if (cw) {
		for (int i = 0; i < 3; i++) {
			char c = cube[4][2][i];
			cube[4][2][i] = cube[3][2][i];
			cube[3][2][i] = cube[5][2][i];
			cube[5][2][i] = cube[2][2][i];
			cube[2][2][i] = c;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			char c = cube[2][2][i];
			cube[2][2][i] = cube[5][2][i];
			cube[5][2][i] = cube[3][2][i];
			cube[3][2][i] = cube[4][2][i];
			cube[4][2][i] = c;
		}
	}
}
void Front(int cw) {
	if (cw) {
		for (int i = 0, j=2; i < 3; i++,j--) {
			char c = cube[4][j][2];
			cube[4][j][2] = cube[1][0][j];
			cube[1][0][j] = cube[5][i][0];
			cube[5][i][0] = cube[0][2][i];
			cube[0][2][i] = c;
		}
	}
	else {
		for (int i = 0, j = 2; i < 3; i++, j--) {
			char c = cube[0][2][i];
			cube[0][2][i] = cube[5][i][0];
			cube[5][i][0] = cube[1][0][j];
			cube[1][0][j] = cube[4][j][2];
			cube[4][j][2] = c;
		}
	}
}
void Back(int cw) {
	if (cw) {
		for (int i = 0, j = 2; i < 3; i++, j--) {
			char c = cube[1][2][i];
			cube[1][2][i] = cube[4][i][0];
			cube[4][i][0] = cube[0][0][j];
			cube[0][0][j] = cube[5][j][2];
			cube[5][j][2] = c;
		}
	}
	else {
		for (int i = 0, j = 2; i < 3; i++, j--) {
			char c = cube[5][j][2];
			cube[5][j][2] = cube[0][0][j];
			cube[0][0][j] = cube[4][i][0];
			cube[4][i][0] = cube[1][2][i];
			cube[1][2][i] = c;
		}
	}
}
void Left(int cw) {
	if (cw) {
		for (int i = 0, j = 2; i < 3; i++, j--) {
			char c = cube[1][i][0];
			cube[1][i][0] = cube[2][i][0];
			cube[2][i][0] = cube[0][i][0];
			cube[0][i][0] = cube[3][j][2];
			cube[3][j][2] = c;
		}
	}
	else {
		for (int i = 0, j = 2; i < 3; i++, j--) {
			char c = cube[3][j][2];
			cube[3][j][2] = cube[0][i][0];
			cube[0][i][0] = cube[2][i][0];
			cube[2][i][0] = cube[1][i][0];
			cube[1][i][0] = c;
		}
	}
}
void Right(int cw) {
	if (cw) {
		for (int i = 0, j = 2; i < 3; i++, j--) {
			char c = cube[3][j][0];
			cube[3][j][0] = cube[0][i][2];
			cube[0][i][2] = cube[2][i][2];
			cube[2][i][2] = cube[1][i][2];
			cube[1][i][2] = c;
		}
	}
	else {
		for (int i = 0, j = 2; i < 3; i++, j--) {
			char c = cube[1][i][2];
			cube[1][i][2] = cube[2][i][2];
			cube[2][i][2] = cube[0][i][2];
			cube[0][i][2] = cube[3][j][0];
			cube[3][j][0] = c;
		}
	}
}
void sideChange(char d, int cw) {
	int num = charToInt(d);
	if (num == 0) Up(cw);
	else if (num == 1) Down(cw);
	else if (num == 2) Front(cw);
	else if (num == 3) Back(cw);
	else if (num == 4) Left(cw);
	else if (num == 5) Right(cw);
}
void frontChangeCw(char d) { //해당 면을 회전시키는 부분
	int num = charToInt(d);
	queue<int> q; 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			q.push(cube[num][i][j]);
		}
	}
	for (int j = 2; j >= 0; j--) {
		for (int i = 0; i < 3; i++) {
			cube[num][i][j] = q.front();
			q.pop();
		}
	}
}
void frontChangeCcw(char d) {
	int num = charToInt(d);
	queue<int> q;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			q.push(cube[num][i][j]);
		}
	}
	for (int i = 0; i<3; i++) {
		for (int j = 2; j >= 0; j--) {
			cube[num][j][i] = q.front();
			q.pop();
		}
	}
}
void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (i == 0) cube[i][j][k] = 'w';//위
				else if (i == 1) cube[i][j][k] = 'y';//아래
				else if (i == 2) cube[i][j][k] = 'r';//앞
				else if (i == 3) cube[i][j][k] = 'o';//뒤
				else if (i == 4) cube[i][j][k] = 'g';//왼
				else if (i == 5) cube[i][j][k] = 'b';//오
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char str[3];
			cin >> str;
			if (str[1] == '+') {
				frontChangeCw(str[0]);
				sideChange(str[0], 1);
			}
			else if (str[1] == '-') {
				frontChangeCcw(str[0]);
				sideChange(str[0], 0);
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%c", cube[0][i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}