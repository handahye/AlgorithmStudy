 #include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
int N, M;
int map[51][51];
bool visit[51][51];
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };
int bfs(int a, int b) {
	int rSize = 0;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	rSize++;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		int wall = 1;
		for (int d = 0; d < 4; d++) {
			if ((map[r][c] & wall) != wall) { //현재 방향에 벽 x
				int nr = r + dr[d], nc = c + dc[d];
				if (nr >= 0 && nc >= 0 && nr < N&&nc < M &&!visit[nr][nc]) {
					rSize++;
					visit[nr][nc] = true;
					q.push({ nr,nc });
				}
			}
			wall *= 2;
		}
		
	}
	return rSize;
}
int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	int cnt = 0;
	int maxS = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j]) {
				maxS = max(maxS, bfs(i, j));
				cnt++;
			}
		}
	}
	printf("%d\n%d\n", cnt, maxS);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; k <= 8; k *= 2) {
				if ((map[i][j] & k) == k) { //벽이 있다면
					memset(visit, false, sizeof(visit));
					map[i][j] -= k;
					maxS = max(maxS, bfs(i, j));
					map[i][j] += k;
				}
			}
		}
	}
	printf("%d", maxS);
	return 0;
}