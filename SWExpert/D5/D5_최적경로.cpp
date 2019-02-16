#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
/*
D5_최적경로
:TSP문제
*/
int map[15][15];
int visit[15];
int N;
int sr, sc, er, ec;
int minN = 987654321;
vector<pair<int, int>> v;
void dfs(int cur, int cnt, int sum) {
	if (cnt == v.size()) {//고객들을 모두 방문한 경우
		int tmp = abs(v[cur].first - er) + abs(v[cur].second - ec); //마지막 고객 위치에서 집까지의 거리 계산
		minN = min(minN, sum+tmp);//위에서 구한 값과 현재까지의 이동거리를 더해서 최솟값을 minN에 저장해둠 
		return;
	}
	for (int next = 0; next < v.size(); next++) {
		if (!visit[next] && next!=cur) { //아직 방문하지 않은 손님인 경우
			if (sum + map[cur][next] < minN) { //현재까지 이동해온 거리 + 현재 이동해야 하는 거리가 내가 저장해뒀던 minN값보다 작은 경우에만
				visit[next] = 1;//방문체크
				dfs(next, cnt + 1, sum + map[cur][next]);
				visit[next] = 0;
			}
		}
	}
}
void init() {
	//i와 j의 거리 미리 계산해서 저장
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i == j) map[i][j] = 0;
			else map[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
		}
	}
	for (int i = 0; i < 15;i++) visit[i] = 0;
	minN = 987654321;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cin >> sr >> sc;
		cin >> er >> ec;
		v.clear();
		v.push_back({ sr,sc }); //회사와 손님들의 좌표를 모두 vector에 담음
		for (int i = 0; i < N; i++) {
			int r, c;
			cin >> r >> c;
			v.push_back({ r,c });
		}
		init();

		visit[0] = 1;
		dfs(0, 1, 0);
		printf("#%d %d\n", t, minN);
	}

	return 0;
}