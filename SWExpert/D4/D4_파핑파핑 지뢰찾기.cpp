#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;
/*
D4_파핑파핑 지뢰찾기 
*/
int res;
int dr[] = { 0, 0, 1,-1, 1,1,-1,-1 };
int dc[] = { -1, 1,0,0,-1,1,-1,1 };
int visit[305][305];
int map[305][305];
int N;
void chainProcessing(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r,c });
	visit[r][c] = 1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int d = 0; d < 8; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < N&&nc < N &&!visit[nr][nc]) {
				visit[nr][nc] = 1;
				if (map[nr][nc] == 0) 
					q.push({ nr,nc });
 			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
		cin >> N;
		res = 0;
		for (int i = 0; i < N;i++) {
			for (int j = 0; j < N; j++) {
				char c;
				cin >> c;
				if (c == '*') map[i][j] = -1; //지뢰	
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == -1) {
					for (int d = 0; d < 8; d++) {
						int nr = i + dr[d];
						int nc = j + dc[d];
						if (nr >= 0 && nc >= 0 && nr < N && nc < N && map[nr][nc] != -1) {
							map[nr][nc] += 1;
						}
					}
				}
			}	
		}
		//연쇄처리 부분
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0 && !visit[i][j]) {
					chainProcessing(i, j);
					res++;
				}
			}
		}
		//직접 클릭해야 하는 부분
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && map[i][j] != -1) {
					res++;
				}
			}
		}
		cout << "#" << t << " " << res << endl;
	}

	return 0;
}