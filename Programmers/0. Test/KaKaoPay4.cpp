#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>
using namespace std;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int main(){
	int map[301][301];
	int visit[301][301] = { 0, };
	int h;
	cin >> h;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	queue < pair<int, int>> q1, q2;
	q1.push({ 0,0 });
	visit[0][0] = 1;
	int res = 0;
	while (!q1.empty()) {
		int r = q1.front().first;
		int c = q1.front().second;
		q1.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
				if (abs(map[nr][nc] - map[r][c]) <= h) {
					if (visit[nr][nc] != 1) {
						q1.push({ nr,nc });
						visit[nr][nc] = 1;
					}
				}
				else if (abs(map[nr][nc] - map[r][c]) > h && visit[nr][nc]==0) {
					visit[nr][nc] = 2;
				}
			}
		}
		bool flag = false;
		if (q1.empty()) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (visit[i][j] == 2) {
						q1.push({ i,j });
						visit[i][j] = 1;
						res++;
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
		}
	}
	cout << res;
	return 0;
}