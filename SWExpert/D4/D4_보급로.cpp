#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int N, res;
int map[101][101];
struct que {
	int r, c, cnt;
};
bool operator<(que a, que b) {
	return a.cnt > b.cnt;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		priority_queue<que> q;
		bool visit[101][101] = { false, };
		res = 987654321;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%1d", &map[i][j]);
		q.push({ 0,0,0 });
		visit[0][0] = true;
		while (!q.empty()) {
			int r = q.top().r;
			int c = q.top().c;
			int cnt = q.top().cnt;
			q.pop();
			if (cnt > res) continue;
			if (r == N - 1 && c == N - 1) {
				res = min(res, cnt);
				continue;
			}
			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d], nc = c + dc[d];
				if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
					if (!visit[nr][nc]) {
						visit[nr][nc] = true;
						int tmp = cnt + map[nr][nc];
						q.push({ nr,nc, tmp });
					}
				}
			}
		}
		printf("#%d %d\n", t, res);
	}
	return 0;
}