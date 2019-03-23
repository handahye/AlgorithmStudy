#include <iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int map[9][9];
bool visit[9][9];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int N, K;
int res;
void dfs(int r, int c, int h, int cnt, bool flag) {
	if (h == 0) {
		res = max(res, cnt);
		return;
	}
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d], nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visit[nr][nc]) {
			if (h > map[nr][nc]) {
				visit[nr][nc] = true;
				dfs(nr, nc, map[nr][nc], cnt + 1, flag);
				visit[nr][nc] = false;
			}
			else if (h <= map[nr][nc] && !flag) {
				if (map[nr][nc] - K<h) {
					visit[nr][nc] = true;
					dfs(nr, nc, h - 1, cnt + 1, !flag);
					visit[nr][nc] = false;
				}
				else res = max(res, cnt);
			}
			else if (h <= map[nr][nc] && flag) {
				res = max(res, cnt);
			}
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		res = -987654321;
		vector<pair<int, int>> s;
		memset(visit, false, sizeof(visit));
		scanf("%d%d", &N, &K);
		int maxN = -987654321;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				maxN = max(maxN, map[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == maxN)
					s.push_back({ i,j });
			}
		}
		for (int i = 0; i < s.size(); i++) {
			visit[s[i].first][s[i].second] = true;
			dfs(s[i].first, s[i].second, maxN, 1, false);
			visit[s[i].first][s[i].second] = false;
		}
		printf("#%d %d\n", t, res);
	}
	return 0;
}
