#include <iostream>
#include<queue>
using namespace std;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int N, W, H;
int map[16][13];
int res;
void mapCopy(int a[][13], int b[][13]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			a[i][j] = b[i][j];
		}
	}
}
void down() {
	queue<int> q;
	for (int i = 0; i < W; i++) {
		for (int j = H-1; j >=0; j--) {
			if (map[j][i] != 0) {
				q.push(map[j][i]);
				map[j][i] = 0;
			}
		}
		int k = H - 1;
		while (!q.empty()) {
			map[k][i] = q.front();
			q.pop();
			k--;
		}
	}
}
int cal() {
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] != 0) cnt++;
		}
	}
	return cnt;
}
void breakWall(int w) {
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < H; i++) {
		if (map[i][w] ==1) { //1이면 바로 0으로 만듦
			map[i][w] = 0;
			break;
		}
		else if (map[i][w] > 1) { //1보다 큰수면 queue에 담음
			q.push({ map[i][w],{ i,w } });
			map[i][w] = 0;
			break;
		}
	}
	while (!q.empty()) {
		int n = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		for (int cnt = 1; cnt < n; cnt++) {
			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d] * cnt, nc = c + dc[d] * cnt;
				if (nr >= 0 && nc >= 0 && nr < H && nc < W) {
					if(map[nr][nc]==1) map[nr][nc] = 0;
					else if (map[nr][nc] > 1) {
						q.push({ map[nr][nc],{ nr,nc }});
						map[nr][nc] = 0;
					}
				}
			}
		}
		
	}
	
}
void dfs(int cnt) {
	if (cnt == N) {
		res = min(res, cal());
		return;
	}
	int tmp[16][13];
	mapCopy(tmp, map);
	for (int i = 0; i < W; i++) {
		breakWall(i);
		down();
		dfs(cnt + 1);
		mapCopy(map, tmp);
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		res = 987654321;
		scanf("%d%d%d", &N, &W, &H);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		dfs(0);
		printf("#%d %d\n", t, res);
	}
	return 0;
}
