#include <iostream>
#include<string>
#include<queue>
#include<string.h>
using namespace std;
/*
BOJ_1194_달이 차오른다, 가자
1) 통로(.) 이동 가능
2) 벽(#) 이동 불가
3) 열쇠(a~f) 언제나 이동 가능
4) 문(A~F) 대응하는 열쇠가 있느 경우에만 이동 가능
5) 민식이 위치(0)
6) 출구(1) 여러개 있을 수 있음
구해야 하는 것: 미로를 탈출하는데 걸리는 최솟값
*/
struct que {
	int r, c, cnt, key;
};
int N, M;
char map[51][51];
bool visit[51][51][64];//a~f까지의 키를 모두 주운 경우 2^6 
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
void bfs(int r, int c) {
	queue<que> q;
	q.push({ r,c,0,0 });
	visit[r][c][0] = true;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int cnt = q.front().cnt;
		int key = q.front().key;
		q.pop();
		if (map[r][c] == '1') {
			cout << cnt << "\n";
			return;
		}
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < N&&nc < M && !visit[nr][nc][key]) {
				if (map[nr][nc] == '.' || map[nr][nc] == '1') {
					visit[nr][nc][key] = true;
					q.push({ nr,nc,cnt + 1, key });
				}
				else if (map[nr][nc] >= 'a' && map[nr][nc] <= 'f') {
					int k = key | (1 << (map[nr][nc] - 'a'));
					visit[nr][nc][k] = true;
					q.push({ nr,nc,cnt + 1, k });
				}
				else if (map[nr][nc] >= 'A' && map[nr][nc] <= 'F') {
					if (key & (1 << map[nr][nc] - 'A')) {
						visit[nr][nc][key] = true;
						q.push({ nr,nc,cnt + 1,key });
					}
				}
			}
		}
	}
	cout << -1 << "\n";
}
int main() {
	cin >> N >> M;
	int sr, sc;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') sr = i, sc = j;
		}
	}
	map[sr][sc] = '.';
	bfs(sr, sc);
	return 0;
}