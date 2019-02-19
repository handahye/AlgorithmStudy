#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
BOJ_14891_Åé´Ï¹ÙÄû
*/
int gear[5][9];
void ccw(int n) {
	int tmp = gear[n][0];
	for (int i = 1; i < 8; i++) gear[n][i - 1] = gear[n][i];
	gear[n][7] = tmp;
}
void cw(int n) {
	int tmp = gear[n][7];
	for (int i = 6; i >= 0; i--) gear[n][i + 1] = gear[n][i];
	gear[n][0] = tmp;
}
void right(int n, int dir) {
	if (n > 4) return;
	if (gear[n][6] != gear[n - 1][2]) {
		dir = dir * (-1);
		right(n + 1, dir);
		dir == 1 ? cw(n) : ccw(n);
	}
}
void left(int n, int dir) {
	if (n<1) return;
	if (gear[n][2] != gear[n + 1][6]) {
		dir = dir * (-1);
		left(n - 1, dir);
		dir == 1 ? cw(n) : ccw(n);
	}
}
int main() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &gear[i][j]);
		}
	}
	int K;
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int n, d;
		scanf("%d%d", &n, &d);
		right(n + 1, d);
		left(n - 1, d);
		d == 1 ? cw(n) : ccw(n);
	}
	int ans = 0;
	gear[1][0] == 0 ? ans += 0 : ans += 1;
	gear[2][0] == 0 ? ans += 0 : ans += 2;
	gear[3][0] == 0 ? ans += 0 : ans += 4;
	gear[4][0] == 0 ? ans += 0 : ans += 8;
	printf("%d", ans);
	return 0;
}