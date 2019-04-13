 #include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
using namespace std;
struct que {
	int r, c, cnt, len;
};
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int N, M;
int map[1001][1001];
bool visit[1001][1001][2];
int bfs() {
	queue<que> q;
	q.push({ 0,0,0,1 });
	visit[0][0][0] = true;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int cnt = q.front().cnt; //º® ºÎ¼ø È½¼ö
		int len = q.front().len;
		q.pop();

		if (r == N - 1 && c == M - 1) return len;
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d], nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (map[nr][nc] == 1 && cnt == 0) {
					visit[nr][nc][cnt] = true;
					q.push({ nr,nc,cnt + 1, len + 1 });
				}
				else if (map[nr][nc] == 0 && !visit[nr][nc][cnt]) {
					visit[nr][nc][cnt] = true;
					q.push({ nr,nc,cnt,len + 1 });
				}
			}
		}
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	printf("%d", bfs());
	return 0;
}