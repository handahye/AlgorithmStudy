#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
#14889_스타트와 링크
[문제]
1. Sij + Sji는 i번과 j번 사람이 모였을 때, 팀에 더해지는 능력치
2. Sij와 Sji는 다를 수 있음
3. 두 팀 능력치 차이의 최솟값을 구해라

[접근방법]
1. 두개의 팀을 만들 수 있는 모든 경우를 만듦
2. 위에서 만든 것 중 능력차이가 가장 작은 경우를 구함
*/

int map[21][21];
int visit[21];
int N, minN=987654321;
int calScore(vector<int> &v) {//능력치 구하기
	int sum = 0;
	for (int i = 0; i < v.size(); i++) 
		for (int j = 0; j < v.size(); j++) 
			sum += map[v[i]][v[j]];
	return sum;
}
int res() {
	vector<int> start, link; 
	for (int i = 0; i < N; i++) {//start와 link 팀 나눔
		if (visit[i]) start.push_back(i);
		else link.push_back(i);
	}
	return abs(calScore(start) - calScore(link));	
}
void dfs(int idx, int cnt) {
	if(cnt == N / 2) {
		minN = min(minN,res());
		return;
	}
	for (int i = idx + 1; i < N; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			dfs(i, cnt + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> map[i][j];

	visit[0] = 1;
	dfs(0, 1);

	printf("%d", minN);
	return 0;
}