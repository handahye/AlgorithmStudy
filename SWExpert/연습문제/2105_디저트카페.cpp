#include <iostream>
#include <algorithm>
#include<string.h>
#include <queue>
using namespace std;
int dr[] = { 1,1,-1,-1 };
int dc[] = { -1,1,1,-1 }; //LD, RD, RU, LU
int N, res;
int map[21][21];
bool cake[101];
int sr, sc;
void dfs(int r, int c, int cnt, int dir, int dirCnt) {
	if (dirCnt > 4) return;

	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d], nc = c + dc[d];
		if (sr == nr && sc == nc && cnt > 3) {
			res = max(res, cnt);
			return;
		}
		if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
			if (!cake[map[nr][nc]]) {
				cake[map[nr][nc]]  = true;
				if (dir != d) dfs(nr, nc, cnt + 1, d, dirCnt + 1);
				else dfs(nr, nc, cnt + 1, dir, dirCnt);
				cake[map[nr][nc]]  = false;
			}

		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		res = -1;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &map[i][j]);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cake[map[i][j]]  = true;
				sr = i, sc = j;
				dfs(i, j, 1, -1, 0);
				cake[map[i][j]]  = false;
			}
		}
		printf("#%d %d\n", t, res);
	}
	return 0;
}