#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>
using namespace std;
/*
#3055_탈출
1. 매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동 가능
2. 물도 매분마다 비어있는 칸으로 확장
3. 물과 고슴도치는 돌을 통과할 수 없음
4. 고슴도치는 물로 차있는 구역으로 이동 못함
5. 물도 비버의 소굴로 이동할 수 없음
6. 고슴도치가 안전하게 비버의 굴로 이동하기 위해 필요한 최소 시간
7. 고슴도치는 물이 찰 예정인 칸으로 이동 불가 
8. 비버 소굴로 이동 못하면 KAKTUS 출력
*/
int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
int visit[101][101];
char map[101][101];
int res = 0;
int n, m;
bool escape = false;
int main() {
	cin >> n >> m;
	queue<pair<int, int>> heg;
	queue<pair<int, int>>water;
	int Dr, Dc;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				visit[i][j] = 1;
				heg.push({ i,j });
			}
			else if (map[i][j] == '*') water.push({ i,j });
		}
	}
	while (!heg.empty()) {
		int w = water.size();
		int h = heg.size();
		//물 퍼져나감
		for (int i = 0; i < w; i++) {
			int r = water.front().first;
			int c = water.front().second;
			water.pop();

			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (nr<0 || nc<0 || nr >= n || nc >= m) continue;
				if (map[nr][nc]=='*' || map[nr][nc] == 'D'|| map[nr][nc] == 'X') continue;
				map[nr][nc] = '*';
				water.push({ nr,nc });
			}
		}
		for (int i = 0; i < h; i++) {
			int r = heg.front().first;
			int c = heg.front().second;
			heg.pop();

			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (visit[nr][nc]||nr<0||nc<0 ||nr>=n ||nc>=m) continue;
				if (map[nr][nc] == '*'|| map[nr][nc] == 'X') continue;
				if (map[nr][nc] == 'D'|| map[nr][nc] == 'A') {
					escape = true;
					break;
				}
				visit[nr][nc] = 1;
				heg.push({ nr,nc });
			}
			if (escape) break;
		}
		res++;
		if (escape) break;
	}
	if(escape) cout << res<< endl;
	else cout << "KAKTUS" << endl;
	return 0;
}