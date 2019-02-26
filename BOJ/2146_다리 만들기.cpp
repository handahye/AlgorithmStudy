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
int bfs(int num) {//num의 번호를 가진 섬에서 가장 가까운 다른 섬 찾기
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
					if (map[nr][nc] != 0 && map[nr][nc] != num) return res; //다른 섬이면
					if (map[nr][nc] == 0 && !visit[nr][nc]) { //아직 방문하지 않은 강물이면
						visit[nr][nc] = 1;
						q.push({ nr,nc });
					}
				}
			}
		}
		res++;//거리증가
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	int num = 1;
	for (int i = 0; i < n; i++) {//섬 나누기 (각 섬에 번호 부여해줌)
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
