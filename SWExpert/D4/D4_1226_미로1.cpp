#include<iostream>
#include<string.h>
using namespace std;
int map[17][17];
bool visit[17][17];
int startR, startC;
int res;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
void dfs(int r, int c) {
	for(int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < 16 && nc < 16 && !visit[nr][nc]) {
			if (map[nr][nc] ==0) {
				visit[nr][nc] = 1;
				dfs(nr, nc);
			}
			else if (map[nr][nc] == 3) {
				res = 1;
				break;
			}
		}
	}
	if (res == 1) return;
}
int main() {
	for (int t = 1; t <= 10; t++) {
		res = 0;
		memset(visit, 0, sizeof(visit));
		cin >> t;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2)
					startR = i, startC = j;
			}
		}
		visit[startR][startC] = 1;
		dfs(startR, startC);
		printf("#%d %d\n", t, res);
	}
}