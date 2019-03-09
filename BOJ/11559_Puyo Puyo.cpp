#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
#include<string>
using namespace std;
char map[13][7];
bool visit[13][7];
int res = 0;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
bool End = false;
void mapCopy(char a[][7], char b[][7]) {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			a[i][j] = b[i][j];
}
void down() {
	vector<char> v;
	for (int i = 0; i < 6; i++) {
		for (int j = 11; j >=0; j--) {
			if (map[j][i] != '.') {
				v.push_back(map[j][i]);
				map[j][i] = '.';
			}
		}
		for (int k = 0, j = 11; k < v.size(); k++, j--) {
			map[j][i] = v[k];
		}
		v.clear();
	}
}
void bfs(int a, int b) {
	char tmp[13][7];
	mapCopy(tmp, map);
	char puyo = map[a][b];
	int cnt = 1;
	queue<pair<int, int>> que;
	visit[a][b] = true;
	map[a][b] = '.';
	que.push({ a,b });
	while (!que.empty()) {
		int r = que.front().first;
		int c = que.front().second;
		que.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d], nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < 12 && nc < 6) {
				if (!visit[nr][nc] && map[nr][nc] == puyo) {
					cnt++;
					visit[nr][nc] = true;
					map[nr][nc] = '.';
					que.push({ nr,nc });
				}
			}
		}
	}
	if(cnt<4) mapCopy(map,tmp);
	else End = true;
}
int main() {
	for (int i = 0; i < 12; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 6; j++)
			map[i][j] = str[j];
	}
	while (1) {
		for (int j = 11; j >= 0; j--) {
			for (int i = 0; i < 6; i++) {
				if (map[j][i] != '.' && !visit[j][i])
					bfs(j, i);
			}
		}
		if (!End) break;
		down();
		memset(visit, false, sizeof(visit));
		res++;
		End = false;
	}
	printf("%d", res);
	return 0;
}