#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
/*15683 °¨½Ã*/
using namespace std;
int map[9][9];
int visit[9][9];
int minN = 987654321;
int N, M;
vector<pair<int, int>>cctv;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };
void mapCopy(int a[][9], int b[][9]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			a[i][j] = b[i][j];
	
}
void go(int r, int c, int dir) {
	int nr = r + dr[dir];
	int nc = c + dc[dir];

	if (nr >= 0 && nc >= 0 && nr < N &&nc < M) {
		if (map[nr][nc] != 6) {
			if(map[nr][nc]==0) map[nr][nc] = 9;
			go(nr, nc, dir);
		}
	}
}
int cal() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) res++;
		}
	}
	return res;
}
void dfs(int idx) {
	if (idx == cctv.size()) {
		minN = min(minN, cal());
		return;
	}
	int r = cctv[idx].first;
	int c = cctv[idx].second;
	int num = map[r][c];
	int tmp[9][9];

	mapCopy(tmp, map);
	if (num == 1) {
		for (int d = 0; d < 4; d++) {
			go(r, c, d);
			dfs(idx + 1);
			mapCopy(map, tmp);
		}
	}
	else if (num == 2) {
		go(r, c, 0), go(r, c, 2);
		dfs(idx + 1);
		mapCopy(map, tmp);

		go(r, c, 1), go(r, c, 3);
		dfs(idx + 1);
		mapCopy(map, tmp);
	}
	else if (num == 3) {
		for (int d = 0; d < 4; d++) {
			go(r, c, d), go(r, c, (d + 1) % 4);
			dfs(idx + 1);
			mapCopy(map, tmp);
		}
	}
	else if (num == 4) {
		for (int d = 0; d < 4; d++) {
			go(r, c, d), go(r, c, (d + 1) % 4), go(r, c, (d + 2) % 4);
			dfs(idx + 1);
			mapCopy(map, tmp);
		}
	}
	else if (num == 5) {
		go(r, c, 0), go(r, c, 1), go(r, c, 2), go(r, c, 3);
		dfs(idx + 1);
		mapCopy(map, tmp);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] >= 1 && map[i][j] <= 5)
				cctv.push_back({ i,j });
		}
	}
	dfs(0);
	printf("%d", minN);
	return 0;
}
