#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct st {
	int r, c, dist;
};
int N, M, D, res;
int map[16][16], tmp[16][16];
bool chk[16];
vector<int> pos;
vector<pair<int, int>> v;
int calDist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}
bool cmp(st &a, st &b) {
	if (a.dist < b.dist) return true;
	else if (a.dist == b.dist) {
		if (a.c < b.c) return true;
		else return false;
	}
	else return false;
}
void mapCopy(int a[][16], int b[][16]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			a[i][j] = b[i][j];
}
void pushEnemy() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (tmp[i][j]) v.push_back({ i,j });
}
int kill(){
	int cnt = 0;
	for (int i = 0; i < pos.size(); i++) {
		int r = N;
		int c = pos[i];
		vector<st> possible;

		for (int j = 0; j < v.size(); j++) {
			int er = v[j].first, ec = v[j].second;
			int dist = calDist(r, c, er, ec);
			if (dist <= D) possible.push_back({ er,ec,dist });	
		}
		if (possible.size() > 1) {
			sort(possible.begin(), possible.end(), cmp);
			int pr = possible[0].r, pc = possible[0].c;
			if (tmp[pr][pc]) {
				tmp[pr][pc] = 0;
				cnt++;
			}
		}
		else if (possible.size() == 1) {
			int pr = possible[0].r, pc = possible[0].c;
			if (tmp[pr][pc]) {
				tmp[pr][pc] = 0;
				cnt++;
			}
		}
	}
	return cnt;
}
void move() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (i == N - 1) tmp[i][j] = 0;
			else {
				if (tmp[i][j]) {
					tmp[i][j] = 0;
					tmp[i + 1][j] = 1;
				}
			}
		}
	}
}
bool chkKill() {
	bool End = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j]) End = true;
		}
	}
	return End;
}
int cal(){
	int cnt = 0;
	mapCopy(tmp, map);
	while (1) {
		v.clear();
		if (!chkKill()) break;
		pushEnemy();
		cnt += kill();
		move();
	}
	return cnt;
}
void dfs(int idx, int cnt) {
	if (cnt == 3) {
		res = max(res, cal());
		return;
	}
	for (int i = idx+1; i < M; i++) {
		if (!chk[i]) {
			chk[i] = true;
			pos.push_back(i);
			dfs(i, cnt + 1);
			pos.pop_back();
			chk[i] = false;
		}
	}
}
int main() {
	scanf("%d%d%d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(-1, 0);
	printf("%d", res);
	return 0;
}