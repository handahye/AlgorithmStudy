#include <iostream>
#include <vector>
#include <string.h>
#include<algorithm>
using namespace std;
struct cell {
	int r, c;
	int before;
	bool active, spread;
};
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int map[601][601];
int visit[601][601] = { 0, };
int N, M, K;
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &N, &M, &K);
		vector<cell> v;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		for (int i = 300; i < 300 + N; i++) {
			for (int j = 300; j < 300 + M; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] > 0) {
					visit[i][j] = -1;
					v.push_back({ i,j, 0, false, false });
				}
			}
		}
		int time = 1;
		int ans = 0;
		while (K--) {
			vector<cell> alive;
			for (int i = 0; i < v.size(); i++) {
				int r = v[i].r, c = v[i].c;
				int k = map[r][c];
				int before = v[i].before;

				if (v[i].active && !v[i].spread) { //활성상태 + 퍼지기x
					if (time - before < k) {  //아직 죽은상태x
						alive.push_back({ r,c,before,true,true });
					}
					for (int d = 0; d < 4; d++) {
						int nr = r + dr[d], nc = c + dc[d];
						if (map[nr][nc] != 0 && visit[nr][nc] == time) {
							map[nr][nc] = max(map[nr][nc], k);
						}
						else if (map[nr][nc] == 0) {
							map[nr][nc] = k;
						}
						if (visit[nr][nc]==0) {
							visit[nr][nc] = time;
							alive.push_back({ nr, nc, time,false, false });
						}

					}
				}
				else if (v[i].active && v[i].spread) { //활성상태 + 퍼지기 완료
					if (time - before < k) {  //아직 죽은상태x
						alive.push_back({ r,c,before,true,true });
					}
				}
				else if (!v[i].active) {
					if (time - before == k) {
						//비활성 -> 활성
						alive.push_back({ r,c,time,true,false });
					}
					else {
						//비활성
						alive.push_back({ r,c,before,false,false });
					}
				}
			}
			v.clear();
			v = alive;
			ans = v.size();
			time++;
			
		}
		printf("#%d %d\n", t, ans);

	}
	return 0;
}