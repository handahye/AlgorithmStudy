 #include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
char map[9][9];
int dr[] = { -1,-1,-1,0,0,0,1,1,1 };
int dc[] = { -1,0,1,-1,0,1,-1,0,1 };
int sr, sc, er, ec;
void moveWall() {
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			if (i == 0) map[i][j] = '.';
			else {
				map[i][j] = map[i-1][j];
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	sr = 7, sc = 0, er = 0, ec = 7;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	queue<pair<int, int>> q;
	q.push({ sr, sc });
	int res = 0;
	while (1) {
		int qSize = q.size();
		bool move = false;
		for (int i = 0; i < qSize; i++) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			if (map[r][c] == '#') continue;

			for (int d = 0; d < 9; d++) {
				int nr = r + dr[d], nc = c + dc[d];
				if (nr >= 0 && nc >= 0 && nr < 8 && nc < 8) {
					if (nr == er && nc == ec) {
						printf("1");
						return 0;
					}
					else if (map[nr][nc] == '.') {
						q.push({ nr,nc });
						move = true;
					}
				}
			}
		}
		if (!move) {
			printf("0");
			return 0;
		}
		moveWall();
	}
	return 0;
}