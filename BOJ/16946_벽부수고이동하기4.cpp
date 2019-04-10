#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
int N, M, res, idx;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int map[1001][1001], area[1001][1001];;
bool visit[1001][1001];
int ans[1001][1001];
vector<int> v;
void bfs(int r, int c) {
	queue <pair<int, int>> q;
	q.push({ r,c });
	int cnt = 1;
	area[r][c] = idx;
	visit[r][c] = true;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d], nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (map[nr][nc] == 0 && !visit[nr][nc]) {
					visit[nr][nc] = true;
					area[nr][nc] = idx;
					q.push({ nr,nc });
					cnt++;
				}
			}
		}
	}
	v.push_back(cnt);
}
int main() {
	scanf("%d%d", &N, &M);
	memset(area, -1, sizeof(area));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && !visit[i][j]) {
				bfs(i, j);
				idx++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				set<int> s;
				for (int d = 0; d < 4; d++) {
					int nr = i + dr[d], nc = j + dc[d];
					if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
						if (map[nr][nc] == 0) {
							if (s.find(area[nr][nc]) == s.end()) {
								s.insert(area[nr][nc]);
								ans[i][j] += v[area[nr][nc]];
							}
						}
					}
				}
				ans[i][j]++;
				ans[i][j] %= 10;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}