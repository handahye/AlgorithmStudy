#include <string>
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
#5373_큐빙
1. 3*3*3의 큐브
2. 윗면: 흰색, 아랫면: 노란색,
앞면: 빨간색, 뒷면: 오랜지색,
왼쪽면: 초록색, 오른쪽면: 파란색
3. 큐브를 돌린 방법이 순서대로 주어짐. 모두 돌린 뒤 가장 윗면 색상 구하기
*/
char cube[6][3][3];
void front(int point, int dir) {
	if (dir == 0) { //시계
		char tmp[3];
		tmp[0] = cube[point][0][0];
		tmp[1] = cube[point][0][1];
		tmp[2] = cube[point][0][2];

		cube[point][0][0] = cube[point][0][0];
		cube[point][0][1] = cube[point][1][0];
		cube[point][0][2] = cube[point][2][0];

		cube[point][0][0] = cube[point][2][0];
		cube[point][1][0] = cube[point][2][1];
		cube[point][2][0] = cube[point][2][2];

		cube[point][2][0] = cube[point][0][2];
		cube[point][2][1] = cube[point][1][2];
		cube[point][2][2] = cube[point][2][2];

		cube[point][0][2] = tmp[0];
		cube[point][1][2] = tmp[1];
		cube[point][2][2] = tmp[2];
	}
	if (dir == 1) {
		char tmp[3];
		tmp[0] = cube[point][0][0];
		tmp[1] = cube[point][0][1];
		tmp[2] = cube[point][0][2];

		cube[point][0][0] = cube[point][0][2];
		cube[point][0][1] = cube[point][1][2];
		cube[point][0][2] = cube[point][2][2];

		cube[point][0][2] = cube[point][2][0];
		cube[point][1][2] = cube[point][2][1];
		cube[point][2][2] = cube[point][2][2];

		cube[point][2][0] = cube[point][0][0];
		cube[point][2][1] = cube[point][1][0];
		cube[point][2][2] = cube[point][2][0];

		cube[point][0][0] = tmp[0];
		cube[point][1][0] = tmp[1];
		cube[point][2][0] = tmp[2];
	}
}
void FB(int type, int a, int b, int c, int d){
	char tmp[3];
	if (type == 1) { 
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[a][2][i];
			cube[a][2][i] = cube[b][0][i];
			cube[b][0][i] = cube[c][2][i];
			cube[c][2][i] = cube[d][0][i];
			cube[d][0][i] = tmp[i];
		}
	}
	if (type == 2) {
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[a][0][i];
			cube[a][0][i] = cube[b][2][i];
			cube[b][2][i] = cube[c][0][i];
			cube[c][0][i] = cube[d][2][i];
			cube[d][2][i] = tmp[i];
		}
	}

}
void RLDU(int type, int a, int b, int c, int d, int axis) {
	char tmp[3];
	if (type == 1) { //왼, 오
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[a][i][axis];
			cube[a][i][axis] = cube[b][i][axis];
			cube[b][i][axis] = cube[c][i][axis];
			cube[c][i][axis] = cube[d][i][axis];
			cube[d][i][axis] = tmp[i];
		}
	}
	else if (type == 2) {//위, 아래
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[a][axis][i];
			cube[a][axis][i] = cube[a][axis][i];
			cube[b][axis][i] = cube[c][axis][i];
			cube[c][axis][i] = cube[d][axis][i];
			cube[d][axis][i] = tmp[i];
		}
	}
}
void rotate(char d, int c) {
	if (d == 'R') {
		if (c == 0) RLDU(1, 0, 4, 1, 5, 2);
		else if (c == 1) RLDU(1, 5, 1, 4, 0, 2);
		front(c, 0);
	}
	if (d == 'L') {
		if (c == 1) RLDU(1, 0, 4, 1, 5, 0);
		else if (c == 0) RLDU(1, 5, 1, 4, 0, 0);
		front(c, 1);
	}
	if (d == 'D') {
		if (c == 1) RLDU(2, 4, 2, 5, 3, 2);
		else if (c == 0)  RLDU(2, 3, 5, 2, 4, 2);
		front(c, 2);
	}
	if (d == 'U') {
		if (c == 0) RLDU(2, 4, 2, 5, 3, 0);
		else if (c == 1) RLDU(1, 3, 5, 2, 4, 0);
		front(c, 3);
	}
	if (d == 'F') {
		if (c == 1) FB(1, 0, 3, 1, 2);
		else if (c == 0)  FB(2, 2, 1, 3, 0);
		front(c, 4);
	}
	if (d == 'B') {
		if (c == 0) FB(2, 0, 3, 1, 2);
		else if (c == 1) FB(1, 2, 1, 3, 0);
		front(c, 5);
	}

}
void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (i == 0) cube[i][j][k] = 'w';//위
				else if (i == 1) cube[i][j][k] = 'y';//아래
				else if (i == 2) cube[i][j][k] = 'g';//왼
				else if (i == 3) cube[i][j][k] = 'b';//오
				else if (i == 4) cube[i][j][k] = 'r';//앞
				else if (i == 5) cube[i][j][k] = 'o';//뒤
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
			char str[2];
			cin >> str;
			char c = str[0];
			char c2 = str[1];
			if (c2 == '+') rotate(c, 0);
			else if (c2 == '-') rotate(c, 1);

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					printf("%c", cube[0][i][j]);
				}
				printf("\n");
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