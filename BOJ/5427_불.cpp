#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
int w, h;
char map[1010][1010];
int sr, sc;
int time;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
bool visit[1001][1001];
vector<pair<int, int>> fire;
bool bfs() {
	queue<pair<int, int>> q, s;
	for (int i = 0; i < fire.size(); i++) {
		int r = fire[i].first, c = fire[i].second;
		q.push({ r,c });
	}
	s.push({ sr,sc });
	visit[sr][sc] = true;
	while (1) {
		//불 퍼져나감
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d], nc = c + dc[d];
				if (nr >= 0 && nc >= 0 && nr < h && nc < w) {
					if (map[nr][nc] == '.') {
						map[nr][nc] = '*';
						q.push({ nr,nc });
					}
				}
			}

		}
		//상근이 위치 이동
		bool move = false;
		int sSize = s.size();
		for (int i = 0; i<sSize; i++) {
			int r = s.front().first;
			int c = s.front().second;
			s.pop();
			if (r == 0 || c == 0 || r == h - 1 || c == w - 1) return true;
			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d], nc = c + dc[d];
				if (nr >= 0 && nc >= 0 && nr < h && nc < w && !visit[nr][nc]) {
					if (map[nr][nc] == '.') {
						move = true;
						s.push({ nr,nc });
						visit[nr][nc] = true;
					}
				}
			}
		}
		if (!move) return false; //움직일 수 없으면 탈출 불가
		time++;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &w, &h);
		fire.clear();
		memset(visit, false, sizeof(visit));
		time = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == '@') {
					map[i][j] = '.';
					sr = i, sc = j;
				}
				else if (map[i][j] == '*') {
					fire.push_back({ i,j });
				}
			}
		}
		if (bfs()) printf("%d\n", time + 1);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}