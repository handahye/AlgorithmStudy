 #include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
bool End;
int R, C;
char map[1501][1501];
bool visit[1501][1501];
int dc[] = { 1,-1,0,0 };
int dr[] = { 0,0,1,-1 };
queue<pair<int, int>> ns, s, nw, w;
int lr, lc;
void sBfs() {
	while (!s.empty() && !End) {
		int r = s.front().first;
		int c = s.front().second;
		s.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < R && nc < C &&!visit[nr][nc]) {
				if (map[nr][nc] == '.') {
					visit[nr][nc] = true;
					s.push({ nr,nc });
				}
				else if (map[nr][nc] == 'L') {
					visit[nr][nc] = true;
					End = true;
					break;
				}
				else if (map[nr][nc] == 'X') {
					visit[nr][nc] = true;
					ns.push({ nr,nc });
				}
			}
		}
	}
}
void wBfs() {
	while (!w.empty()) {
		int r = w.front().first;
		int c = w.front().second;
		w.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr >= 0 && nc >= 0 & nr < R && nc < C) {
				if (map[nr][nc] == 'X') {
					map[nr][nc] = '.';
					nw.push({ nr,nc });
				}
			}
		}
	}
}
int go() {
	int day = 0;
	s.push({ lr,lc });
	visit[lr][lc] = true;
	while (!End) {
		sBfs();
		if (!End) {
			wBfs();
			s = ns;
			w = nw;
			while (!ns.empty()) ns.pop();
			while (!nw.empty()) nw.pop();
			day++;
		}
	}
	return day;
}
int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d%d", &R, &C);
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'L') lr = i, lc = j;
			else if (map[i][j] != 'X') w.push({ i,j });
		}
	}
	printf("%d", go());
	return 0;
}