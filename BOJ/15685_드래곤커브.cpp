#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
#15685_드래곤 커브
[문제]
1. 드래곤 커브는 1) 시작 점, 2) 시작 방향, 3) 세대로 이루어짐
2. 2-1) 0세대 드래곤 커브는 길이가 1인 선분
	2-2) 1세대 드래곤 커브는 0세대의 끝점을 기준으로 시계방향으로 90도 회전시킨 뒤,
	0세대 드래곤 커브의 끝 점에 붙인 것
	2-3) 위 방법을 이용해서 세대가 이어짐
3. 즉 K세대 드래곤 커브는 K-1세대 드래곤 커브를 끝 점 기준으로 90도 시계 방향 시킨 다음, 
그것을 끝 점에 붙인 것.

[주의할 점]
1. x, y 반대 
*/
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int visit[102][102] = { 0, };
int nx, ny;
int dirChange(int dir) {
	if (dir == 0) return 1;
	else if (dir == 1) return 2;
	else if (dir == 2) return 3;
	else if (dir == 3) return 0;
}
void dragonCurve(vector<int> &v) {
	for (int i = v.size() - 1; i >= 0; i--) { //vector의 마지막부터 접근해야함
		int d = dirChange(v[i]);
		nx = nx + dx[d];
		ny = ny + dy[d];
		visit[nx][ny] = 1;
		v.push_back(d);
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> y >> x >> d >> g; 
		vector<int> dragon;
		visit[x][y] = 1;
		nx = x + dx[d], ny = y + dy[d];
		visit[nx][ny] = 1;
		dragon.push_back(d);

		for (int i = 0; i < g; i++) //세대 만큼 움직임
			dragonCurve(dragon);
	}
	int res = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (visit[i][j] && visit[i][j + 1] && visit[i + 1][j] && visit[i+1][j + 1])
				res++;
		}
	}
	printf("%d", res);
	return 0;
}