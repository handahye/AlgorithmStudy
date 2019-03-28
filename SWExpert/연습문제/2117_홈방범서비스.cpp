#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
struct que {
	int r, c, k;
};
int map[21][21];
int chk[21][21];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int N, M;
int cal(int k, int h) {
	return (h*M) - (k*k + (k - 1)*(k - 1));
}
int bfs(int r, int c) {
	int res = 0;
	queue<que> q;
	q.push({ r,c,1});
	int home[20*20] = { 0, };
	bool visit[21][21] = { false, };
	visit[r][c] = true;
	int maxK = 0;
	if (map[r][c]) home[1] += 1;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int k = q.front().k;
		q.pop();
		maxK = max(maxK, k);
		k += 1;
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d], nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visit[nr][nc]) {
				visit[nr][nc] = true;
				if (map[nr][nc]) home[k] += 1;
				q.push({ nr,nc,k});
			}
		}
	}
	int h = 0;
	for (int k = 1; k <= maxK; k++) {
		h += home[k];
		int tmp = cal(k, h);
		if (tmp >= 0) res = max(res, h);
	}
	return res;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int res = -987654321;
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				res = max(res, bfs(i, j));
			}
		}
		printf("#%d %d\n", t, res
		);
	}
	return 0;
}
