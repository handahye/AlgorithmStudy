#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
/*BOJ_2146_다리 만들기*/
using namespace std;
int n;
int map[101][101];
int visit[101][101];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
void dfs(int r, int c, int num) {
	visit[r][c] = 1;
	map[r][c] = num;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nc >= 0 && nr < n &&nc < n) {
			if (map[nr][nc] && !visit[nr][nc])
				dfs(nr, nc, num);
		}
	}
}
int bfs(int num) {
	queue<pair<int, int>> q;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n;j++)
			if (map[i][j] == num) {
				visit[i][j] = 1;
				q.push({ i,j });
			}
	}
	int res = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i<s; i++) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
					if (map[nr][nc] != 0 && map[nr][nc] != num) return res;
					if (map[nr][nc] == 0 && !visit[nr][nc]) {
						visit[nr][nc] = 1;
						q.push({ nr,nc });
					}
				}
			}
		}
		res++;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (map[i][j] && !visit[i][j]) 
				dfs(i, j, num++);
	}
	int minN = 987654321;
	for (int i = 1; i <= num; i++)
		minN = min(minN, bfs(i));
	cout << minN;
	return 0;
}
