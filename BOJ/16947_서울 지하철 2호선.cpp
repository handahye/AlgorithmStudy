#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
using namespace std;
/*
1. 1~N까지 돌면서 순환선 찾기
2. 순환선으로 체크된 애들 돌면서 거기에 연결된 애들의 거리 구하기
*/
struct st{
	int idx, cnt;
};
bool visit[3002], End;
int N, sIdx;
vector<int> v[3002], circle;
vector<st> res;
bool cmp(st &a, st &b) {
	return a.idx < b.idx;
}
void dfs(int idx, int cnt) {
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i];
		if (!visit[next]) {
			visit[next] = true;
			circle.push_back(next);
			dfs(next, cnt+1);
			if (End) return;
			visit[next] = false;
			circle.pop_back();
		}
		else if (next == sIdx && cnt>1) {
			End = true;
			return;
		}
	}
}
void cal(int idx, int cnt) {
	for (int i = 0; i < v[idx].size(); i++) {
		int num = v[idx][i];
		if (!visit[num]) {
			visit[num] = true;
			res.push_back({ num, cnt + 1 });
			if (v[num].size() > 0) cal(num, cnt + 1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		visit[i] = true;
		circle.push_back(i);
		sIdx = i;
		dfs(i, 0);
		if (End) break;
		visit[i] = false;
		circle.pop_back();
	}
	for (int i = 0; i < circle.size(); i++) {
		int num = circle[i];
		res.push_back({ num, 0 });
		if(v[num].size()>0) cal(num, 0);
	}
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < res.size(); i++) {
		printf("%d ", res[i].cnt);
	}
	return 0;
}