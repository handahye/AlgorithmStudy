#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include<iostream>
/*1861. 정사각형 방*/
using namespace std;
int N;
int dr[4] = { 0,0,1,- 1 };
int dc[4] = { 1,-1,0,0 };
int maxN, minStart;
int map[1001][1001], visit[1001][1001];
int dfs(int r, int c, int cnt) {
	int curCnt = cnt;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nc >= 0 && nr < N&&nc < N) {
			if (!visit[nr][nc] && map[r][c] + 1 == map[nr][nc]) {
				visit[nr][nc] = 1;
				curCnt = dfs(nr, nc, cnt+1);
				visit[nr][nc] = 0;
			}
		}
	}
	return curCnt;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> N;
		memset(visit, 0, sizeof(visit));
		maxN = -987654321, minStart = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int res = dfs(i,j,1);
				if (res > maxN || (res == maxN && map[i][j] < minStart)) {
					maxN = res;
					minStart = map[i][j];
				}
			}
		}

		printf("#%d %d %d\n", t, minStart, maxN);
}

	return 0;
}