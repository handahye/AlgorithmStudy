#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int T, N;
int visit[21];
long long minN;
vector<pair<int, int>> v;
void cal() {
	long long res1 = 0, res2 = 0;
	vector<pair<int, int>> a, b;
	for (int i = 0; i < N; i++) {
		int x = v[i].first;
		int y = v[i].second;
		if (visit[i]) a.push_back({ x,y });
		else b.push_back({ x,y });
	}
	for (int i = 0; i < N / 2; i++) {
		res1 += (a[i].first - b[i].first);
		res2 += (a[i].second - b[i].second);
	}
	minN = min(minN, (res1*res1) + (res2*res2));
}
void dfs(int idx, int cnt) {
	if (cnt == N / 2) {
		cal();
		return;
	}
	for (int i = idx + 1; i < N; i++){
		if (!visit[i]) {
			visit[i] = 1;
			dfs(i, cnt + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		memset(visit, 0, sizeof(visit));
		v.clear();
		minN = 999999999999;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		visit[0] = 1;
		dfs(0, 1);
		printf("#%d %lld\n", t, minN);
	}
}