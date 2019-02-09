#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
using namespace std;
/*
D4_Ladder2
*/
int map[101][101];
int visit[101][101];
vector<pair<int,int>> ans; //거리, 좌표
int endR, endC;
bool cmp(pair<int, int> &a, pair<int, int>&b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}
void dfs(int r, int c, int cnt) {
	if (r == 0 && map[r][c] == 1) {//시작점에 도달한 경우 
		ans.push_back({ cnt, c });
		return;
	}
	bool chk = false;
	if (c - 1 >= 0 && map[r][c - 1] == 1 &&!visit[r][c-1]) { //왼쪽으로 가기
		visit[r][c - 1] = 1;
		dfs(r, c - 1, cnt + 1);
		visit[r][c - 1] = 0;
		chk = true;
	}
	
	if (c + 1 < 100 && map[r][c + 1] == 1 &&!visit[r][c+1]) { //오른쪽으로 가기
		visit[r][c + 1] = 1;
		dfs(r, c + 1, cnt + 1);
		visit[r][c + 1] = 0;
		chk = true;
	}
	
	if (!chk && map[r - 1][c] == 1) { //왼쪽 오른쪽으로 갈 수 없고, 위로 갈 수 있는 경우 
		visit[r - 1][c] = 1;
		dfs(r - 1, c, cnt + 1);
		visit[r - 1][c] = 0;
	}
	
}
int main(){
	for (int t = 1; t <= 10; t++) {
		int T;
		cin >> T;
		ans.clear();
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < 100; i++) { //도착점에서 시작
			if (map[99][i] == 1) {
				visit[99][i] = 1;
				dfs(99, i, 1);
				visit[99][i] = 0;
			}
		}
		sort(ans.begin(), ans.end());
		cout << "#" << t << " " << ans[0].second << endl;
	}
	return 0;
}