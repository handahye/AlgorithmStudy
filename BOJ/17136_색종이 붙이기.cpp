#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int map[11][11];
bool visit[11][11] = { false, };
vector<pair<int, int>>v;
int res = 987654321;
bool chk(int x, int y, int k) {
	int cnt = 0;
	for (int i = x; i < x + k; i++) {
		if (i >= 10) return false;
		for (int j = y; j < y + k; j++) {
			if (y >= 10)return false;
			if (map[i][j] == 0  || visit[i][j]) return false;
		}
	}
	return true;
}
int find(int x, int y) {
	if (chk(x, y, 5)) return 5;
	if (chk(x, y, 4)) return 4;
	if (chk(x, y, 3)) return 3;
	if (chk(x, y, 2)) return 2;
	return 1;
}
void visitChk(int x, int y, int k, bool flag) {
	for (int i = x; i < x + k; i++)
		for (int j = y; j < y + k; j++)
			visit[i][j] = flag;
}
void dfs(int idx, int a, int b, int c, int d, int e, int sum) {
	int used = a + b + c + d + e;
	if (res < used) return;
	if (sum == v.size()) {
		res = min(res, used);
		return;
	}
	int x = v[idx].first, y = v[idx].second;

	if (visit[x][y]) {
		dfs(idx + 1, a, b, c, d, e, sum);
		return;
	}
	int num = find(x, y);
	if (num == 1) {
		if (a + 1 <= 5) {
			visitChk(x, y, 1, true);
			dfs(idx + 1, a + 1, b, c, d, e, sum + 1);
			visitChk(x, y, 1, false);
		}

	}
	else if (num == 2) {
		if (b + 1 <= 5) {
			visitChk(x, y, 2, true);
			dfs(idx + 1, a , b+1, c, d, e, sum + 4);
			visitChk(x, y, 2, false);
		}
		if (a + 1 <= 5) {
			visitChk(x, y, 1, true);
			dfs(idx + 1, a+1, b, c, d, e, sum + 1);
			visitChk(x, y, 1, false);
		}
	}
	else if (num == 3) {
		if (c + 1 <= 5) {
			visitChk(x, y, 3, true);
			dfs(idx + 1, a, b, c+1, d, e, sum + 9);
			visitChk(x, y, 3, false);
		}
		if (b + 1 <= 5) {
			visitChk(x, y, 2, true);
			dfs(idx + 1, a, b + 1, c, d, e, sum + 4);
			visitChk(x, y, 2, false);
		}
		if (a + 1 <= 5) {
			visitChk(x, y, 1, true);
			dfs(idx + 1, a + 1, b, c, d, e, sum + 1);
			visitChk(x, y, 1, false);
		}
	}
	else if (num == 4) {
		if (d + 1 <= 5) {
			visitChk(x, y, 4, true);
			dfs(idx + 1, a, b, c, d+1, e, sum + 16);
			visitChk(x, y, 4, false);
		}
		if (c + 1 <= 5) {
			visitChk(x, y, 3, true);
			dfs(idx + 1, a, b, c + 1, d, e, sum + 9);
			visitChk(x, y, 3, false);
		}
		if (b + 1 <= 5) {
			visitChk(x, y, 2, true);
			dfs(idx + 1, a, b + 1, c, d, e, sum + 4);
			visitChk(x, y, 2, false);
		}
		if (a + 1 <= 5) {
			visitChk(x, y, 1, true);
			dfs(idx + 1, a + 1, b, c, d, e, sum + 1);
			visitChk(x, y, 1, false);
		}
	}
	else if(num==5){
		if (e + 1 <= 5) {
			visitChk(x, y, 5, true);
			dfs(idx + 1, a, b, c, d, e+1, sum + 25);
			visitChk(x, y, 5, false);
		}
		if (d + 1 <= 5) {
			visitChk(x, y, 4, true);
			dfs(idx + 1, a, b, c, d + 1, e, sum + 16);
			visitChk(x, y, 4, false);
		}
		if (c + 1 <= 5) {
			visitChk(x, y, 3, true);
			dfs(idx + 1, a, b, c + 1, d, e, sum + 9);
			visitChk(x, y, 3, false);
		}
		if (b + 1 <= 5) {
			visitChk(x, y, 2, true);
			dfs(idx + 1, a, b + 1, c, d, e, sum + 4);
			visitChk(x, y, 2, false);
		}
		if (a + 1 <= 5) {
			visitChk(x, y, 1, true);
			dfs(idx + 1, a + 1, b, c, d, e, sum + 1);
			visitChk(x, y, 1, false);
		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) v.push_back({ i,j });
		}
	}
	if (v.size() == 0) printf("0");
	else {
		dfs(0, 0, 0, 0, 0, 0, 0);
		if (res == 987654321) printf("-1");
		else printf("%d", res);
	}
	return 0;
}