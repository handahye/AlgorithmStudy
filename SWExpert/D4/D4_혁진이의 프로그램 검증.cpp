#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
using namespace std;
/*
D4_혁진이의 프로그램 검증
1. 만약 다음 이동이 2차원 격자의 바깥으로 이동하는 방향이면, 반대편에 있는 위치로 이동한다.
2. 혁셈블리어에서는 메모리가 단 하나 있으며, 0에서 15사이의 정수를 하나 저장할 수 있다. 가장 처음에는 0이 저장되어 있다.
3. 주어진 프로그램이 정지할 수 있으면 “YES”를 출력하고, 아니면 “NO”를 출력한다.
*/
char map[21][21];
int visit[4][16][21][21]; //dir, num, r, c <- 배열 [4][15][20][20]으로 선언했다가 계속 틀림^-^.. 
int R, C;
bool ans;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
void chkNum(int &r, int &c) {
	if (r >= R) r = 0;
	if (c >= C) c = 0;
	if (r < 0) r = R - 1;
	if (c < 0) c = C - 1;
}
void dfs(int r, int c, int num, int dir) {
	if (ans) return;
	if (map[r][c] == '@') {
		ans = true;
		return;
	}
	else if (map[r][c] >= '0' && map[r][c] <= '9') num = map[r][c] - '0';
	else if (map[r][c] == '>') dir = 0;
	else if (map[r][c] == '<') dir = 1;
	else if (map[r][c] == '^') dir = 2;
	else if (map[r][c] == 'v') dir = 3;
	else if (map[r][c] == '_') num == 0 ? dir = 0 : dir = 1;
	else if (map[r][c] == '|') num == 0 ? dir = 3 : dir = 2;
	else if (map[r][c] == '-') num == 0 ? num = 15 : num -= 1;
	else if (map[r][c] == '+') num == 15 ? num = 0 : num += 1;
	if (map[r][c] == '?') {
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			chkNum(nr, nc);
			if (visit[d][num][nr][nc]) continue;
			visit[d][num][nr][nc] = 1;
			dfs(nr, nc, num, d);
		}
	}
	else {
		int nr = r + dr[dir], nc = c + dc[dir];
		chkNum(nr, nc);
		if (visit[dir][num][nr][nc]) return;
		visit[dir][num][nr][nc] = 1;
		dfs(nr, nc, num, dir);
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = false;
		memset(visit, 0, sizeof(visit));
		cin >> R >> C;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> map[i][j];
		dfs(0, 0, 0, 0);
		if (ans)
			cout << "#" << t << " " << "YES" << endl;
		else
			cout << "#" << t << " " << "NO" << endl;
	}
	return 0;
}