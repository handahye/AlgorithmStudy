#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
using namespace std;
/*
1. 오작교 놓을 수 없는 위치 chk
2. 오작교를 놓을 수 있는 위치에 모두 하나씩 놔봄
3. 갈 수 있는 경로 중 최소 시간 저장
*/
struct que {
	int r, c, time;
	bool before;
};
int N, M; //N: 크기, M: 오작교 주기
int map[11][11];
vector<pair<int, int>> cliff;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int res;
void canMakeBridge(int r, int c) {
	int a = 0, b = 0;
	for (int d = 0; d<4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];

		if (nr < 0 || nr>= N || nc < 0 || nc >= N) continue;
		if (map[nr][nc] == 0 && (d == 0 || d == 1)) a++;
		if (map[nr][nc] == 0 && (d == 2 || d == 3)) b++;
	}
	if (a >= 1 && b >= 1) map[r][c] = -1;
}
void bfs() {
	queue <que> q;
	q.push({ 0,0,0,false });
	bool chk[11][11] = { false, };
	chk[0][0] = true;
	while (!q.empty()) {
		int time = q.front().time;
		int r = q.front().r;
		int c = q.front().c;
		bool before = q.front().before;
		q.pop();
		if (r == N - 1 && c == N - 1) {
			res = min(res, time);
			continue;
		}
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d], nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N && !chk[nr][nc]) {
				if (map[nr][nc] == 1) {
					chk[nr][nc] = true;
					q.push({ nr,nc,time+1,false });
				}
				else if (map[nr][nc] > 1) {
					if ((time + 1) % map[nr][nc] == 0) {
						if (!before) {
							chk[nr][nc] = true;
							q.push({ nr,nc,time + 1,true });
						}
					}
					else q.push({ r,c,time + 1,false });
					
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	scanf("%d%d", &N, &M);
	res = 987654321;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) cliff.push_back({ i,j });
		}
	}
	//오작교를 놓을 수 없는 위치 -1로 set
	for (int i = 0; i < cliff.size(); i++) {
		int r = cliff[i].first, c = cliff[i].second;
		canMakeBridge(r, c);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) {
				map[i][j] = M;
				bfs();
				map[i][j] = 0;
			}
		}
	}
	printf("%d", res);
	return 0;
}