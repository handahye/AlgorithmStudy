#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int N;
int map[13][13];
vector<pair<int, int> > core, ans;
int res, maxN;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first > b.first;
}
void mapCopy(int a[][13], int b[][13]) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			a[i][j] = b[i][j];
}
int change(int r, int c, int dir) {
	int len = 0;
	if (dir == 0) {
		c += 1;
		while (c <= N) {
			if (map[r][c] != 0) {
				return -1;
			}
			map[r][c] = 2;
			len++;
			c++;
		}
	}
	else if (dir == 1) {
		c -= 1;
		while (c >= 1) {
			if (map[r][c] != 0) {
				return -1;
			}
			map[r][c] = 2;
			len++;
			c--;
		}
	}
	else if (dir == 2) {
		r += 1;
		while (r <= N) {
			if (map[r][c] != 0) {
				return -1;
			}
			map[r][c] = 2;
			len++;
			r++;
		}
	}
	else if (dir == 3) {
		r -= 1;
		while (r >= 1) {
			if (map[r][c] != 0) {
				return -1;
			}
			map[r][c] = 2;
			len++;
			r--;
		}
	}
	return len;
}
void dfs(int idx, int cnt, int num) {
	if (idx == core.size()) {
		ans.push_back({ num, cnt });
		return;
	}
	int r = core[idx].first, c = core[idx].second;
	int tmp[13][13];
	mapCopy(tmp, map);
	bool chk = false;
	for (int d = 0; d < 4; d++) {
		int len = change(r, c, d);
		if (len<0) {
			mapCopy(map, tmp);
			continue;
		}
		else {
			dfs(idx + 1, cnt + len, num + 1);
			chk = true;
		}
		mapCopy(map, tmp);
	}
	if (!chk) dfs(idx + 1, cnt, num);
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		res = 987654321;
		maxN = -1;
		core.clear();
		ans.clear();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &map[i][j]);
				if (i == 1 || i == N || j == 1 || j == N) continue;
				if (map[i][j]) core.push_back({ i,j });

			}
		}
		dfs(0, 0, 0);
		sort(ans.begin(), ans.end(), cmp);
		printf("#%d %d\n", t, ans[0].second);
	}
	return 0;
}