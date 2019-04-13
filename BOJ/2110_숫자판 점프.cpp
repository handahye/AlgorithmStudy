 #include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
using namespace std;
int map[6][6];
set<int> s;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
void dfs(int r, int c, int len, string num) {
	if (len == 6) {
		int n = atoi(num.c_str());
		s.insert(n);
		return;
	}
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d], nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < 5 && nc < 5) {
			dfs(nr, nc, len + 1, num + to_string(map[nr][nc]));
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &map[i][j]);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 1, to_string(map[i][j]));
		}
	}
	printf("%d", s.size());
	return 0;
}