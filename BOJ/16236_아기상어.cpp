#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>
#include<string.h>
using namespace std;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int sr, sc, N;
int map[21][21];
bool visit[21][21];
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		if (a.second < b.second) return true;
		else return false;
	}
	else if (a.first < b.first) return true;
	else return false;

}
int main() {
	int time = 0, fSize = 2, fcnt=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) sr = i, sc = j;
		}
	}
	map[sr][sc] = 0;
	while (1) {
		queue<pair<int, pair<int, int>>> q;
		vector<pair<int, int>> possible;
		q.push({ 0,{sr,sc } });
		bool chk = false;
		int minDist = 987654321;
		memset(visit, false, sizeof(visit));

		while (!q.empty()) {
			int r = q.front().second.first;
			int c = q.front().second.second;
			int cnt = q.front().first;
			q.pop();
	
			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d], nc = c + dc[d];
				if (nr >= 0 && nc >= 0 && nr < N && nc < N &&!visit[nr][nc]) {
					if (map[nr][nc] < fSize && map[nr][nc]!=0 && cnt+1<=minDist) {
						possible.push_back({ nr,nc });
						minDist = min(minDist, cnt+1);
						visit[nr][nc] = true;
					}
					else if (map[nr][nc] == fSize || map[nr][nc] == 0) {
						visit[nr][nc] = true;
						q.push({ cnt + 1 ,{nr, nc} });
					}
				}
			}
		}
		if (possible.size() == 0) break;
		if(possible.size()>1) sort(possible.begin(), possible.end(),cmp);

		time += minDist;
		sr = possible[0].first, sc = possible[0].second;
		map[sr][sc] = 0;
		fcnt++;

		if (fcnt == fSize) {
			fSize++;
			fcnt = 0;
		}
	}
	printf("%d", time);
	return 0;
}