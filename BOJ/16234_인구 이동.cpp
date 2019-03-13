#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
int map[51][51];
int visit[51][51];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int N, L, R;
bool End=false;
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;//연합
	q.push({ i,j });
	v.push_back({ i,j });
	int sum = map[i][j]; //연합의 총 인구수
	visit[i][j] = true;
	while (!q.empty()) {//연합 구하기 위한 bfs
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d], nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N &&!visit[nr][nc]) {
				if (abs(map[r][c] - map[nr][nc]) >= L && abs(map[r][c] - map[nr][nc]) <= R) {
					visit[nr][nc] = true; //L이상 R이하면 연합이니까 queue랑 vector에 추가
					q.push({ nr,nc });
					v.push_back({ nr,nc });
					sum += map[nr][nc];//인구수 더해줌
				}
			}
		}
	}

	if (v.size() > 1) {//vector 사이즈가 1보다 크면 연합이 만들어진거니까
		End = true;
		int num = sum / v.size(); //위에서 구한 sum을 연합수로 나눠줌
		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = num;//map 갱신
		}
	}
}
int main() {
	int res = 0;
	scanf("%d%d%d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		End = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) bfs(i, j);
			}
		}
		if (!End) break; //연합이 만들어지지 않았으면 빠져나옴
		res++;//연합이 만들어져 인구이동을 했으면 
		memset(visit, 0, sizeof(visit));
	}
	printf("%d", res);
	return 0;
}