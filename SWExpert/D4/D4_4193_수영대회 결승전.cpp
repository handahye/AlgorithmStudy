#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int map[16][16], dist[16][16];
int sR, sC, eR, eC;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = 987654321;
			}
		}
		cin >> sR >> sC >> eR >> eC;
		priority_queue<pair<int, pair<int,int>>> que;
		que.push({ 0,{sR,sC} });
		dist[sR][sC] = 0;
		while (!que.empty()) {
			int time = -que.top().first;
			int r = que.top().second.first;
			int c = que.top().second.second;
			que.pop();

			if (time > dist[r][c]) continue;

			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (nr >= 0 && nc >= 0 && nr < N&&nc < N &&map[nr][nc]!=1) {
					if (map[nr][nc] == 0 && dist[nr][nc] > time + 1) {
						dist[nr][nc] = time + 1;
						que.push({ -dist[nr][nc],{ nr,nc } });
					}
					else if (map[nr][nc] == 2) {
						if (time % 3 == 0 && dist[nr][nc] > time + 3) {
							dist[nr][nc] = time + 3;
							que.push({ -dist[nr][nc],{ nr,nc } });
						}
						else if (time % 3 == 1 && dist[nr][nc] > time + 2) {
							dist[nr][nc] = time + 2;
							que.push({ -dist[nr][nc],{ nr,nc } });
						}
						else if (time % 3 == 2 && dist[nr][nc] > time + 1) {
							dist[nr][nc] = time + 1;
							que.push({ -dist[nr][nc],{ nr,nc } });
						}
					}
					
				}
			}


		}
		if (dist[eR][eC] == 987654321) printf("#%d %d\n", t, -1);
		else printf("#%d %d\n", t, dist[eR][eC]);
	}
	return 0;
}