#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;
/*
D4_미로2
*/
int map[101][101];
int visit[101][101];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int er, ec, sr, sc;
int End = false;
void dfs(int r, int c) {
	if (End) return;
	if (r == sr && c == sc) { //출발 지점까지 도착할 수 있으면 End에 ture 체크
		End = true;
		return;
	}
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < 100 && nc < 100) {
			if (!visit[nr][nc] && map[nr][nc]!=1) { //방문하지 않았고, 벽이 아닌 경우
				visit[nr][nc] = 1;
				dfs(nr, nc);
			}
		}
	}
}
int main() {
	for (int t = 1; t <= 10; t++) {
		int T;
		cin >> T;
		memset(visit, 0, sizeof(visit));
		End = false;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) sr = i, sc = j;
				else if (map[i][j] == 3)er = i, ec = j;
			}
		}
		visit[er][ec] = 1;
		dfs(er, ec);//도착 지점에서 출발 지점까지 갈 수 있는지 
		if (End) printf("#%d 1\n",t);
		else printf("#%d 0\n",t);
	}

	return 0;
}