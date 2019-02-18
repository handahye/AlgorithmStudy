#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
/*
BOJ_1726_로봇
명령 1. Go k
- k는 1, 2 또는 3일 수 있다. 현재 향하고 있는 방향으로 k칸 만큼 움직인다.
명령 2. Turn dir
- dir은 left 또는 right 이며, 각각 왼쪽 또는 오른쪽으로 90° 회전한다.

0은 궤도가 깔려 있어 로봇이 갈 수 있는 지점이고, 1은 궤도가 없어 로봇이 갈 수 없는 지점이다.

*/
int M, N;
int map[105][105];
int visit[5][105][105];
int sr, sc, sDir, er, ec, eDir;
int dr[] = { 0,1,0,-1 };
int dc[] = { -1,0,1,0 };
struct que {
	int r, c, dir, cnt;
};
void changeDir(int &d) {
	if (d == 1) d = 2;
	else if (d == 2) d = 0;
	else if (d == 3) d = 1;
	else if (d == 4) d = 3;
}
int main() {
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);

	scanf("%d %d %d", &sr, &sc, &sDir);
	changeDir(sDir);
	scanf("%d %d %d", &er, &ec, &eDir);
	changeDir(eDir);

	queue<que> q;
	q.push({ sr,sc,sDir,0 });
	visit[sDir][sr][sc] = 1;
	while (!q.empty()) {
		int r = q.front().r, c = q.front().c, dir = q.front().dir, cnt = q.front().cnt;
		q.pop();
		if (r == er && c == ec && dir == eDir) {
			printf("%d", cnt);
			break;
		}
		int nr, nc;
		for (int k = 1; k <= 3; k++) {
			nr = r + dr[dir] * k;
			nc = c + dc[dir] * k;
			if (nr <= 0 || nc <= 0 || nr > M || nc > N) break;
			if (map[nr][nc]) break;
			if (visit[dir][nr][nc]) continue;
			visit[dir][nr][nc] = 1;
			q.push({ nr, nc, dir, cnt + 1 });
		}
		for (int d = 0; d < 4; d++) {
			if (d == dir || d == (dir + 2) % 4) continue;
			if (visit[d][r][c]) continue;
			visit[d][r][c] = 1;
			q.push({ r,c,d,cnt + 1 });
		}
	}
	return 0;
}