#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
int map[101][101];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int N, K, L,  time = 0, res = 0;
bool chkWall(int nr, int nc) {
	if (nr == 0 || nc == 0 || nr == N + 1 || nc == N + 1) return true;
	else return false;
}
int changeDir(int dir, char d) {
	if (dir == 0) {
		if (d == 'L') return 3;
		else return 2;
	}
	else if (dir == 1) {
		if (d == 'L') return 2;
		else return 3;
	}
	else if (dir == 2) {
		if (d == 'L') return 0;
		else return 1;
	}
	else if (dir == 3) {
		if (d == 'L') return 1;
		else return 0;
	}
}
int main() {
	list<pair<int, int>> snake;
	vector<pair<int, char>> v;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		map[a][b] = 6; //»ç°ú
	}
	int L;
	scanf("%d", &L);
	bool End = false;
	for (int i = 0; i < L; i++) {
		int t;
		char d;
		cin >> t >> d;
		v.push_back({ t,d });
	}

	int idx = 0;
	int r = 1, c = 1, dir = 0;
	map[r][c] = 1;
	snake.push_front({ r,c });

	while (1) {
		time++;
		int nr = r + dr[dir], nc = c + dc[dir];
		if (chkWall(nr, nc) || map[nr][nc] == 1) {
			End = true;
			res = time;
			break;
		}
		else if (map[nr][nc] == 6) {
			map[nr][nc] = 1;
			snake.push_front({ nr,nc });
		}
		else if (map[nr][nc] == 0) {
			int rr = snake.back().first, cc = snake.back().second;
			map[rr][cc] = 0;
			snake.pop_back();
			map[nr][nc] = 1;
			snake.push_front({ nr,nc });
		}
		r = nr, c = nc;
		if (End) break;
		if (time == v[idx].first && idx<v.size()) {
			dir = changeDir(dir, v[idx].second);
			idx++;
		}
	}
	printf("%d\n", res);
	return 0;
}