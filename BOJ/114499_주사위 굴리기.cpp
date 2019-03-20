#include <iostream>
#include<vector>
using namespace std;
int n, m, x, y, k;
int map[21][21];
int dice[6] = { 0, }; //아래 위 오른 왼 앞 뒤
int copyDice[6] = { 0, };
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
//동 1 서 2 북 3 남 4
void copyD(int a[], int b[]) {
	for (int i = 0; i < 6; i++)
		a[i] = b[i];
}
void changeDice(int dir) {
	copyD(copyDice, dice);
	if (dir == 1) {
		dice[0] = copyDice[2];
		dice[1] = copyDice[3];
		dice[2] = copyDice[1];
		dice[3] = copyDice[0];
	}
	else if (dir == 2) {
		dice[0] = copyDice[3];
		dice[1] = copyDice[2];
		dice[2] = copyDice[0];
		dice[3] = copyDice[1];
	}
	else if (dir == 3) {
		dice[0] = copyDice[5];
		dice[1] = copyDice[4];
		dice[4] = copyDice[0];
		dice[5] = copyDice[1];
	}
	else if (dir == 4) {
		dice[0] = copyDice[4];
		dice[1] = copyDice[5];
		dice[4] = copyDice[1];
		dice[5] = copyDice[0];
	}
}
int main() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int dir;
		cin >> dir;
		int xx = x + dr[dir - 1];
		int yy = y + dc[dir - 1];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
		changeDice(dir);
		if (map[xx][yy] == 0) {
			map[xx][yy] = dice[0];
		}
		else{
			dice[0] = map[xx][yy];
			map[xx][yy] = 0;
		}
		cout << dice[1] << endl;
		x = xx, y = yy;
	}

	return 0;
}
