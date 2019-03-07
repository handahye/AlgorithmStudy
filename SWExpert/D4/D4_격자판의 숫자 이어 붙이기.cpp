#include<iostream>
#include<string.h>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
int map[5][5];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
set<string> s;
void dfs(int r, int c, int cnt, string str) {
	if (cnt == 7) {
		s.insert(str);
		return;
	}
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d], nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < 4 && nc < 4) {
			dfs(nr, nc, cnt + 1, str + to_string(map[nr][nc]));
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		s.clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs(i, j, 1, to_string(map[i][j]));
			}
		}
		printf("#%d %d\n", t, s.size());
	}
	return 0;
}