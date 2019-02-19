#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
BOJ_14502_¿¬±¸¼Ò
*/
int N,M;
int map[9][9];
int visit[9][9];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
queue<pair<int, int>> virus;
int maxN = -987654321;
int wall=0;
void copyMap(int a[][9], int b[][9]) {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			a[i][j] = b[i][j];
}
int spreadVirus() {
	int tmp[9][9], chk[9][9] = { 0, };
	copyMap(tmp, map);
	queue<pair<int, int>> q;
	q = virus;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if(nr >= 0 && nc >= 0 && nr < N &&nc < M) {
				if (!chk[nr][nc] && tmp[nr][nc] == 0) {
					chk[nr][nc] = 1;
					tmp[nr][nc] = 2;
					q.push({ nr,nc });
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) res++;
		}
	}
	return res;
}
void dfs(int r, int c, int cnt) {
	if (cnt == 3) {
		maxN = max(maxN, spreadVirus());
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && !visit[i][j]) {
				map[i][j] = visit[i][j] = 1;
				dfs(i, j, cnt+1);
				map[i][j] = visit[i][j] = 0;
			}
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) virus.push({ i,j });
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = visit[i][j] = 1;
				dfs(i, j, 1);
				map[i][j] = visit[i][j] = 0;
			}
		}
	}
	printf("%d", maxN);
	return 0;
}