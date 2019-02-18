#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
/*
BOJ_16236_아기상어
*/
int map[21][21];
int visit[21][21];
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
struct shark {
	int r, c, shSize, cnt, time;
};
bool cmp(shark a, shark b) {
	if (a.time < b.time) return true;
	else if (a.time == b.time) {
		if (a.r < b.r) return true;
		else if (a.r == b.r) {
			if (a.c < b.c) return true;
			else return false;
		}
		else if (a.r>b.r) return false;
	}
	else if (a.time>b.time) return false;
}
int main() {
	int N;
	int sr, sc;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) sr = i, sc = j;
		}
	}
	queue<shark> q;
	map[sr][sc] = 0;
	visit[sr][sc] = 1;
	q.push({ sr,sc,2,0,0 });
	int ans = 0;
	while (1) {
		vector<shark> v;
		memset(visit, 0, sizeof(visit));
		while (!q.empty()) {
			int r = q.front().r;
			int c = q.front().c;
			int shSize = q.front().shSize;
			int cnt = q.front().cnt;
			int time = q.front().time;
			q.pop();

			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visit[nr][nc]) {
					if (map[nr][nc] == 0 || map[nr][nc] == shSize) {
						visit[nr][nc] = 1;
						q.push({ nr,nc,shSize,cnt,time + 1 });
					}
					else if (map[nr][nc] < shSize) {
						visit[nr][nc] = 1;
						v.push_back({ nr,nc,shSize,cnt + 1,time + 1 });
					}
				}
			}
		}

		if (v.size() == 0) break;

		sort(v.begin(), v.end(), cmp);
		if (v[0].shSize == v[0].cnt) {
			v[0].shSize++;
			v[0].cnt = 0;
		}
		map[v[0].r][v[0].c] = 0;
		ans += v[0].time;
		visit[v[0].r][v[0].c] = 1;
		q.push({ v[0].r, v[0].c, v[0].shSize, v[0].cnt, 0 });
	}
	cout << ans;
	return 0;
}