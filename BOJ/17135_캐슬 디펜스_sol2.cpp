#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct st {
	int r, c, dist;
};
int N, M, D;
int res;
int map[16][16], tmp[16][16];
bool chk[16];
vector<int> arrow;
vector<pair<int, int>> enemy;
bool cmp(st &a, st &b) {
	if (a.dist == b.dist) {
		if (a.c < b.c) return true;
		else return false;
	}
	else if (a.dist < b.dist) return true;
	else return false;
}
void copyMap(int a[][16], int b[][16]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			a[i][j] = b[i][j];
}
int calDist(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}
void moveEnemy(vector<pair<int, int>> &e) {
	for (int i = N-1; i >=0; i--) {
		for (int j = 0; j < M; j++) {
			if (i == 0) tmp[i][j] = 0;
			else {
				tmp[i][j] = tmp[i-1][j];
				if (tmp[i][j] == 1) e.push_back({ i,j });
			}
		}
	}
}
int simulation() {
	vector<pair<int, int>> e;
	copyMap(tmp, map);
	e = enemy;
	int cnt = 0;
	while (1) {
		vector<pair<int, int>> f;
		bool visit[16][16] = { false, };
		for (int i = 0; i < 3; i++) {
			vector<st> v;
			for (int j = 0; j < e.size(); j++) {//현재 격자판에 있는 
				int r = e[j].first, c = e[j].second;
				int dist = calDist(N, arrow[i], r, c);
				if (dist <= D) v.push_back({ r,c,dist });	
			}
			sort(v.begin(), v.end(), cmp);
			if(v.size()>0) f.push_back({ v[0].r, v[0].c });
		}
		for (int i = 0; i < f.size(); i++) {
			int r = f[i].first, c = f[i].second;
			if (!visit[r][c]) {
				visit[r][c] = true;
				cnt++;
				tmp[r][c] = 0;
			}
		}
		//남아있는 적들 옮기기
		e.clear();
		moveEnemy(e);
		if (e.size() == 0) return cnt;
	}
}
void selectArrow(int idx, int cnt) {
	if (cnt == 3) {
		res = max(res, simulation());
		return;
	}
	for (int i = idx + 1; i < M; i++) {
		if (!chk[i]) {
			chk[i] = true;
			arrow.push_back(i);
			selectArrow(i, cnt + 1);
			chk[i] = false;
			arrow.pop_back();
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d%d%d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) enemy.push_back({ i,j });
		}
	}
	selectArrow(-1,0);
	printf("%d", res);
	return 0;
}