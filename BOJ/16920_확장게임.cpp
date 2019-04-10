#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
struct que{
	int r, c, dist;
};
int N, M, P;
int map[10001][10001];
bool visit[10001][1001];
queue<que> q[10];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int res[10];
int s[10] = { 0, };
void bfs() {
	while (1) {
		bool End = false;
		for (int i = 1; i <= P; i++) {
			queue<que> tmp[10];
			while (!q[i].empty()) {
				int r = q[i].front().r;
				int c = q[i].front().c;
				int dist = q[i].front().dist;
				q[i].pop();
				if (dist == s[i]) {
					tmp[i].push({ r,c,0 });
					continue;
				}
				for (int d = 0; d < 4; d++) {
					int nr = r + dr[d], nc = c + dc[d];
					if (!visit[nr][nc] && nr >= 0 && nc >= 0 && nr < N && nc < M) {
						if (map[nr][nc] == -1) continue;
						if (map[nr][nc] == 0 && dist + 1 <= s[i]) {
							visit[nr][nc] = true;
							q[i].push({ nr,nc, dist + 1 });
							res[i]++;
							End = true;
						}
					}
				}

			}
			q[i] = tmp[i];
			
		}
		if (!End)break;
	}
}
int main() {
	scanf("%d%d%d", &N, &M, &P);
	for (int i = 1; i <= P; i++) {
		int tmp;
		scanf("%d", &tmp);
		s[i] = tmp;
	}
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if (c == '#') map[i][j] = -1;
			else if (c >= '1' && c <= '9') {
				int num = c - '0';
				map[i][j] = num;
				q[num].push({ i,j,0});
				visit[i][j] = true;
				res[num]++;
			}
		}
	}
	bfs();
	for (int i = 1; i <= P; i++) printf("%d ", res[i]);
	return 0;
}