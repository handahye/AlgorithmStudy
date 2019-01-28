#include <queue>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int pipe[6][2] = { {0,1},{2,3},{0,2},{1,2},{1,3},{0,3} };
int dir[4][3] = { {1,4,5},{1,3,6},{2,5,6}, {2,3,4} };
int N;
int map[51][51], dist[51][51];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
struct que{
	int r;
	int c;
	int cnt;
	int type;
};
bool chkGo(int d, int nextType) {
	bool chk = false;
	for (int t = 0; t < 3; t++) {
		if (nextType == dir[d][t]) 
			chk = true;
	}
	return chk;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = 987654321;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		queue<que> q; 
		q.push({ 0,0,1,map[0][0]});
		dist[0][0] = 1;
		while (!q.empty()) {
			int cnt = q.front().cnt;
			int r = q.front().r;
			int c = q.front().c;
			int type = q.front().type;
			q.pop();

			if (dist[r][c] < cnt) continue;

			for (int d = 0; d < 2; d++) {
				int nd = pipe[type - 1][d];
				int nr = r + dr[nd];
				int nc = c + dc[nd];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
				if (chkGo(nd, map[nr][nc]) && dist[nr][nc]>cnt + 1) {
					dist[nr][nc] = cnt + 1;
					q.push({ nr,nc,cnt+1,map[nr][nc]});
				}
				else if (!chkGo(nd, map[nr][nc]) && dist[nr][nc]>cnt + 1) {
					dist[nr][nc] = cnt + 1;
					if (map[nr][nc] == 2 || map[nr][nc] == 1)
						q.push({ nr,nc,cnt + 1,dir[nd][0] });
					else {
						q.push({ nr,nc,cnt + 1, dir[nd][1] });
						q.push({ nr,nc,cnt + 1, dir[nd][2] });
					}
				}
			}
		}
		printf("#%d %d\n", t, dist[N-1][N-1]);
	}
	return 0;
}