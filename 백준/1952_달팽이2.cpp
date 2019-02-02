#include <iostream>
#include <algorithm>
#include<vector>
#include <string>
using namespace std;
/*
#1952_달팽이2
1. 표의 밖 또는 이미 그려진 칸에 닿으면 더이상 이동할 수 없고,
시계 방향으로 선을 꺾어서 그려나감
2. 표가 모두 채워질 때까지, 선을 몇 번 꺾을까?
*/
int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
int visit[101][101];
int res = 0;
int m, n;
bool End = false;
void dfs(int total, int cnt, int r, int c, int dir) {
	if (End) return;
	if (total - cnt == m * n) {
		End = true;
		return;
	}
	res = cnt;
	int nr = r + dr[dir];
	int nc = c + dc[dir];
	if (nr < 0 || nc < 0 || nr >= m || nc >= n || visit[nr][nc]) {
		dir = (dir + 1) % 4;
		dfs(total+1, cnt + 1, r, c, dir);
	}
	visit[nr][nc] = 1;
	dfs(total+1, cnt, nr, nc, dir);
	
}
int main() {
	cin >> m >> n;
	visit[0][0] = 1;
	dfs(1, 0, 0, 0, 0);
	cout << res << endl;
	return 0;
}